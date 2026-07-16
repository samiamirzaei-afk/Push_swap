#ifndef T_HEAD_H
#define T_HEAD_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>



/* utils */
void	ft_show_two(int *arrayA, int *arrayB, int size);
void	ft_show_one(int *arraya, int size);
int **ft_free_rad(int **result, int i);
int **ft_double_array(int size_a);
void    ft_print_radix(int **array, int size);

#endif
