/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:24:16 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/10 11:45:04 by ammirzae         ###   ########.fr       */
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
	int		i;
	int		*array;
	int		size;
	float		dis;
	short	flags[2];
	


	if (argc < 2)
	{
		printf("please provide 2 or more numbers [...]\n");
		return (1);
	}
	i = 1;
	size = 0;
	if((ft_flag(argv, flags)) <= 0)
		return(write(1,"Error\n", 6), 1);
	printf("flag1:%d flag2:%d\n", flags[0], flags[1]);		

	return(0);
	
	array = ft_argv_to_array(argc, argv, &size);
	dis = ft_disorder(array, size);
	printf("%f", dis);

}
