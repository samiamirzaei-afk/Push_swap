#ifndef PUSH_H
#define PUSH_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>



/*	disorder.c */
float ft_disorder(int*, int);

/* argv_to_array.c */
int *ft_argv_to_array(int argc, char **argv, int *size);

/* flag.c */
int ft_version_finder(char *str);
int ft_found_flag(char *str);
int ft_flag(char **argv, short *flags);

/* utils.c */
int	ft_strcmp(char *s1, char *s2);
int	ft_isdigit_plus(int num);
int	ft_isdigit_str(char *str);
int	ft_isdigit(int num);
int	ft_isalpha(int number);

/* utils2.c */
short ft_issymbol(int num);

/* ft_atoi */
int	ft_atoi(char *str);


/* error_check */
short	ft_array_check(int *array, int size);

typedef enum e_flag
{
    ADAPTIVE = 1,
    COMPLEX,
    MEDIUM,
    SIMPLE,
    BENCH
}   t_flag;

#define ADA "adaptive"
#define COM "complex"
#define MED "medium"
#define SIM "simple"
#define BEN "bench"
#ifndef FLAG_SYMBOL
#define FLAG_SYMBOL '-'
#endif
#ifndef FLAG_SIZE
#define FLAG_SIZE 2
#endif

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
int	bubble_main(int *array_a, int size);




/*
--adaptive = 1
--complex = 2
--mediu	= 3
--simple = 4
--bench = 5
*/
#endif


