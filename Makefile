CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	stk_ops/push.c \
	stk_ops/swap.c \
	stk_ops/rotate.c \
	stk_ops/reverse_rotate.c

OBJS = $(SRCS:.c=.o)

LIBFT_FOLDER = libft
LIBFT_LIB = $(LIBFT_FOLDER)/libft.a 

NAME = push_swap

all: $(NAME)

# libtmp.a
# -ltmp -> lib tmp .a

# -lft -> libft.a
$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_FOLDER) -lft -I. -o $(@)

$(LIBFT_LIB) :
	make -C $(LIBFT_FOLDER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: main.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o test

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_FOLDER) -c $< -o $@

# test: main.o $(OBJS)
# 	$(CC) $(CFLAGS) main.o $(OBJS) -o test

# test: $(OBJ) main.o
# 	$(CC) $^

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