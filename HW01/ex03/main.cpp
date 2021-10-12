/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:22:48 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/27 21:35:39 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"
#include "../s_list.hpp"

/*
 * Pass the numbers from command line!
 */
int	main(int argc, char **argv)
{
	int			i;
	s_list<int>	*a;
	
	a = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		if (!ft_isdigitstr(argv[i]))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		ft_lstadd<int>(&a, ft_atoi(argv[i]));
		i--;	
	}
	a = ft_lstmerge_sort<int>(&a);
	ft_lstprint<int>(a);
}
