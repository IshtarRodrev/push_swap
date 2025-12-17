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
void	pa(t_stack *b, t_stack *a)
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
	t_node	*node;

	if (!b || !a)
		return ;
	node = b->first;
	if (a->first == NULL)
		a->last = node;
	b->first = node->next;
	if (b->first)
		b->first->prev = NULL;
	node->next = a->first;
	if (a->first)
		a->first->prev = node;
	a->first = node;
}


pb()
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
}
