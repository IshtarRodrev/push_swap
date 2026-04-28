/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:53:00 by akechedz          #+#    #+#             */
/*   Updated: 2026/02/06 15:53:00 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	k_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	delta;
	int	threshold;

	n = a->size;
	delta = n / 20 + 7;
	threshold = 0;
	while (a->first)
	{
		if (a->first->data <= threshold + delta)
		{
			pb(a, b);
			if (b->first->data <= threshold)
				rb(b);
			threshold++;
		}
		else
		{
			ra(a);
		}
	}
}

void	reintegrate(t_stack *a, t_stack *b) //FIXME: this is pseudocode
{
	while (b->first)//do until B is empty
	{
		int max_index;
		int pos;

		max_index = get_max_index(b);
		pos = get_position(b, max_index);
		if (pos <= b->size / 2)
		{
			while (b->first->index != max_index)
				rb(b);
		}
		else
		{
			while (b->first->index != max_index)
				rrb(b);
		}
		pa(b, a);
	}
}

/*
echo "pb\npb\npb\nrrb\npa\nrrb\npa\npa" | ./checker_linux 3 2 1 
echo "pb\npb\npb\nrrb\npa\nrrb\npa\npa" | ./misc/checker_linux 3 2 1
*/