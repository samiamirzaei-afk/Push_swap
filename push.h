#ifndef PUSH_H
#define PUSH_H


/*	disorder.c */
float ft_disorder(int*, int);

/* bubble.c */
int *ft_argv_to_array(int argc, char **argv, int *size);

typedef enum e_flag
{
    ADAPTIVE = 1,
    COMPLEX,
    MEDIUM,
    SIMPLE,
    BENCH
}   t_flag;
/*
--adaptive = 1
--complex = 2
--medium	= 3
--simple = 4
--bench = 5
*/
#endif


