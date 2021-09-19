/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_step.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:21 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 18:30:22 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stepper.hpp"

int	ft_check_step(int *arr, int arr_size)
{
	int	i;
	int	even;

	i = 0;
	even = 0;
	while (i < arr_size - 1)
	{
		if (!(arr[i] - arr[i + 1] % 2))
			even++;
		if (even && arr[i] - arr[i + 1] % 2)
			return (0);
		i++;
	}
	return (1);
}
