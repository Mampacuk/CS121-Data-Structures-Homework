/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mazewalker.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:21 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 17:34:21 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAZEWALKER_HPP
# define MAZEWALKER_HPP

# include <iostream>
# include <cstring>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

typedef struct s_maze
{
	char	**mtx;
	int		width;
	int		height;
}				t_maze;

int	ft_traverse_maze(t_maze map, int i, int j);

#endif