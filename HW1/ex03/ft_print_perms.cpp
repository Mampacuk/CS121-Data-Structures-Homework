/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perms.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:53:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/05 11:53:07 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perms.hpp"

/*
 * Convert enum to string for concatenation 
 */
std::string	ft_convert_character(e_set val)
{
	std::string	character;

	if (val == a)
		character = "a";
	else if (val == b)
		character = "b";
	else if (val == c)
		character = "c";
	else if (val == d)
		character = "d";
	else if (val == e)
		character = "e";
	return (character);
}

/*
 * Find out whether the enum is a vowel 
 */
int	ft_isvowel(e_set val)
{
	return (val == a || val == e);
}

/*
 * Takes in the depth (length), the character to start with, and the base
 * (should be an empty string "" ideally) 
 */
void	ft_build_next_character(int depth, e_set selected, std::string base)
{
	/*
	 * Base case; no need to go deeper, just print the assembled string 
	 */
	if (depth <= 0 || selected < a || selected > d)
	{
		std::cout << base << std::endl;
		return ;
	}
	if (ft_isvowel(selected))
	{
		ft_build_next_character(depth - 1, b, base + ft_convert_character(selected));
		/*
		 * Go deeper if it's not the last node 
		 */
		if (depth - 1)
		{
			ft_build_next_character(depth - 1, c, base + ft_convert_character(selected));
			ft_build_next_character(depth - 1, d, base + ft_convert_character(selected));
		}
	}
	else
	{
		ft_build_next_character(depth - 1, a, base + ft_convert_character(selected));
		/*
		 * Go deeper if it's not the last node 
		 */
		if (depth - 1)
			ft_build_next_character(depth - 1, e, base + ft_convert_character(selected));
	}
}

/*
 * Prints result for each character with appropriate empty base 
 */
void	ft_print_perms(int n)
{
	std::string	base;
	
	base = "";
	ft_build_next_character(n, a, base);
	ft_build_next_character(n, b, base);
	ft_build_next_character(n, c, base);
	ft_build_next_character(n, d, base);
	ft_build_next_character(n, e, base);
}