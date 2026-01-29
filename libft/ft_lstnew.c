/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:56:38 by akechedz          #+#    #+#             */
/*   Updated: 2025/10/06 04:28:27 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}
/*	Allocates memory (using malloc(3)) and returns a new node. The ’content’ 
	member variable is initialized with the given parameter ’content’. 
	The variable ’next’ is initialized to NULL.*/
/*	create a new list node element in 4 steps:
	1. declaring the new list element
    2. allocating the memory for the new element
    3. setting the content of the new element to the 'content' parameter and 
	setting the 'next' to NULL
	4. finally, return the created element.*/