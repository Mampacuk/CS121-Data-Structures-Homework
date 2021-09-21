/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:22:48 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 20:27:46 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

/*
 * Pass the numbers from command line!
 */
int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	
	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!ft_isdigitstr(argv[i]))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		ft_lstadd_back(&a, ft_atoi(argv[i]));
		i++;	
	}
	a = ft_lstmerge_sort(&a);
	ft_lstprint(a);
}
