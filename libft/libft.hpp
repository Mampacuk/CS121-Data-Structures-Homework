/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:37:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 13:46:50 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <cmath>
# include <algorithm>

# include <stdio.h>
# include <stdlib.h>

# include "IQueue.hpp"
# include "IDeque.hpp"
# include "IStack.hpp"

# include "ArrayVector.hpp"
# include "List.hpp"
# include "LinkedBinaryTree.hpp"
# include "UnsortedPriorityQueue.hpp"

int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(char **s1, char **s2);
int		ft_atoi(const char *str);
int		ft_isdigitstr(char *str);
int		ft_recursive_power(int nb, int power);

#endif
