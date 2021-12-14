/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly_mad_prob.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:32:16 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/14 20:32:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "string.h"
#include <ctime>
#include <cmath>

int	N = 19;
int	p = 23;
int a;
int b;
int A;

long long ft_hash(const char *str, int n)
{
	if (!str || !n)
		return (0);
	return (*str + A * ft_hash(str - 1, --n));
}


int	ft_compress(long long hash)
{
	return (((a * hash + b) % p) % N);
}

/*
 * Pass a as the first arguments, strings as the rest
 */
int	main(int argc, char **argv)
{
	srand(time(0));
	a = rand() % p;
	b = rand() % (p - 1) + 1;
	if (argc > 2)
	{
		A = std::stoi(argv[1]);
		std::cout << "A is initialized to " << A << std::endl;
		std::cout << "a is initialized to " << a << std::endl;
		std::cout << "b is initialized to " << b << std::endl;
		std::cout << "p is initialized to " << p << std::endl;
		std::cout << "N is initialized to " << N << std::endl;
		int	i = 2;
		while (i < argc)
		{
			long long	hash = ft_hash(argv[i] + strlen(argv[i]) - 1, strlen(argv[i]));
			std::cout << argv[i++] << "'s hash code is " << hash << ", it's compressed to " << ft_compress(hash) << std::endl << std::endl;
		}
		std::cout << "get(\"J\") compressed to " << ft_compress(ft_hash("J" + strlen("J") - 1, strlen("J"))) << std::endl;
	}
}
