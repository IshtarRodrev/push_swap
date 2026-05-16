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

#include "push_swap.h"
#include "libft/libft.h"

void	push(t_stack *src_stk, t_stack *dst_stk)
{
	t_node	*node;

	if (!src_stk || !dst_stk || !src_stk->first)
		return ;
	node = src_stk->first;
	src_stk->first = node->next;
	if (src_stk->first)
		src_stk->first->prev = NULL;
	else
		src_stk->last = NULL;
	node->prev = NULL;
	node->next = dst_stk->first;
	if (dst_stk->first)
		dst_stk->first->prev = node;
	else
		dst_stk->last = node;
	dst_stk->first = node;
	if (src_stk->size > 0)
		src_stk->size -= 1;
	dst_stk->size += 1;
}

void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
