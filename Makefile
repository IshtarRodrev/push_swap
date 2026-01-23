CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c

OBJS = $(SRCS:.c=.o)

LIBFT_SRCS = libft/ft_calloc.c \
	libft/ft_memset.c \
	libft/ft_atoi.c
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(OBJ) main.o
	$(CC) $^

# test: $(OBJ) main.o
# 	$(CC) $(OBJ) main.o -o test.out

# main: 
# 	cat README.md | grep -i '```C' -A31 | tail -n31 > main.c
main: 
	sed -n '/```C/,/```/p' README.md | sed '1d' | sed '/```/d' > main.c
# block2: 
# 	sed -n '0,/```C/{/```C/!d}; /```C/,/```/p' README.md | sed '1d;/```/d' > block2.c

# block5: 
# 	awk '/```C/{c++} c==5{print} /```/{if(c==5)exit}' README.md | sed '/```/d' > block5.c

run: $(NAME)
	./$(NAME)

debug: make -g && lldb./a.out

.PHONY: all clean fclean re test run debug