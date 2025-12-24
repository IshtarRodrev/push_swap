/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:23:33 by akechedz          #+#    #+#             */
/*   Updated: 2025/12/24 02:53:19 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "push_swap.h"
/*
	push_swap()
{
	//the magic;
	//https://pythontutor.com/visualize.html#mode=edit
}
*/
t_node	*new_node(int num)
{
	t_node	*element;

	element = malloc(sizeof(t_node));
	if (!element)
		return (NULL);
	element->data = num;
	element->next = NULL;
	element->prev = NULL;
/* 	
	NOT hier!!!!
	element->prev = NULL;
	element->next = element->prev;// looping*/
	return (element);
}

t_stack	*fill_stack(t_stack *stack, int new_data)
{
    t_node *n_node;
	
	n_node = new_node(new_data);
    if (!stack->first)
    {
        n_node->next = n_node->prev = NULL;
        stack->first = n_node;
    }
    else 
    {
        // List is not empty
        // t_node *last = head->prev; 

        // Insert new node
        n_node->next = stack->first;
        n_node->prev = NULL;
        stack->first = n_node;
        stack->last->next = NULL;
        
        // Update head
        stack->first = n_node;
    }
    
    return stack;
}

void	print_list(t_node *head)
{
	t_node	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
		if (curr == head)
			break ;
	}
	printf("\n");
	return ;
}

int	main(int argc, char **argv)
{	t_stack *a;
	t_stack *b;
	int		num;
	
	int i = argc;
	printf(">>%d\n", argc);
	while (argv[i])
	{
		i--;
			printf(">%s\n", argv[i]);
		// num = atoi(argv[i]);
		// a = fill_stack(a, num);
	}
	// b = NULL;
	// print_list(a->first);
	return (1);
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
