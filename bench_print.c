#include "push.h"
//U+221A 

void	ft_show_nbr(int *i, char *digit_buffer, int fd)
{
	while (digit_buffer[*i] != '\0')
	       	write(fd, &digit_buffer[(*i)--], 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int		i;
	char	digit_buffer[12];

	digit_buffer[0] = '\0';
	i = 1;
	while (nb > 9)
	{
		digit_buffer[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	digit_buffer[i] = nb + '0';
	ft_show_nbr(&i, digit_buffer, fd);
}

void ft_low_per(int count)
{
	char dig[4];

	dig[3] = '\0';
	dig[2] = '%';
	dig[1] = (count % 10) + '0';
	count = count / 10;
	dig[0] = count + '0';
	write(2, "0.", 2);
	write(2, &dig, 3);
}

void ft_lowest_per(int count)
{
	char dig[3];

	dig[0] = count + '0';
	dig[1] = '%';
	dig[2] = '\0';
	write(2, "0.0", 3);
	write(2, &dig, 3);
}

void	ft_low_print(int count)
{
	if(count == 0)
	{
		write(2, "0%", 2);
		return ;
	}
	if(count < 10)
	{
		ft_lowest_per(count);
		return ;
	}
	if(count < 100)
	{
		ft_low_per(count);
		return ;
	}
}

void	ft_flow_fill(char *digit_buffer, int count, int i)
{
	while (count > 9)
	{
		if(i == 4)
		{
			digit_buffer[i] = '.';
			i++;
		}
		digit_buffer[i] = (count % 10) + '0';
		count /= 10;
		i++;
	}
	if(i == 4)
	{
		digit_buffer[i] = '.';
		i++;
	}
	digit_buffer[i] = count + '0';
}
void	ft_putflo(float nb)
{
	int		i;
	int		count;
	char	digit_buffer[9];

	count = 0;
	i = 2;
	digit_buffer[0] = '\0';
	digit_buffer[1] = '%';
	nb = nb * 10000;
	count = nb;
	if(count < 100)
		return(ft_low_print(count));
	ft_flow_fill(digit_buffer, count, i);
	ft_show_nbr(&i, digit_buffer, 2);
}

/*
typedef struct s_op
{
        unsigned short  sa;
        unsigned short  sb;
        unsigned short  ss;
        unsigned short  pa;
        unsigned short  pb;
        unsigned short  ra;
        unsigned short  rb;
        unsigned short  rr;
        unsigned short  rra;
        unsigned short  rrb;
        unsigned short  rrr;
}       t_ops;
*/
int ft_op_count(t_ops *all_ops)
{
	int n;

	n = (all_ops->sa + all_ops->sb + all_ops->ss);
	n += (all_ops->pa + all_ops->pb);
	n += (all_ops->ra + all_ops->rb + all_ops->rr);
	n += (all_ops->rra + all_ops->rrb + all_ops->rrr);
	return(n);
}
//sa:  0  sb:  0  ss:  0  pa:  5  pb:  6
//ra:  2  rb:  1  rr:  5  rra:  6  rrb:  8  rrr: 9


void ft_all_ops2(t_ops *all_ops)
{
	write(2, "[bench] ra:  ", 13);
	ft_putnbr_fd(all_ops->ra, 2);
	write(2, "  rb:  ", 7);
	ft_putnbr_fd(all_ops->rb, 2);
	write(2, "  rr:  ", 7);
	ft_putnbr_fd(all_ops->rr, 2);
	write(2, "  rra:  ", 8);
	ft_putnbr_fd(all_ops->rra, 2);
	write(2, "  rrb:  ", 8);
	ft_putnbr_fd(all_ops->rrb, 2);
	write(2, "  rrr:  ", 8);
	ft_putnbr_fd(all_ops->rrr, 2);
	write(2, "\n", 1);
}

void ft_all_ops(t_ops *all_ops)
{
	write(2, "[bench] sa:  ", 13);
	ft_putnbr_fd(all_ops->sa, 2);
	write(2, "  sb:  ", 7);
	ft_putnbr_fd(all_ops->sb, 2);
	write(2, "  ss:  ", 7);
	ft_putnbr_fd(all_ops->ss, 2);
	write(2, "  pa:  ", 7);
	ft_putnbr_fd(all_ops->pa, 2);
	write(2, "  pb:  ", 7);
	ft_putnbr_fd(all_ops->pb, 2);
	write(2, "\n", 1);
	ft_all_ops2(all_ops);
}
void bench_print(float dis, char *command, t_ops *all_ops)
{
	int total_ops;

	write(2, "[bench] disorder:  ", 19);
	ft_putflo(dis);	
	write(2, "\n", 1);
	write(2, "[bench] strategy:  ", 19);
	write(2, command, ft_strlen(command));
	write(2, "[bench] total_ops:  ", 20);
	total_ops = ft_op_count(all_ops);
	ft_putnbr_fd(total_ops, 2);	
	write(2, "\n", 1);
	ft_all_ops(all_ops);

}
