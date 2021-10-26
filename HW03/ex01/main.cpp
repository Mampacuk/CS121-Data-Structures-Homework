/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:14:47 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 19:21:00 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_remove_dupes(ArrayVector<int> &vector);
void	ft_remove_dupes(List<int> &list);

/*
 * Pass the numbers from command line!
 */
int	main(int, char **argv)
{
	int					val;
	ArrayVector<int>	seq1;
	List<int>			seq2;

	argv++;
	while (*argv)
	{
		val = ft_atoi(*argv);
		if (!ft_isdigitstr(*argv))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		seq1.insert(seq1.size(), val);
		seq2.insertBack(val);
		argv++;	
	}
	std::cout << "ft_remove_dupes(ArrayVector<int>&):" << std::endl;
	ft_remove_dupes(seq1);
	seq1.print();

	std::cout << std::endl << "ft_remove_dupes(List<int>&):" << std::endl;
	ft_remove_dupes(seq2);
	seq2.print();
}
