/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge_sort_split.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 21:20:30 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:25:48 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

t_list	*ft_lstmerge_sort_split(t_list **head)
{
	t_list	**evenodd;

	evenodd = ft_lstsplit(head);
	evenodd[0] = ft_lstmerge_sort(&evenodd[0]);
	evenodd[1] = ft_lstmerge_sort(&evenodd[1]);
	return (ft_lstmerge(&evenodd[0], &evenodd[1]));
}
