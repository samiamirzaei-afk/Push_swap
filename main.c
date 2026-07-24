/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:24:16 by ammirzae          #+#    #+#             */
/*   Updated: 2026/07/22 14:14:20 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push.h" 

int main_4(t_s_flag s_flag, t_ops *all_ops, t_di_ar rest)
{

	if(s_flag.main_flag == MEDIUM)
	{
		bubble_main(rest.array, rest.size, s_flag.option_flag, &all_ops);
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, MED_FULL, all_ops);
		free(all_ops);
		return(0);
	}
	if(s_flag.main_flag == ADAPTIVE)
	{
		if(rest.dis >= 0.2 && rest.dis < 0.5)
		{
			bubble_main(rest.array, rest.size, s_flag.option_flag, &all_ops);
			if(s_flag.option_flag == BENCH)
				bench_print(rest.dis, ADA_MED_FULL, all_ops);
		free(all_ops);
		return(1);
		}
	}
	return(0);
}

int main_3(t_s_flag s_flag, t_ops *all_ops, t_di_ar rest)
{
	if(s_flag.main_flag == COMPLEX)
	{
		radix_main(rest.array, rest.size, s_flag.option_flag, &all_ops );
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, COM_FULL, all_ops);
		return(free(all_ops), 0);
	}
	if(s_flag.main_flag == ADAPTIVE && rest.dis >= 0.5)
	{
		radix_main(rest.array, rest.size, s_flag.option_flag, &all_ops);
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, ADA_COM_FULL, all_ops);
		return(free(all_ops), 0);
	}
	return(main_4(s_flag, all_ops, rest));
}

int main_2(t_s_flag s_flag, t_ops *all_ops, t_di_ar rest)
{
	if(rest.dis == 0)
	{
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, SORT_FULL, all_ops);
		printf("already sorted!\n");
		return(free(all_ops), free(rest.array), 0);
	}
	if(s_flag.main_flag == SIMPLE)
	{
		bubble_main(rest.array, rest.size, s_flag.option_flag, &all_ops );
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, SIM_FULL, all_ops);
		return(free(all_ops), 0);
	}
	if(s_flag.main_flag == ADAPTIVE && rest.dis < 0.2)
	{
		bubble_main(rest.array, rest.size, s_flag.option_flag, &all_ops);
		if(s_flag.option_flag == BENCH)
			bench_print(rest.dis, ADA_SIM_FULL, all_ops);
		return(free(all_ops), 0);
	}
	main_3(s_flag, all_ops, rest);
	return(0);
}



int main_1(int *array, int size, t_s_flag s_flag)
{
	int	i;
	t_ops	*all_ops;
	t_di_ar	rest;
	
	rest.dis = ft_disorder(array, size);
	if(ft_op_to_zero(&all_ops) == NULL)
		return(free(array), -1);
	i = 0;
	while(i < FLAG_SIZE)
	{
		if(s_flag.flags[i] == BENCH)
			s_flag.option_flag = s_flag.flags[i];
		if(s_flag.flags[i] >= ADAPTIVE && s_flag.flags[i] <= SIMPLE )
			s_flag.main_flag = s_flag.flags[i];
		i++;
	}
	rest.array = array;
	rest.size = size;
	return (main_2(s_flag, all_ops, rest));
}


int	main(int argc, char **argv)
{
	int	*array;
	int	size;
	t_s_flag	s_flag;
	
	if (argc < 3)
		return (1);
	s_flag.option_flag = 0;
	size = 0;
	if((ft_flag(argv, s_flag.flags)) == -1)
		return(write(1,"Error\n", 6), 1);
	array = ft_argv_to_array(argc, argv, &size);
	if(array == NULL)
		return(0);
	if(ft_array_check(array, size) == -1)
		return(write(1,"Error2\n", 7), 1);
	main_1(array, size, s_flag);
}


/*
int	main(int argc, char **argv)
{
	int	i;
	int	*array;
	int	size;
	float	dis;
	t_s_flag	s_flag;
	t_ops	*all_ops;
	t_list	*head;
	
	head = NULL;
	s_flag.option_flag = 0;
	
	if (argc < 2)
	{
		printf("please provide 2 or more numbers [...]\n");
		return (1);
	}
	size = 0;
	if((ft_flag(argv, s_flag.flags)) == -1)
		return(write(1,"Error\n", 6), 1);
	array = ft_argv_to_array(argc, argv, &size);
	if(ft_array_check(array, size) == -1)
		return(write(1,"Error2\n", 7), 1);
	dis = ft_disorder(array, size);
	ft_op_to_zero(&all_ops);
	i = 0;
	while(i < FLAG_SIZE)
	{
		if(s_flag.flags[i] == BENCH)
			s_flag.option_flag = s_flag.flags[i];
		if(s_flag.flags[i] >= ADAPTIVE && s_flag.flags[i] <= SIMPLE )
			s_flag.main_flag = s_flag.flags[i];
		i++;
	}
	if(dis == 0)
	{
		if(s_flag.option_flag == BENCH)
			bench_print(dis, SORT_FULL, all_ops);
		free(all_ops);
		free(array);
		return(0);
	}
	if(s_flag.main_flag == SIMPLE)
	{
		bubble_main(array, size, s_flag.option_flag, &all_ops );
		if(s_flag.option_flag == BENCH)
			bench_print(dis, SIM_FULL, all_ops);
		free(all_ops);
		return(1);
	}
	if(s_flag.main_flag == COMPLEX)
	{
		bubble_main(array, size, s_flag.option_flag, &all_ops );
		if(s_flag.option_flag == BENCH)
			bench_print(dis, COM_FULL, all_ops);
		free(all_ops);
		return(1);
	}
	if(s_flag.main_flag == MEDIUM)
	{
		bubble_main(array, size, s_flag.option_flag, &all_ops );
		if(s_flag.option_flag == BENCH)
			bench_print(dis, MED_FULL, all_ops);
		free(all_ops);
		return(1);
	}
	if(s_flag.main_flag == ADAPTIVE)
	{
		if(dis < 0.2)
		{
			bubble_main(array, size, s_flag.option_flag, &all_ops);
			if(s_flag.option_flag == BENCH)
				bench_print(dis, ADA_SIM_FULL, all_ops);
		free(all_ops);
		return(1);
		}
		if(dis >= 0.2 && dis < 0.5)
		{
			bubble_main(array, size, s_flag.option_flag, &all_ops);
			if(s_flag.option_flag == BENCH)
				bench_print(dis, ADA_MED_FULL, all_ops);
		free(all_ops);
		return(1);
		}
		if(dis >= 0.5)
		{
			bubble_main(array, size, s_flag.option_flag, &all_ops);
			if(s_flag.option_flag == BENCH)
				bench_print(dis, ADA_COM_FULL, all_ops);
		free(all_ops);
		return(1);
		}
	}
// IGNORE AFTER
	if(list_maker(array, size, &head) == 0)
		return(write(1,"Error3\n", 7), 1);
	t_list *ptr_ptr;
	ptr_ptr = head;
	for(i = 0; ptr_ptr != NULL; i++)
	{
		printf("link[%d]: %d\n", i, ptr_ptr->num);
		ptr_ptr = ptr_ptr->next;
	}
	ft_lstclear(&head);
	free(all_ops);

	return(0);
}
*/
