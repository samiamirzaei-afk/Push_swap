NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -Iinclude -MMD -MP
LDFLAGS		=
LDLIBS		=
DEBUG		?= 0
RM		= rm -f

# Optional libs: no configured optional library directory detected.
LIBS		=

JOBS		?= $(shell nproc)
MAKEFLAGS	+= -j $(JOBS) -l $(JOBS)

ifeq ($(DEBUG),1)
CFLAGS		+= -g3
CPPFLAGS	+= -DDEBUG=1
endif

SRC_DIR		= src
OBJ_DIR		= obj
SRCS		= $(SRC_DIR)/bench/bench.c \
			  $(SRC_DIR)/bench/bench_format.c \
			  $(SRC_DIR)/bench/bench_stats.c \
			  $(SRC_DIR)/bench/bench_strategy.c \
			  $(SRC_DIR)/ft_atoi.c \
			  $(SRC_DIR)/list.c \
			  $(SRC_DIR)/main.c \
			  $(SRC_DIR)/operations/operations.c \
			  $(SRC_DIR)/operations/operations_basic.c \
			  $(SRC_DIR)/operations/operations_reverse.c \
			  $(SRC_DIR)/operations/operations_rotate.c \
			  $(SRC_DIR)/parse.c \
			  $(SRC_DIR)/sort/bubble/bubble_sort.c \
			  $(SRC_DIR)/sort/bubble/five_sort.c \
			  $(SRC_DIR)/sort/chunk/chunk_push.c \
			  $(SRC_DIR)/sort/chunk/chunk_sort.c \
			  $(SRC_DIR)/sort/chunk/chunk_utils.c \
			  $(SRC_DIR)/sort/radix/radix.c \
			  $(SRC_DIR)/sort/radix/radix_index.c \
			  $(SRC_DIR)/sort_adaptive.c \
			  $(SRC_DIR)/utils/strutils.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

compiledb:
	$(MAKE) fclean
	compiledb -n make

-include $(DEPS)

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
