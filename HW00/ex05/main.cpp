/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:33 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 17:34:33 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mazewalker.hpp"

int	ft_count_exits(char *row)
{
	int	count;

	count = 0;
	for (int i = 0; row[i]; i++)
		if (row[i] == 'E')
			count++;
	return (count);
}

/*
 * Check for allowed characters 
 */
int	ft_ismaprow(char *row)
{
	for (int i = 0; row[i]; i++)
		if (!(row[i] == '.' || row[i] == 'X' || row[i] == 'E'))
			return (0);
	return (1);
}

int	main(void)
{
	int		starti;
	int		startj;
	t_maze	map;
	char	*buf;
	int		exits;

	exits = 0;
	std::cout << "Enter map height: ";
	std::cin >> map.height;
	if (std::cin.fail() || map.height < 1)
	{
		std::cout << "Invalid height" << std::endl;
		return (1);
	}
	std::cout << "Enter map width: ";
	std::cin >> map.width;
	if (std::cin.fail() || map.height < 1)
	{
		std::cout << "Invalid width" << std::endl;
		return (1);
	}
	std::cout << "Enter starting point i (row): ";
	std::cin >> starti;
	if (std::cin.fail() || starti < 0 || starti >= map.height)
	{
		std::cout << "Invalid starting point i" << std::endl;
		return (1);
	}
	std::cout << "Enter starting point j (column): ";
	std::cin >> startj;
	if (std::cin.fail() || startj < 0 || startj >= map.width)
	{
		std::cout << "Invalid starting point j" << std::endl;
		return (1);
	}
	map.mtx = new char *[map.height];
	for (int i = 0; i < map.height; i++)
	{
		// std::cout << "Enter line " << i << ":" << std::endl;
		buf = new char[BUFSIZ];
		std::cin >> buf;
		if (!ft_ismaprow(buf) || std::cin.fail() || strlen(buf) != (size_t) map.width)
		{
			std::cout << "Invalid map row" << std::endl;
			return (1);
		}
		map.mtx[i] = strdup(buf);
		exits += ft_count_exits(buf);
		delete [] buf;
	}
	if (exits != 1)
	{
		std::cout << "Invalid number of exits" << std::endl;
		return (1);
	}
	if (map.mtx[starti][startj] == 'X')
	{
		std::cout << "Can't start in a wall" << std::endl;
		return (1);
	}
	if (ft_traverse_maze(map, starti, startj))
		std::cout << KGRN << "Yes" << KNRM << std::endl;
	else
		std::cout << KRED << "No" << KNRM << std::endl;
}