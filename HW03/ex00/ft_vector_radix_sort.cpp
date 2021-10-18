/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_radix_sort.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:41:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/18 19:41:08 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

template <typename D>
void	ft_vector_radix_sort(ArrayVector<D> &vector)
{
	int	i;
	int	j;
	int	selected;

	i = 0;
	while (i < 6)
	{
		ArrayVector<D>	buckets[6];
		
		j = 0;
		while (j < vector.size())
		{
			selected = vector[j] / ft_recursive_power(10, i) % 10;
			buckets[selected].insert(buckets[selected].size(), vector[j]);
			vector.erase(j);
			j++;
		}
		j = 0;
		while (j < 6)
		{
			for (int k = 0; k < buckets[k].size(); k++)
				vector.insert(vector.size(), buckets[j][k]);
			j++;
		}
		i++;
	}
}
