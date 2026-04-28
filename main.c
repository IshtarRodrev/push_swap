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
// 		adjust_stack(a, num);
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
/* 
# include <stdlib.h>


int main()
{
  t_node value = {123, NULL, NULL};
  t_node *head = NULL;
  t_node *tmp = NULL;

  head = calloc(1, sizeof(t_node));
  head->data = 10;
  tmp = calloc(1, sizeof(t_node));
  tmp->data = 20;
  
  head->next = tmp;
  tmp->prev = head;
  
  t_stack st;
  
  st.first = head;
  st.last = tmp;
  
  swap(&st);
}

int main2()
{
  t_node value = {123, NULL, NULL};
  value.data = 19;

  t_node *n1 = NULL;
  t_node *n2 = NULL;
  t_node *n3 = NULL;

  n1 = calloc(1, sizeof(t_node));
  n1->data = 10;
  n2 = calloc(1, sizeof(t_node));
  n2->data = 20;
  n3 = calloc(1, sizeof(t_node));
  n3->data = 30;
  
  n1->next = n2;
  n2->prev = n1;
  
  n2->next = n3;
  n3->prev = n2;
  
  t_stack st;
  
  st.first = n1;
  st.last = n3;
  
  swap(&st);
}
*/