/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:14:20 by akechedz          #+#    #+#             */
/*   Updated: 2026/10/29 06:02:45 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = stk_init();
	if (!a)
		return (1);
	if (!parse_args(argc, argv, a))
		return (stk_free(a), ft_printf("Error\n"), 1);
	if (check_sorted(a))
		return (stk_free(a), 0);
	b = stk_init();
	if (!b)
		return (stk_free(a), ft_printf("Error\n"), 1);
	if (a->size < 7)
		mini_sort(a, b);
	else
		k_sort(a, b);
	reintegrate(a, b);
	stk_free(a);
	stk_free(b);
	return (0);
}
