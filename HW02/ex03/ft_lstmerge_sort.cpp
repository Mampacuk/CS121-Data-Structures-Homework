/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge_sort.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:06:38 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:21:55 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

t_list	*ft_lstmerge_sort(t_list **head)
{
	int		mid_index;
	t_list	*mid_node;
	t_list	*low;
	t_list	*high;

	if (!head)
		return (NULL);
	if (!(*head)->next)
		return (*head);
	mid_index = ft_lstsize(*head) / 2 - 1;
	mid_node = ft_lstfind(*head, mid_index);
	low = *head;
	high = mid_node->next;
	mid_node->next = NULL;
	low = ft_lstmerge_sort(&low);
	high = ft_lstmerge_sort(&high);
	return (ft_lstmerge(&low, &high));		
}