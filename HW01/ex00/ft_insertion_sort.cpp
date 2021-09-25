/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 17:39:10 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.hpp"

static void	ft_insert_element(char **arr, char **head)
{
	if (!arr || !(*arr) || !head || !(*head) || arr == head)
		return ;
	if (ft_strcmp(*(arr - 1), *arr) > 0)
		ft_swap(arr, arr - 1);
	else
		return ;
	ft_insert_element(arr - 1, head);
}

void	ft_insertion_sort(char **arr, char **head)
{
	if (!arr || !(*arr) || !head || !(*head))
		return ;
	ft_insert_element(arr, head);
	ft_insertion_sort(arr + 1, head);
}
