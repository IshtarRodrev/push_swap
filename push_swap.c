/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:23:33 by akechedz          #+#    #+#             */
/*   Updated: 2026/05/12 21:35:37 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> //FIXME: remove if INT_MAX unused
#include <stdlib.h>
#include "libft/libft.h"

/* void	push_swap()
{
	//the magic;
	//https://pythontutor.com/visualize.html#mode=edit
	//https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376
	//https://www.google.com/search?q=push+swap+ksort&sca_esv=a87a460474998c14&udm=50&fbs=ADc_l-YGrpJMQtvjQ6h14rj-dfIrH4mwN5r0Z1FZtFNB2w3Upe2HDPC6akWpYUJBWeXXRd1nD-EOaE0XinGd5KvoJHG8OW6hbPG5HGkmH5eSOG4TMBnyznkwl4rk7eTLPmGiiMXA5VY9M9TuEf30xK4inDhkSZpsG7LKn-gYXluNSgL4chfqr1ROt-6fxN4aMa1bK4-MNo7i&aep=1&ntc=1&sa=X&ved=2ahUKEwjQoqPq3K6SAxXK5QIHHWcdEVUQ2J8OegQICRAD&biw=2663&bih=1297&dpr=1&aic=0&mstk=AUtExfDtognJwVWGkKvQQlQCGVZoGPYfdpx7o5VD0dJh4EdPIt1tGMJZQrxkicIJ5BM7no-Xu_YlcPMl9ruPdBgbKde30pYb2dzfj8IVLqqKvbmGhz26ohjHq6Ylz3TiOh9m0x_BnIBAIg8l-kaymlE3mYP5SbeJzJQsS5c&csuir=1
} */

/* parser-local helpers moved to parse/parse.c */

void	print_list(t_node *head)
{
	t_node	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		ft_printf("%d[%d] -> ", curr->data, curr->index);
		curr = curr->next;
		if (curr == NULL)
			ft_printf("NULL");
		// if (curr == head)
		// 	break ;
	}
	ft_printf("\n");
	return ;
}

void	stk_free(t_stack *stack)
{
	t_node *curr;
	t_node *next;

	if (!stack)
		return ;
	curr = stack->first;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
}

t_stack *stk_init(void)
{
	t_stack * stk;

	stk = calloc(1, sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->first = NULL;
	stk->last = NULL;
	stk->size = 0;
	return (stk);
}

void stk_normalize(t_stack *stk)
{
	t_node  *cur;
	t_node  *tmp;
	int     rank;

	if (!stk || !stk->first)
		return ;
	cur = stk->first;
	while (cur)
	{
		rank = 0;
		tmp = stk->first;
		while (tmp)
		{
			if (tmp->data < cur->data)
				rank++;
			tmp = tmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

// ./push_swap 2 1 3 6 5 8  

/*
int	main(int argc, char **argv)//TODO: rename this func to push_swap
{    
	t_stack    *a;
	t_stack    *b;

	if (argc < 2)
		return (1);
	a = calloc(1, sizeof(t_stack));
	if (!a)
		return (1);
	b = calloc(1, sizeof(t_stack));
	if (!b)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		stk_free(a);
		stk_free(b);
		return (ft_printf("Error\n"), 1);
	}
	// b->first = NULL;
 	print_list(a->first);
	pa(a, b);
	pa(a, b);
	print_list(a->first);
	pa(a, b);
	print_list(a->first);
	ra(a);
	print_list(a->first);
	print_list(a->first);
	print_list(b->first);
//	k_sort(a, b);
	stk_free(a);
	stk_free(b);
	return (0);
}
*/
/*
sa()
{
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one element or none.
}

sb()
{
	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one element or none.
}

ss()
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
*/
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
// TODO: NORMALISE DATA!!!