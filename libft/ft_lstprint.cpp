/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:52:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 15:52:13 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	if (!lst)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	curr = lst;
	while (curr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}
