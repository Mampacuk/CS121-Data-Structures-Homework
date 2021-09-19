/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:52:29 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 15:53:36 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

t_list	*ft_lstnew(int data)
{
	t_list	*head;

	head = new t_list;
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}
