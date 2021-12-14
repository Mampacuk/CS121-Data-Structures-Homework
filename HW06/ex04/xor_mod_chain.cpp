/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:23:42 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/14 19:23:42 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int N = 13;

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	i = 1;
		while (i < argc)
		{
			int		result = 0;
			char	*str = argv[i];

			while (*str)
			{
				std::cout << "xored " << result << " with " << *str;
				result = result ^ *str;
				std::cout << ", result: " << result << std::endl;
				str++;
			}
			std::cout << "after compression: " << (result % N) << std::endl << std::endl;
			i++;
		}
	}
}
