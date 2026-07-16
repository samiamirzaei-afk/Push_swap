NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iinclude -MMD -MP

PRINT_OPERATIONS ?= 1
CPPFLAGS += -DPUSH_PRINT_OPERATIONS=$(PRINT_OPERATIONS)

RM = rm -rf

# Optional libs: no configured optional library directory detected.
LIBS =

JOBS ?= $(shell nproc)
MAKEFLAGS += -j$(JOBS) -l$(JOBS)

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/bench/bench.c \
	   $(SRC_DIR)/ft_atoi.c \
	   $(SRC_DIR)/list.c \
	   $(SRC_DIR)/main.c \
	   $(SRC_DIR)/operations/operations.c \
	   $(SRC_DIR)/operations/operations_basic.c \
	   $(SRC_DIR)/operations/operations_reverse.c \
	   $(SRC_DIR)/operations/operations_rotate.c \
	   $(SRC_DIR)/parse.c \
	   $(SRC_DIR)/sort.c \
	   $(SRC_DIR)/utils/strutils.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb:
	$(MAKE) fclean
	compiledb -n make

-include $(DEPS)

.PHONY: all clean fclean re compiledb
.DEFAULT_GOAL := all
