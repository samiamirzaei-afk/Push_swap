NAME = a.bug

CFLAGS = -Wall -Wextra

SRC = main.c\
	  disorder.c\
	  bubble.c
all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
