NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude -MMD -MP
PRINT_OPERATIONS ?= 1
CPPFLAGS += -DPUSH_PRINT_OPERATIONS=$(PRINT_OPERATIONS)
RM = rm -rf

# Optional libs: no configured optional library directory detected.
LIBS		=

SRC_DIR = src
OBJ_DIR = obj
SRCS		= $(SRC_DIR)/ft_atoi.c \
			  $(SRC_DIR)/list.c \
			  $(SRC_DIR)/main.c \
			  $(SRC_DIR)/operations.c \
			  $(SRC_DIR)/operations_basic.c \
			  $(SRC_DIR)/operations_rotate.c \
			  $(SRC_DIR)/operations_reverse.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/sort.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
