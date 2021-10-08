/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:38:00 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 13:46:02 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayStack.hpp"

/*
 * Pass the numbers from command line! (the capacity is 100, by default)
 */
int	main(int argc, char **argv)
{
	ArrayStack<int>	stack;

	argv++;
	while (*argv)
	{
		if (!ft_isdigitstr(*argv))
		{
			std::cout << "Invalid input" << std::endl;
			return (1);
		}
		stack.push(ft_atoi(*argv));
		argv++;
	}
	ft_reverse_stack(stack);
	stack.print();
}