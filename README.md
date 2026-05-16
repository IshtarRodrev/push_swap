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
# include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stk_init();
	if (!a)
		return (1);
	if (!parse_args(argc, argv, a))
	{
		stk_free(a);
		//stk_free(b);
		return (ft_printf("Error\n"), 1);
	}
#ifdef DEBUG
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
#endif
	b = stk_init();
	if (!b)
	{
		stk_free(a);
		return (ft_printf("Error\n"), 1);
	}
	k_sort(a, b);
#ifdef DEBUG
	print_list(b->first);
	ft_printf("B_SIZE=%d\n", b->size);
#endif
	reintegrate(a, b);
#ifdef DEBUG
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
#endif
	stk_free(a);
	stk_free(b);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		num;

// 	a = calloc(1, sizeof(t_stack));
// 	if (!a)
// 		return (0);
// 	b = calloc(1, sizeof(t_stack));
// 	if (!b)
// 		return (0);
// 	while (argc > 1)
// 	{
// 		argc--;
// 		if (!check_digits(argv[argc]))
// 			return (ft_printf("Error"), 0);
// 		num = ft_atoi(argv[argc]);
// 		ft_printf(">%d\n", num);
// 		push_back_2_stk(a, num);
// 	}
// 	// b->first = NULL;
// 	/* 	print_list(a->first);
// 	pa(a, b);
// 	pa(a, b);
// 	print_list(a->first);
// 	pa(a, b);
// 	print_list(a->first);
// 	ra(a);
// 	print_list(a->first);
// 	print_list(a->first);
// 	print_list(b->first); */
// 	push_swap(a, b);
// 	return (1);
// }
```
# Resources
• A “Resources” section listing classic references related to the topic (documen-
tation, articles, tutorials, etc.), as well as a description of how AI was used —
specifying for which tasks and which parts of the project.
https://www.geeksforgeeks.org/dsa/insertion-in-doubly-circular-linked-list/
https://pythontutor.com/visualize.html#mode=edit
https://push-swap42-visualizer.vercel.app/
https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376
https://www.google.com/search?q=push+swap+ksort&sca_esv=a87a460474998c14&udm=50&fbs=ADc_l-YGrpJMQtvjQ6h14rj-dfIrH4mwN5r0Z1FZtFNB2w3Upe2HDPC6akWpYUJBWeXXRd1nD-EOaE0XinGd5KvoJHG8OW6hbPG5HGkmH5eSOG4TMBnyznkwl4rk7eTLPmGiiMXA5VY9M9TuEf30xK4inDhkSZpsG7LKn-gYXluNSgL4chfqr1ROt-6fxN4aMa1bK4-MNo7i&aep=1&ntc=1&sa=X&ved=2ahUKEwjQoqPq3K6SAxXK5QIHHWcdEVUQ2J8OegQICRAD&biw=2663&bih=1297&dpr=1&aic=0&mstk=AUtExfDtognJwVWGkKvQQlQCGVZoGPYfdpx7o5VD0dJh4EdPIt1tGMJZQrxkicIJ5BM7no-Xu_YlcPMl9ruPdBgbKde30pYb2dzfj8IVLqqKvbmGhz26ohjHq6Ylz3TiOh9m0x_BnIBAIg8l-kaymlE3mYP5SbeJzJQsS5c&csuir=1

# Additional
Additional sections may be required depending on the project (e.g., usage
examples, feature list, technical choices, etc.).
Any required additions will be explicitly listed below