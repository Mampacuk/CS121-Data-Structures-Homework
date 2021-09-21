/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge_sort.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:06:38 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 20:27:39 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

t_list	*ft_lstmerge_sort(t_list **head)
{
	t_list	**sublists;
	t_list	*merged;
	
	if (!head || !(*head))
		return (NULL);
	if (!(*head)->next)
		return (*head);
	sublists = ft_lstsplit(head);
	sublists[0] = ft_lstmerge_sort(&sublists[0]);
	sublists[1] = ft_lstmerge_sort(&sublists[1]);
	merged = ft_lstmerge(&sublists[0], &sublists[1]);
	delete [] sublists;
	return (merged);		
}