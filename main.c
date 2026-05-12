# include <stdlib.h>
# include <stdio.h>
# include "push_swap.h"
# include "libft/libft.h"

// ./push_swap 2 1 3 6 5 8  
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
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
	b = stk_init();
	if (!b)
	{
		stk_free(a);
		return (ft_printf("Error\n"), 1);
	}
	k_sort(a, b);
	//print_list(b->first);
	//ft_printf("B_SIZE=%d\n", b->size);
	reintegrate(a, b);
	print_list(a->first);
	ft_printf("A_SIZE=%d\n", a->size);
	stk_free(a);
	stk_free(b);
	return (0);
}

/*
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
*/

/*
int	main2(int argc, char **argv)
{
  t_stack	*a;
  t_stack	*b;

  stk_init(a);  
  if (!parse_args(argc, argv, a))
	{
		stk_free(a);
		//stk_free(b);
		return (ft_printf("Error\n"), 1);
	}
  //stk_init(b);
 	print_list(a->first);
  ft_printf("A_SIZE=%d", a->size);
  */
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
//  }
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