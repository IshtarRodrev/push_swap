/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:08:15 by akechedz          #+#    #+#             */
/*   Updated: 2026/10/26 18:13:57 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(t_stack *a);

static void	micro_sort(t_stack *a);

static void	reverse_micro_sort(t_stack *b);

static void	push_smallest(t_stack *a, t_stack *b, int limit)
{
	t_node	*top;
	t_node	*bot;

	while (a->size > 3)
	{
		top = a->first;
		bot = a->last;
		while (top->index >= limit && bot->index >= limit)
		{
			top = top->next;
			bot = bot->prev;
		}
		if (top->index < limit)
			while (a->first->index >= limit)
				ra(a);
		else
			while (a->first->index >= limit)
				rra(a);
		pb(a, b);
	}
}

void	mini_sort(t_stack *a, t_stack *b)
{
	if (!a || !b || is_sorted(a))
		return ;
	if (a->size > 3)
		push_smallest(a, b, a->size - 3);
	micro_sort(a);
	reverse_micro_sort(b);
	while (b->first)
		pa(b, a);
}
/*TODO: Does it may make sence to open is_sorted() function so it can be used outside mini_sort*/
static int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->first;
	while (cur && cur->next)
	{
		if (cur->index > cur->next->index)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void	micro_sort(t_stack *a)
{
	if (a->size == 3)
	{
		if (a->first->index > a->first->next->index
			&& a->first->index > a->last->index)
			ra(a);
		else if (a->first->next->index > a->first->index
			&& a->first->next->index > a->last->index)
			rra(a);
	}
	if (a->size >= 2 && a->first->index > a->first->next->index)
		sa(a);
}

static void	reverse_micro_sort(t_stack *b)
{
	if (b->size == 3)
	{
		if (b->first->index < b->first->next->index
			&& b->first->index < b->last->index)
			rb(b);
		else if (b->first->next->index < b->first->index
			&& b->first->next->index < b->last->index)
			rrb(b);
	}
	if (b->size >= 2 && b->first->index < b->first->next->index)
		sb(b);
}
