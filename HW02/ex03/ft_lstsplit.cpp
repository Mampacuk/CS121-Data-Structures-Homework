/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:54:59 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 14:47:40 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

/*
 * `result[0]` is always the odd list;
 * `result[1]` is always the even list
 */
t_list	**ft_lstsplit(t_list **head)
{
	int		i;
	t_list	**result;
	t_list	*curr;
	t_list	*next_node;

	if (!head)
		return (NULL);
	result = new t_list *[2];
	/*
	 * If a head is empty, then there was no odd/even
	 * members in the list, and it's NULL
	 */
	result[0] = NULL;
	result[1] = NULL;
	curr = *head;
	i = 0;
	while (curr)
	{
		next_node = curr->next;
		if (i % 2 != 0)
			ft_lstadd_back(&result[0], curr);
		else
			ft_lstadd_back(&result[1], curr);
		curr->next = NULL;
		curr = next_node;
		i++;
	}
	return (result);
}
