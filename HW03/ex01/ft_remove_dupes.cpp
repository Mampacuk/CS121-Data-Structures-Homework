/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_dupes.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:20:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 19:30:40 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_remove_dupes(ArrayVector<int> &vector)
{
	int					i;
	ArrayVector<int>	container;

	if (vector.size() < 2)
		return ;
	container.insert(0, vector[0]);
	i = 1;
	while (i < vector.size())
	{
		if (vector[i - 1] != vector[i])
			container.insert(container.size(), vector[i]);
		i++;
	}
	while (!vector.empty())
		vector.erase(vector.size() - 1);
	i = 0;
	while (i < container.size())
		vector.insert(vector.size(), container[i++]);
}

void	ft_remove_dupes(List<int> &list)
{
	List<int>::Iterator curr = list.begin();

	if (list.size() < 2)
		return ;
	while (curr != --list.end())
	{
		List<int>::Iterator	curr_copy(curr);
		List<int>::Iterator	curr_next(++curr);
		if (*curr_copy == *curr_next)
			list.erase(curr_copy);
	}
}
