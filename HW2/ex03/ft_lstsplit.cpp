/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:54:59 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:21:33 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

/*
 * `result[0]` is always the even list;
 * `result[1]` is always the odd list
 */
t_list	**ft_lstsplit(t_list **head)
{
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
	while (curr)
	{
		next_node = curr->next;
		if (curr->data % 2 == 0)
			ft_lstadd_back(&result[0], curr);
		else
			ft_lstadd_back(&result[1], curr);
		curr->next = NULL;
		curr = next_node;
	}
	return (result);
}
