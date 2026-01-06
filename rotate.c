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

void	rotate(t_stack *src_stk)	
{
	if(!src_stk->first || src_stk->first == src_stk->last)
		return ;
	src_stk->first->prev = src_stk->last;
	src_stk->last->next = src_stk->first;
	src_stk->first = src_stk->first->next;
	src_stk->last = src_stk->first->prev;
	src_stk->first->prev = NULL;
	src_stk->last->next = NULL;
	return ;
}

void	ra(t_stack *a)
{
	// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.
	rotate(a);
	printf("ra\n");
}
void	rb(t_stack *b)
{
	// rb (rotate b): Shift up all elements of stack b by 1.
	// The first element becomes the last one.
	rotate(b);
	printf("rb\n");
}
void	rr(t_stack *a, t_stack *b)
{
	// rr : ra and rb at the same time.
	rotate(a);
	rotate(b);
	printf("rr\n");
}
