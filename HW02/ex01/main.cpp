/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:29 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 16:54:07 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stepper.hpp"

int	main(void)
{
	int	n;
	int	*arr;

	std::cout << "Input the array size: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	arr = new int[n];
	std::cout << "Now, input the elements:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		if (std::cin.fail())
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
	}
	if (!ft_check_step(arr, n))
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	std::cout << ft_find_step(arr, 0, n - 1, n) << std::endl;
}
