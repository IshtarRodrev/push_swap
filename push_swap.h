/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 07:04:58 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/12 07:04:58 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
	int             index;
}t_node;

typedef struct s_stack
{
	t_node	*first;
	t_node	*last;
	size_t	size;
}t_stack;

/* stack operations (wrappers that print the operation) */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

/* core helpers */
// parser-local helpers (dup-check and fill_stack) are internal to parse/
int		parse_args(int argc, char **argv, t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	k_sort(t_stack *a, t_stack *b);
t_stack *stk_init(void);
void	stk_normalize(t_stack *stk);
void	reintegrate(t_stack *a, t_stack *b);
void	print_list(t_node *head);
void	stk_free(t_stack *stack);

#endif
