/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:23:33 by akechedz          #+#    #+#             */
/*   Updated: 2026/05/20 13:16:14 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

void	print_list(t_node *head)
{
	t_node	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		ft_printf("%d[%d] -> ", curr->data, curr->index);
		curr = curr->next;
		if (curr == NULL)
			ft_printf("NULL");
	}
	ft_printf("\n");
	return ;
}

void	stk_free(t_stack *stack)
{
	t_node	*curr;
	t_node	*next;

	if (!stack)
		return ;
	curr = stack->first;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->first = NULL;
	stack->last = NULL;
	stack->size = 0;
	free(stack);
}

t_stack	*stk_init(void)
{
	t_stack	*stk;

	stk = ft_calloc(1, sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->first = NULL;
	stk->last = NULL;
	stk->size = 0;
	return (stk);
}

void	stk_normalize(t_stack *stk)
{
	t_node	*cur;
	t_node	*tmp;
	int		rank;

	if (!stk || !stk->first)
		return ;
	cur = stk->first;
	while (cur)
	{
		rank = 0;
		tmp = stk->first;
		while (tmp)
		{
			if (tmp->data < cur->data)
				rank++;
			tmp = tmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

int	check_sorted(t_stack *stk)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stk->first;
	while (curr != NULL)
	{
		if (curr->index != i)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}
