NAME = q.bug

CFLAGS = -Wall -Wextra

SRC = main.c\
	  disorder.c\
	  argv_to_array.c\
	  flag.c\
	  utils.c\
	  utils2.c\
	  ft_atoi.c\
	  error_check.c\
	  bubble_sort.c\
	  rra_ra_sa_pa_pb.c\
	  five_sort.c\
	  list_maker.c\
	  ft_op_to_zero.c\
	  bench_print.c\
	  radix_main.c\
	  list_swap_ro_rero_pb_pa.c

all:
	$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)
