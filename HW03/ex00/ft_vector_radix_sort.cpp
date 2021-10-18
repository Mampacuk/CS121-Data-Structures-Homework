/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_radix_sort.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:41:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/18 20:49:21 by aisraely         ###   ########.fr       */
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
			selected = vector[0] / ft_recursive_power(10, i) % 10;
			std::cout << "selected " << selected << std::endl;
			std::cout << "inserted the element " << vector[0] << " into " << buckets[selected].size() << std::endl;
			buckets[selected].insert(buckets[selected].size(), vector[0]);
			std::cout << "successfull insertion!" << std::endl;
			vector.erase(0);
		}
		std::cout << "buckets now:" << std::endl;
		for (int z = 0; z < 10; z++)
		{
			std::cout << "bucket " << z << ":" << std::endl;
			buckets[z].print();
		}
		j = 0;
		while (j < 10)
		{
			while (!buckets[j].empty())
			{
				vector.insert(vector.size(), buckets[j][0]);
				buckets[j].erase(0);
			}
			j++;
		}
		std::cout << "vector now:" << std::endl;
		vector.print();
		i++;
	}
}
