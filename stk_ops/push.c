/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:29:29 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/13 16:29:29 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include "libft/libft.h"
//https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/

void	push(t_stack *src_stk, t_stack *dst_stk)
{
	t_node	*node;

	if (!src_stk || !dst_stk || !src_stk->first)
		return ;
	node = src_stk->first;

	// detach from source
	src_stk->first = node->next;
	if (src_stk->first)
		src_stk->first->prev = NULL;
	else
		src_stk->last = NULL; //turns empty
	// attach to destination top
	node->prev = NULL;
	node->next = dst_stk->first;
	if (dst_stk->first)
		dst_stk->first->prev = node;
	else
		dst_stk->last = node; // dst was empty, node is also last
	dst_stk->first = node;

	// update sizes
	if (src_stk->size > 0)
		src_stk->size -= 1;
	dst_stk->size += 1;
}

void	pa(t_stack *b, t_stack *a)
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
	push(a, b);
	ft_printf("pb\n");
}
