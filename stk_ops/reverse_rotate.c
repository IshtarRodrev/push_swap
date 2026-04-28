/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:31:22 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/13 16:31:22 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
# include "libft/libft.h"

void	reverse_rotate(t_stack *s)
{
	t_node *tmp;

	if(!s || !s->first || s->first == s->last)
		return ;
	tmp = s->last;
	s->last = tmp->prev;
	s->last->next = NULL; 
	tmp->prev = NULL;
	tmp->next = s->first;
	s->first->prev = tmp; 
	s->first = tmp;
}
void	rra(t_stack *a)
{
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// The last element becomes the first one.
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	// rrr : rra and rrb at the same time.
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
