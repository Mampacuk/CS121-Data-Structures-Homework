/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:52:23 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 15:52:24 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = lst;
	while (curr)
	{
		curr = curr->next;
		i++;
	}
	return (i);
}