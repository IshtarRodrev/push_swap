# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 17:43:40 by akechedz          #+#    #+#              #
#    Updated: 2025/10/09 14:28:38 by akechedz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This Makefile example contains some variables and automatic variables
# Below is the same Makefile without the variables and automatic variables
# NAME is a variable containing the name of the executable
# we want to create.
NAME = libft.a

CC = cc

CCFLAGS = -Wall -Wextra -Werror 

# SRC is a variable containing all .c files required to build the project
	# Note that every file name has to be separated by a space and that I 
	# didn't use a wildcard (*.c) to get every file.
	# While the usage of a wildcard would be simpler, it is not authorized by
	# the 42 Norm as it is easier to input an unwanted file in the build 
	# process by simply adding it in the src folder.
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_strmapi.c \
	ft_putnbr_fd.c

BONUS_SRC = ft_lstnew.c \
			ft_lstsize.c 

HEADER = libft.h

# OBJ is a variable containing all .o files.
	# As you can see I wrote OBJ := and not OBJ =
	# The difference between := and = is that = is an assignement like we know
	# in C. := tells make to append the result to the variable
	# We have to append the result because what's on the right will be run for
	# every .c file

# Whats on the right basically means : "for every .c file you find in the
	# SRC variable, give me the corresponding .o file".
	# This will then append the result for each .c file to the OBJ variable.
	# It simply replaces the .c in each files in the SRC variable by .o
	# This is definition:
OBJ := $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

# ALL is the first rule in the Makefile, making it the default rule when
	# calling the make command without specifying the rule.
	# As said in the description table above, this rule has the $(NAME) rule
	# as dependency and will therefore, call the $(NAME) rule
	# This is dependency:
all: $(NAME)

# $(NAME) is, as said above, the main rule of the Makefile.
	# This rule has the OBJ variable as dependency, which means, if one or
	# more .o files are missing, make will try to build them (if a rule for
	# that exists) before running the $(NAME) commands. 
	# When all the dependency are there, the commands will be executed.
	# This commande takes two automatic variables, $^ and $@
	#
	# $^: The name of all the prerequisites, with space between them
	# $@: This corresponds to the name of the target, in this case this will
	#    be libft.a.

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

# %.o rule will compile one .c file to its correspondig object (.o) file
	# The %.o: %.c pattern specifies that in order to build something whose
	# file name ends with .o, you need to have a file that has the same prefix
	# but then ends with .c rather than .o.
	# $<: The name of the first prerequisite.
	# $@: This corresponds to the name of the target, in this case this will
	#    be libft.a.
%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

# CLEAN rule has no prerequisites
	# What it does is run the rm -f shell command followed by the content of
	# the OBJ variable, that is, every .o filenames.
	# This results in all the .o files being deleted.
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# FCLEAN rule has as prerequisite the CLEAN rule, which means that the 
	# CLEAN rule will be run first. 
	# When the CLEAN rule is done, the fclean commands will be run.
	# This results in all the .io files being deleted, as well as the created
	# library because it has the name $(NAME)
fclean: clean
	rm -f $(NAME)

# RE rule has as prerequisites the FCLEAN and ALL rules.
	# As the prerequisite are read from left to right, the first rule to be
	# executed will be the FCLEAN rule, then we'll have the ALL rule
	# Since there are no commands for the RE rule, once the ALL rule is done,
	# the RE rule will also be done.
re: fclean all

# test: $(OBJ) main.o
# 	$(CC) $^

# debug:
# 	$(CC) -g main.c $(SRC) -o debug_exec && lldb ./debug_exec

# Lesson: Filename must be Makefiel
# Lesson2 : must be tab

#TODO: To turn in bonuses to your project, 
	#you must include a rule bonus to your Makefile, 
	#which will add all the various headers, libraries 
	#or functions that are forbidden on the main part 
	#of the project. Bonuses must be in a different 
	#file _bonus.{c/h} if the subject does not specify 
	#anything else. Mandatory and bonus part evaluation 
	#is done separately.
bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)


.PHONY: all clean fclean re #test debug