#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct s_five 
{
        int small;
        int big;
        int small_i;
        int big_i;

}	t_big_small;

/* rra_ra_sa_pa.c */
void	ft_ra(int *array_a, int size, char *command);
void	ft_rra(int *array_a, int size, char *command);
void	ft_pb(int *array_a, int *array_b, int *size_a, int *size_b, char *command);
void	ft_swap(int *array);

/* five_sort */
void	ft_big_small(int *array, int size, t_big_small *list); 
void	ft_three_sort(int *array_a, int size_a);
void	five_sort(int *array_a, int *array_b, int size_a);

/* bubble_sort.c */
void	ft_show_two(int *array_a, int *array_b, int size);
void	ft_show_one(int *arraya, int size);
int	ft_small(int *array, int size, int *small_i);
void	ft_bubble(int *array_a, int *array_b, int size_a);
#endif
