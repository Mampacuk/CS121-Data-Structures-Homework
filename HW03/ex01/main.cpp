/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:14:47 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/20 17:15:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

void	ft_remove_dupes(ArrayVector<int> &vector);

// TODO: a checking method that uses iterators and returns true if is sorted
// bool	ft_issorted()

/*
 * Pass the numbers from command line!
 */
int	main(int, char **argv)
{
	int					val;
	ArrayVector<int>	seq1;
	NodeList<int>		seq2;

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
		argv++;	
	}
	ft_remove_dupes(seq1);
	seq1.print();
}
