/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:05:08 by akechedz          #+#    #+#             */
/*   Updated: 2025/10/09 14:23:42 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*element;

	while (lst)
	{
		element->next;
		count++;
	}
	return (count);
}
/*	Counts the number of nodes in the list.*/
/*	Returns the length of the list.*/