/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:25:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/18 19:53:54 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_vector_radix_sort(ArrayVector<int> &vector);

/*
 * Pass the numbers from command line!
 */
int	main(int, char **argv)
{
	int					i;
	int					val;
	ArrayVector<int>	seq;

	i = 0;
	argv++;
	while (*argv)
	{
		val = ft_atoi(*argv);
		if (!ft_isdigitstr(*argv) || val < 0 || val > 999999)
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		seq.insert(i, val);
		i++;
		argv++;	
	}
	ft_vector_radix_sort(seq);
	seq.print();
}
