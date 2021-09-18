/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 17:39:29 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_HPP
# define SORTING_HPP

# include <stdlib.h>
# include <iostream>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_selection_sort(char **arr);
void	ft_insertion_sort(char **arr, char **head);

#endif