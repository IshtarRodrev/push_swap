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

# include "push_swap.h"// TODO
//https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/

void	push(t_stack *src_stk, t_stack *dst_stk)
{
	t_node	*node;

	if (!src_stk || !dst_stk)
		return ;
	node = src_stk->first;
	if (dst_stk->first == NULL)
		dst_stk->last = node;
	src_stk->first = node->next;
	if (src_stk->first)
		src_stk->first->prev = NULL;
	node->next = dst_stk->first;
	if (dst_stk->first)
		dst_stk->first->prev = node;
	dst_stk->first = node;
}

void	pa(t_stack *b, t_stack *a)
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
	push(a, b);
	ft_printf("pb\n");
}
