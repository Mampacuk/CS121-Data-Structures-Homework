/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:22:57 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 15:22:57 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.hpp"

void	ft_wrap_ft_draw_triangle(int height)
{
	ft_draw_triangle(height - 1, height * 2 - 2, height);
}

int	main(void)
{
	int	n;

	std::cout << "Enter the height of the triangle: ";
	std::cin >> n;
	if (std::cin.fail() || n <= 0)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	ft_wrap_ft_draw_triangle(n);
}