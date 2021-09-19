/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_triangle.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:31:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 13:31:02 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.hpp"

void	ft_putchar(int i, int j, int height)
{
	if (i == height - 1)
		std::cout << '*';
	else
	{
		if (j == height - 1 + i || j == height - 1 - i)
			std::cout << '*';
		else
			std::cout << ' ';
	}
	if (j == height * 2 - 2)
		std::cout << std::endl;
}

/*
 * The function is to be called as follows:
 * i		= (height - 1)
 * j		= (height * 2 - 2)
 * height	= height
 */
void	ft_draw_triangle(int i, int j, int height)
{
	if (i < 0)
		return ;
	if (j <= 0)
		ft_draw_triangle(i - 1, height * 2 - 2, height);
	else
		ft_draw_triangle(i, j - 1, height);
	ft_putchar(i, j, height);
}
