#ifndef PUSH_H
#define PUSH_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define ADA "adaptive"
#define COM "complex"
#define MED "medium"
#define SIM "simple"
#define BEN "bench"
#ifndef FLAG_SYMBOL
#define FLAG_SYMBOL '+'
#endif
#ifndef FLAG_SIZE
#define FLAG_SIZE 2
#endif

#define SORT_FULL "Already sorted\n"
#define SIM_FULL "Simple  / O(𝑛^2)\n"
#define MED_FULL "Medium  / O(𝑛√𝑛)\n"
#define COM_FULL "Simple  / O(𝑛 𝑙𝑜𝑔 𝑛)\n"

typedef struct s_array
{
	int	*array_a;
	int 	*array_b;
	int	size_a;
	int	size_b;

}	t_arrays;

typedef struct s_flag
{
	short	flags[FLAG_SIZE + 1];
	short 	main_flag;
	short	option_flag;

}	t_s_flag;

typedef struct s_op
{
        unsigned short	sa;
        unsigned short	sb;
        unsigned short	ss;
        unsigned short	pa;
        unsigned short	pb;
        unsigned short	ra;
        unsigned short	rb;
        unsigned short	rr;
        unsigned short	rra;
        unsigned short	rrb;
        unsigned short	rrr;
}	t_ops;


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

/* ft_op_to_zero.c */
void	ft_print_ops(t_ops **all_ops);
t_ops	**ft_op_to_zero(t_ops **all_ops);
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

typedef struct s_list
{
	int		num;
	struct s_list	*next;
}	t_list;

typedef struct s_five 
{
        int small;
        int big;
        int small_i;
        int big_i;

}	t_big_small;



/* rra_ra_sa_pa_pb.c */
void	ft_ra(t_arrays *list, char *command, short option, t_ops **all_ops);
void	ft_rra(t_arrays *list, char *command, short option, t_ops **all_ops);
void	ft_swap(int *array, char *command, short option, t_ops **all_ops);
void	ft_pa(t_arrays *list, char *command, short option, t_ops **all_ops);
void	ft_pb(t_arrays *list, char *command, short option, t_ops **all_ops);

/* five_sort */
void	ft_big_small(int *array, int size, t_big_small *list); 
void	ft_three_sort(t_arrays list, short option, t_ops **all_ops);
void	five_sort(t_arrays list, short option, t_ops **all_ops);

/* disorder.c */ 
int ft_sort(int *array, int size);
float ft_disorder(int *array, int size);

/* bubble_sort.c */
void	ft_show_two(int *array_a, int *array_b, int size);
void	ft_show_one(int *arraya, int size);
int	ft_small(int *array, int size, int *small_i);
void	ft_bubble(t_arrays list, short option, t_ops **all_ops);
void	bubble_main(int *array_a, int size, short option, t_ops **all_ops);

/* ??? */
int	list_maker(int *array, int size, t_list **head);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front( t_list **list, t_list *new);
int	ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstdelone(t_list *trash, void (*del)(void*));
void	ft_lstclear(t_list **head);
void	ft_lstiter(t_list *list, void (*f)(void *));

/* bench_print.c */
void	bench_print(float dis, char *command, t_ops *all_ops);


/*
--adaptive = 1
--complex = 2
--mediu	= 3
--simple = 4
--bench = 5
*/
#endif


