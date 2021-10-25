/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:25:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/25 17:06:11 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"
#include "DLLList.hpp"

void	ft_vector_radix_sort(DLLList<int> &vector);

/*
 * Pass the numbers from command line!
 */
int	main(int, char **argv)
{
	int				val;
	DLLList<int>	seq;

	argv++;
	while (*argv)
	{
		val = ft_atoi(*argv);
		if (!ft_isdigitstr(*argv) || val < 0 || val > 999999)
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		seq.insert(seq.size(), val);
		argv++;	
	}
	ft_vector_radix_sort(seq);
	seq.print();

	// DLLList<int>	copy_constructed(seq);
	// std::cout << "Copy constructor:" << std::endl;
	// copy_constructed.print();
	// DLLList<int>	assignator;
	// assignator.insert(0, 42);
	// assignator.insert(0, 42);
	// assignator.insert(0, 69);
	// seq = assignator;
	// std::cout << "Assignemnt:" << std::endl;
	// seq.print();
}
