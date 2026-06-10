NAME = a.bug

CFLAGS = -Wall -Wextra

SRC = main.c\
	  disorder.c\
	  argv_to_array.c\
	  flag.c
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
