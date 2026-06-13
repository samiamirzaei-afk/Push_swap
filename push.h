#ifndef PUSH_H
#define PUSH_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>


/*	disorder.c */
float ft_disorder(int*, int);

/* bubble.c */
int *ft_argv_to_array(int argc, char **argv, int *size);

/* flag.c */
int ft_flag(char **argv, short *flags);

typedef enum e_flag
{
    ADAPTIVE = 1,
    COMPLEX,
    MEDIUM,
    SIMPLE,
    BENCH
}   t_flag;

#define ADA "--adaptive"
#define COM "--complex"
#define MED "--medium"
#define SIM "--simple"
#define BEN "--bench"

/*
--adaptive = 1
--complex = 2
--medium	= 3
--simple = 4
--bench = 5
*/
#endif


