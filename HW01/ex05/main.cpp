/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:31:42 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/28 19:41:19 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

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
		if (!ft_isdigitstr(argv[i]) || (val < 0 || val > 999999))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		ft_lstadd<int>(&a, val);
		i--;	
	}
	a = ft_lstradix_sort<int>(&a);
	ft_lstprint<int>(a);
}
