/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_dupes.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:20:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/19 21:20:03 by aisraely         ###   ########.fr       */
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
