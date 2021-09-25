/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:39:22 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 14:46:39 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.hpp"

int	main(void)
{
	int		n;
	char	*buf;
	char	**mtx1;
	char	**mtx2;

	std::cout << "TEST00: SELECTION SORT" << std::endl;
	std::cout << "PLEASE INPUT THE NUMBER OF STRINGS: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	mtx1 = new char *[n + 1];
	for (int i = 0; i < n; i++)
	{
		buf = new char[BUFSIZ];
		std::cin >> buf;
		mtx1[i] = strdup(buf);
		delete [] buf;
	}
	mtx1[n] = NULL;
	ft_selection_sort(mtx1);
	std::cout << "THE RESULT:" << std::endl;
	for (int i = 0; mtx1[i]; i++)
	{
		std::cout << mtx1[i] << std::endl;
		free(mtx1[i]);
	}
	delete [] mtx1;
	
	std::cout << "TEST01: INSERTION SORT" << std::endl;
	std::cout << "PLEASE INPUT THE NUMBER OF STRINGS: ";
	std::cin >> n;
	if (std::cin.fail() || n < 1)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	mtx2 = new char *[n + 1];
	for (int i = 0; i < n; i++)
	{
		buf = new char[BUFSIZ];
		std::cin >> buf;
		mtx2[i] = strdup(buf);
		delete [] buf;
	}
	mtx2[n] = NULL;
	ft_insertion_sort(mtx2, mtx2);
	std::cout << "THE RESULT:" << std::endl;
	for (int i = 0; mtx2[i]; i++)
	{
		std::cout << mtx2[i] << std::endl;
		free(mtx2[i]);
	}
	delete [] mtx2;
}