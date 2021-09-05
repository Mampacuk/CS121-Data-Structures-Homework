/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_maze.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:12 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 17:34:12 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mazewalker.hpp"

int	ft_traverse_maze(t_maze map, int i, int j)
{
	if (i >= map.height || i < 0 || j >= map.width || j < 0
		|| map.mtx[i][j] == 'X')
		return (0);
	if (map.mtx[i][j] == 'E')
		return (1);
	map.mtx[i][j] = 'X';
	return (ft_traverse_maze(map, i - 1, j)
		+ ft_traverse_maze(map, i + 1, j)
		+ ft_traverse_maze(map, i, j - 1)
		+ ft_traverse_maze(map, i, j + 1));
}