/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_radix_sort.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:41:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/19 20:24:15 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_vector_radix_sort(ArrayVector<int> &vector)
{
	int					i;
	int					j;
	int					selected;
	ArrayVector<int>	buckets[10];

	i = 0;
	while (i < 10)
	{
		while (!vector.empty())
		{
			selected = vector[vector.size() - 1] / ft_recursive_power(10, i) % 10;
			buckets[selected].insert(buckets[selected].size(), vector[vector.size() - 1]);
			vector.erase(vector.size() - 1);
		}
		j = 0;
		while (j < 10)
		{
			while (!buckets[j].empty())
			{
				vector.insert(vector.size(), buckets[j][buckets[j].size() - 1]);
				buckets[j].erase(buckets[j].size() - 1);
			}
			j++;
		}
		i++;
	}
}
