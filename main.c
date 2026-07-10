/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:24:16 by ammirzae          #+#    #+#             */
/*   Updated: 2026/07/05 13:30:25 by ammirzae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
argv[0] = a.out
argv[1] = flag
argv[2] = numebr1
argv[3] = numebr2
argv[4] = numebr3
argv[5] = numebr4
argv[6] = NULL;
*/
#include "push.h" 

int	main(int argc, char **argv)
{
	int	i;
	int	*array;
	int	size;
	float	dis;
//       short   flags[FLAG_SIZE + 1];
//       int     main_flag;
//       int     option_flag;
	t_s_flag	s_flag;
	t_ops	*all_ops;
	t_list	*head;
	
	head = NULL;
//	main_flag = 0;
//	option_flag = 0;
//	(void)option_flag;
	s_flag.option_flag = 0;
	
	if (argc < 2)
	{
		printf("please provide 2 or more numbers [...]\n");
		return (1);
	}
	size = 0;
	if((ft_flag(argv, s_flag.flags)) == -1)
		return(write(1,"Error\n", 6), 1);
	for(i = 0; i <= FLAG_SIZE; i++)
		printf("flag%d:[%d]\n", i, s_flag.flags[i]);		

	array = ft_argv_to_array(argc, argv, &size);
	if(ft_array_check(array, size) == -1)
		return(write(1,"Error2\n", 7), 1);

	dis = ft_disorder(array, size);
	printf("disorder: %f\n", dis);
	ft_op_to_zero(&all_ops);

	ft_print_ops(&all_ops);
	if(dis == 0)
		return(0);
	i = 0;
	while(i < FLAG_SIZE)
	{
		if(s_flag.flags[i] == BENCH)
		{
			s_flag.option_flag = s_flag.flags[i];
//			i++;
		}
		if(s_flag.flags[i] >= ADAPTIVE && s_flag.flags[i] <= SIMPLE )
		{
			s_flag.main_flag = s_flag.flags[i];
//			i++;
		}
		i++;
	}
	printf("option:%d main:%d\n", s_flag.option_flag, s_flag.main_flag);
	if(s_flag.main_flag == SIMPLE)
	{
		bubble_main(array, size, s_flag.option_flag, &all_ops );
		ft_print_ops(&all_ops);
		free(all_ops);
		return(1);
	}

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
