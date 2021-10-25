/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_dupes.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:20:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 14:45:06 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_remove_dupes(ArrayVector<int> &vector)
{
	int	i;

	i = 0;
	while (i < vector.size() - 1)
		if (vector[i] == vector[i + 1])
			vector.erase(i);
		else
			i++;
}

void	ft_remove_dupes(List<int> &list)
{
	List<int>::Iterator curr = list.begin();

	if (list.size() > 0)
		while (curr != --list.end())
		{
			List<int>::Iterator	curr_copy(curr);
			List<int>::Iterator	curr_next(++curr);
			if (*curr_copy == *curr_next)
				list.erase(curr_copy);
		}
}
