/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:57:57 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/27 21:36:44 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"
#include "../s_list.hpp"

int	main(int argc, char **argv)
{
	int			i;
	int			val;
	s_list<int>	*a;
	
	a = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		val = ft_atoi(argv[i]);
		if (!ft_isdigitstr(argv[i]) || (val < 0 || val > 99999999))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		ft_lstadd<int>(&a, val);
		i--;	
	}
	a = ft_lsthybrid_sort<int>(&a);
	ft_lstprint<int>(a);
}
