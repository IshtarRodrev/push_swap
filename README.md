*This project has been created as part of the 42 curriculum by akechedz*
# push_swap
This project focuses on sorting data within a stack using a restricted set of operations. The challenge lies in minimizing the number of actions required to achieve a fully sorted stack. To accomplish this, various algorithms are explored and applied, with the goal of selecting the most efficient approach for optimized data sorting.
# Description
A “Description” section that clearly presents the project, including its goal and a
brief overview.
# Instructions
An “Instructions” section containing any relevant information about compilation,
installation, and/or execution.
Create main.c in the push_swap directory. The code is provided below.

	###main.c

	```C
# include <stdlib.h>
# include <stdio.h>
# include "push_swap.h"

int	main(void) // hardcoded values
{
	//t_node	value = {123, NULL, NULL};
	t_node	*head = NULL;
	t_node	*tmp = NULL;
	t_stack	st;

	head = calloc(1, sizeof(t_node));
	head->data = 10;
	tmp = calloc(1, sizeof(t_node));
	tmp->data = 20;

	head->next = tmp;
	tmp->prev = head;

	st.first = head;
	st.last = tmp;

	sa(&st);
}
	```
	```C
int	main(int argc, char **argv) // input values
{
	t_stack	*a;
	t_stack	*b;
	int		num;

	a = calloc(1, sizeof(t_stack));
	if (!a)
		return (0);
	b = calloc(1, sizeof(t_stack));
	if (!b)
		return (0);
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
	push_swap(a, b);
	return (1);
}
```
# Resources
• A “Resources” section listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/
https://pythontutor.com/visualize.html#mode=edit
https://push-swap42-visualizer.vercel.app/
# Additional
Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below