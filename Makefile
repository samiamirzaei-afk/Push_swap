NAME = a.bug

CFLAGS = -Wall -Wextra

SRC = main.c\
	  disorder.c\
	  argv_to_array.c\
	  flag.c\
	  utils.c\
	  utils2.c\
	  ft_atoi.c
all:
	$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)
