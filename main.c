/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ammirzae <ammirzae@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:24:16 by ammirzae          #+#    #+#             */
/*   Updated: 2026/06/25 13:58:37 by ammirzae         ###   ########.fr       */
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
	short	flags[FLAG_SIZE + 1];


	if (argc < 2)
	{
		printf("please provide 2 or more numbers [...]\n");
		return (1);
	}
	size = 0;
	if((ft_flag(argv, flags)) == -1)
		return(write(1,"Error\n", 6), 1);
	for(i = 0; i <= FLAG_SIZE; i++)
		printf("flag%d:[%d]\n", i, flags[i]);		

	array = ft_argv_to_array(argc, argv, &size);
	if(ft_array_check(array, size) == -1)
		return(write(1,"Error2\n", 7), 1);

	dis = ft_disorder(array, size);
	printf("disorder: %f\n", dis);
	if(dis == 0)
		return(0);
		
	return(0);
}
