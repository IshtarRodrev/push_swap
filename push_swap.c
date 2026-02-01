/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:23:33 by akechedz          #+#    #+#             */
/*   Updated: 2026/01/30 20:11:46 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h> //FIXME

/* void	push_swap()
{
	//the magic;
	//https://pythontutor.com/visualize.html#mode=edit
	//https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376
	//https://www.google.com/search?q=push+swap+ksort&sca_esv=a87a460474998c14&udm=50&fbs=ADc_l-YGrpJMQtvjQ6h14rj-dfIrH4mwN5r0Z1FZtFNB2w3Upe2HDPC6akWpYUJBWeXXRd1nD-EOaE0XinGd5KvoJHG8OW6hbPG5HGkmH5eSOG4TMBnyznkwl4rk7eTLPmGiiMXA5VY9M9TuEf30xK4inDhkSZpsG7LKn-gYXluNSgL4chfqr1ROt-6fxN4aMa1bK4-MNo7i&aep=1&ntc=1&sa=X&ved=2ahUKEwjQoqPq3K6SAxXK5QIHHWcdEVUQ2J8OegQICRAD&biw=2663&bih=1297&dpr=1&aic=0&mstk=AUtExfDtognJwVWGkKvQQlQCGVZoGPYfdpx7o5VD0dJh4EdPIt1tGMJZQrxkicIJ5BM7no-Xu_YlcPMl9ruPdBgbKde30pYb2dzfj8IVLqqKvbmGhz26ohjHq6Ylz3TiOh9m0x_BnIBAIg8l-kaymlE3mYP5SbeJzJQsS5c&csuir=1
} */
void	k_sort(t_stack *a, t_stack *b) //FIXME: this is pseudocode
{
	int	n;
	int	delta;
	int	threshold;

	n = a->size;
	delta = n / 20 + 7;
	threshold = 0;
	while (!a->first && !a->last)
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
	/*
	echo "pb\npb\npb\nrrb\npa\nrrb\npa\npa" | ./checker_linux 3 2 1 
	echo "pb\npb\npb\nrrb\npa\nrrb\npa\npa" | ./misc/checker_linux 3 2 1
	*/
}

t_node	*new_node(int num)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->data = num;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

int	check_stack(t_stack *stack, int new_data)
{
	t_node	*tmp;

	tmp = stack->last;
	while (tmp->prev)
	{
		if (tmp->data == new_data)
			return (0);
		tmp = tmp->prev;
	}
	ft_printf("Error");
	return (1);
}

t_stack	*fill_stack(t_stack *stack, int new_data)
{
	t_node	*element;

	element = new_node(new_data);
	if (!stack->first)
	{
		element->next = NULL;
		element->prev = NULL;
		/*element->next = element->prev;// looping*/
		stack->first = element;
		stack->last = element;
	}
	else if (!check_stack(stack, new_data))
		return (stack);
	else
	{
		// t_node *last = head->prev; 
		element->next = stack->first;
		element->next->prev = element;
		element->prev = NULL;
		stack->first = element;
		// stack->last->next = NULL;
		stack->first = element;
	}
	return (stack);
}

/* 
int	ft_atoi(const char *str)
{
	int	neg;
	int	result;

	neg = 0;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ' )
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - 48);
		str++;
	}
	if (result > INT_MAX)
		result = INT_MAX;
	if (neg == 1)
		result *= -1;
	return (result);
}
*/

void	print_list(t_node *head)
{
	t_node	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		ft_printf("%d ", curr->data);
		curr = curr->next;
		if (curr == head)
			break ;
	}
	ft_printf("\n");
	return ;
}

int	check_digits(char *checkme)
{
	int	i;

	i = 0;
	if (checkme[i] == '-')
		i++;
	if (checkme[i] == '\0')
		return (0);
	while (checkme[i])
	{
		if (!ft_isdigit(checkme[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)//TODO: rename this func to push_swap
{	
	t_stack	*a;
	t_stack	*b;
	int		num;

	a = calloc(1, sizeof(t_stack));
	if (!a)
		return (1);
	b = calloc(1, sizeof(t_stack));
	if (!b)
		return (1);
	a->size = argc;
	while (argc > 1)
	{
		argc--;
		if (!check_digits(argv[argc]))
			return (ft_printf("Error"), 0);
		num = ft_atoi(argv[argc]);
		ft_printf(">%d\n", num);
		fill_stack(a, num);
	}
	// b->first = NULL;
/* 	print_list(a->first);
	pa(a, b);
	pa(a, b);
	print_list(a->first);
	pa(a, b);
	print_list(a->first);
	ra(a);
	print_list(a->first);
	print_list(a->first);
	print_list(b->first); */
	k_sort(a, b);
	return (0);
}
/*
sa()
{
	// sa (swap a): Swap the first 2 elements at the top of stack a.
	// Do nothing if there is only one element or none.
}

sb()
{
	// sb (swap b): Swap the first 2 elements at the top of stack b.
	// Do nothing if there is only one element or none.
}

ss()
{
	// ss : sa and sb at the same time.
}

pa()
{
	// pa (push a): Take the first element at the top of b and put it at the top of a.
	// Do nothing if b is empty.
}

pb()
{
	// pb (push b): Take the first element at the top of a and put it at the top of b.
	// Do nothing if a is empty.
}

ra()
{
	// ra (rotate a): Shift up all elements of stack a by 1.
	// The first element becomes the last one.
}
rb()
{
	// rb (rotate b): Shift up all elements of stack b by 1.
	// The first element becomes the last one.
}
rr()
{
	// rr : ra and rb at the same time.
}

rra()
{
	// rra (reverse rotate a): Shift down all elements of stack a by 1.
	// The last element becomes the first one.
}
rrb()
{
	// rrb (reverse rotate b): Shift down all elements of stack b by 1.
	// The last element becomes the first one.
}
rrr()
{
	// rrr : rra and rrb at the same time.
}
*/
/*
• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random number of unique negative and/or positive
integers.
◦ The stack b is empty.
• The goal is to sort the numbers in stack a in ascending order. To achieve this, you
have the following operations at your disposal:
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time. */
// TODO: NORMALISE DATA!!!