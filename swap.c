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

#include "push_swap.h"// TODO

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
	//why not just swap the ->data of both nodes, why, why??
	src_stk->first = tmp;
}
/*
void	swap3(t_stack *src_stk)
{
	t_node	*tmp_node;

	tmp_node = new_node(src_stk->first->next);
}
*/
	/* you can use a temporary pointer to store the second node, 
	then adjust the pointers of the first node, 
	and finally adjust the pointers of the second node */

void	sa(t_stack *a)
{
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one element or none.
	swap(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{
	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one element or none.
	swap(b);
	printf("sb\n");
}

void	ss(t_stack *b, t_stack *a)
{
	// ss : sa and sb at the same time.
	swap(a);
	swap(b);
	printf("ss\n");
}
