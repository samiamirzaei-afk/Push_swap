NAME = a.bug

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
	  medium_sort.c\
	  rra_ra_sa_pa.c\
	  five_sort.c\
	  list_maker.c

all:
	$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)
