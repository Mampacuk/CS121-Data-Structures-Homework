/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 13:31:49 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 13:31:49 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "triangle.hpp"

void	ft_wrap_ft_draw_triangle(int height)
{
	ft_draw_triangle(height - 1, height * 2 - 2, height);
}

int	main(void)
{
	ft_wrap_ft_draw_triangle(3);	
	std::cout << "ft_draw_triangle(1):" << std::endl;
	ft_wrap_ft_draw_triangle(1);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(2):" << std::endl;
	ft_wrap_ft_draw_triangle(2);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(3):" << std::endl;
	ft_wrap_ft_draw_triangle(3);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(4):" << std::endl;
	ft_wrap_ft_draw_triangle(4);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(5):" << std::endl;
	ft_wrap_ft_draw_triangle(5);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(6):" << std::endl;
	ft_wrap_ft_draw_triangle(5);
	std::cout << "__________________________________________" << std::endl;
	std::cout << "ft_draw_triangle(100):" << std::endl;
	ft_wrap_ft_draw_triangle(100);
}