NAME = a.bug

CFLAGS = -Wall -Wextra

SRC = main.c\
	  disorder.c\
	  bubble.c\
	  flag.c
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
