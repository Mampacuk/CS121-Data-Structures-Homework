/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:56:55 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:21:47 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

t_list	*ft_lstmerge(t_list **lst1, t_list **lst2)
{
	t_list	*head;
	t_list	*tail;
	t_list	*curr1;
	t_list	*curr2;
	
	if (!lst1 || !lst2)
		return (NULL);
	/*
	 * If one of the lists is empty, then it's
	 * trivially sorted 
	 */
	if (!(*lst1))
		return (*lst2);
	if (!(*lst2))
		return (*lst1);
	/*
	 * Check which one of the lists to take as the head
	 * to build on
	 */
	if ((*lst1)->data < (*lst2)->data)
	{
		head = (*lst1);
		/*
		 * If it doesn't have any other elements, then
		 * just make it point to the head of the other
		 * list and return (in `else` of this branch)
		 */
		if (head->next)
		{
			/*
			 * Should we relink the head to the other list
			 * (if), or continue building atop the selected
			 * one (else)?
			 */
			if ((*lst2)->data < head->next->data)
			{
				curr1 = head->next;
				curr2 = (*lst2)->next;
				head->next = (*lst2);
			}
			else
			{
				curr1 = head->next->next;
				curr2 = (*lst2);
				tail = head->next;
			}
		}
		else
		{
			head->next = (*lst2);
			return (head);
		}
	}
	/*
	 * Is symmetric to the previous branch
	 */
	else
	{
		head = (*lst2);
		if (head->next)
		{
			if (head->next && (*lst1)->data < head->next->data)
			{
				curr1 = (*lst1)->next;
				curr2 = head->next;
				head->next = (*lst1);
			}
			else
			{
				curr1 = (*lst1);
				curr2 = head->next->next;
				tail = head->next;
			}
		}
		else
		{
			head->next = (*lst1);
			return (head);
		}
	}
	tail = head->next;
	while (curr1 && curr2)
	{
		if (curr1->data < curr2->data)
		{
			tail->next = curr1;
			curr1 = curr1->next;
		}
		else
		{
			tail->next = curr2;
			curr2 = curr2->next;
		}
		tail = tail->next;
	}
	if (!curr1)
		tail->next = curr2;
	else if (!curr2)
		tail->next = curr1;
	return (head);
}
