/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selection_sort.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:12 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 17:39:13 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.hpp"

static char	**ft_select_smallest(char **arr, char **smallest)
{
	if (!smallest || !*(smallest))
		return (NULL);
	if (!arr || !(*arr))
		return (smallest);
	if (ft_strcmp(*arr, *smallest) < 0)
		smallest = arr;
	return (ft_select_smallest(arr + 1, smallest));
}

void	ft_selection_sort(char **arr)
{
	if (!arr || !(*arr))
		return ;
	ft_swap(arr, ft_select_smallest(arr, arr + 1));
	ft_selection_sort(arr + 1);
}
