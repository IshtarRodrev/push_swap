/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:30:32 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/13 16:30:32 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *src_stk)
{
	t_node	*tmp;

	if (!src_stk || !src_stk->first || src_stk->first == src_stk->last)
		return ;
	tmp = src_stk->first;
	src_stk->first = src_stk->first->next;
	src_stk->first->prev = NULL;
	tmp->next = NULL;
	tmp->prev = src_stk->last;
	src_stk->last->next = tmp;
	src_stk->last = tmp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
