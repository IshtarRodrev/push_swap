CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c \
	main.c \
	stk_ops/push.c \
	stk_ops/swap.c \
	stk_ops/rotate.c \
	stk_ops/reverse_rotate.c \
	sort_algo/k_sort.c \
	sort_algo/mini_sort.c \
	parse/parse.c \
	parse/validation.c \
	utils/ft_atol.c

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h $(LIBFT_FOLDER)/libft.h

LIBFT_FOLDER = libft
LIBFT_LIB = $(LIBFT_FOLDER)/libft.a

NAME = push_swap

# arguments for run / test / debug: make run ARG="3 2 1"
ARG ?= 2 1 3 6 5 8

all: $(NAME)

# -lft -> libft.a
$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_FOLDER) -lft -o $(@)

# always ask libft's Makefile, it only rebuilds libft.a when its sources change
$(LIBFT_LIB): FORCE
	$(MAKE) -C $(LIBFT_FOLDER)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_FOLDER) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_FOLDER) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_FOLDER) fclean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) $(ARG)

# valgrind if available, otherwise run the program normally
test: $(NAME)
	@if command -v valgrind >/dev/null 2>&1; then \
		echo "Running valgrind..."; \
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(ARG); \
	else \
		echo "valgrind not found — running program instead"; \
		./$(NAME) $(ARG); \
	fi

# rebuild with -DDEBUG to print the stacks between the sorting steps
debug: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG"
	./$(NAME) $(ARG)

# regenerate main.c from the ```C block in README.md
main:
	sed -n '/```C/,/```/p' README.md | sed '1d' | sed '/```/d' > main.c

FORCE:

.PHONY: all clean fclean re run test debug main FORCE
