/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:28:22 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/13 16:28:22 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	swap(t_stack *src_stk)
{
	t_node	*one;
	t_node	*two;

	if (!src_stk || !src_stk->first || !src_stk->first->next)
		return ;
	one = src_stk->first;
	two = src_stk->first->next;
	one->next = two->next;
	if (two->next)
		two->next->prev = one;
	two->prev = NULL;
	two->next = one;
	one->prev = two;
	src_stk->first = two;
}

void	swap2(t_stack *src_stk)
{
	t_node	*tmp;

	if (!src_stk || !src_stk->first || !src_stk->first->next)
		return ;
	tmp = src_stk->first->next;
	tmp->prev = NULL;
	tmp->next = src_stk->first->next;
	src_stk->first = tmp;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack *b, t_stack *a)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
