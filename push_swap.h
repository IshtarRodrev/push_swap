/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 07:04:58 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/12 07:04:58 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct stack
{
	int				data;
	struct stack	*next;
	struct stack	*prev;
	struct stack	*first;
	struct stack	*last;
}					stack;

stack *A = NULL;
stack *B = NULL;

sa ()
{
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one element or none.
}

sb()
{
	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one element or none.
}

ss ()
{
	// ss : sa and sb at the same time.
}

pa()
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
}

pb()
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
}

ra()
{
	// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.
}
rb()
{
	// rb (rotate b): Shift up all elements of stack b by 1.
	// The first element becomes the last one.
}
rr()
{
	// rr : ra and rb at the same time.
}

rra()
{
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// The last element becomes the first one.
}
rrb()
{
	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
}
rrr()
{
	// rrr : rra and rrb at the same time.
}

/* 
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random number of unique negative and/or positive
integers.
◦ The stack b is empty.
• The goal is to sort the numbers in stack a in ascending order. To achieve this, you
have the following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time. */

/* NORM
• A structure’s name must start by s_.
• A typedef’s name must start by t_.
• A union’s name must start by u_.
• An enum’s name must start by e_.
• A global’s name must start by g_.
• Identifiers, like variables, functions names, user defined types, can only contain
lowercases, digits and ’_’ (snake_case). No capital letters are allowed.*/