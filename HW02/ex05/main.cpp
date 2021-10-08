/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:38:00 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 14:35:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ArrayStack.hpp"
#include "../../libft/libft.hpp"

template <typename D>
void	ft_reverse_stack(IStack<D> &a);

/*
 * Pass the numbers from command line! (the capacity is 100, by default)
 */
int	main(int, char **argv)
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
	std::cout << "The input stack is:" << std::endl;
	stack.print();
	ft_reverse_stack(stack);
	std::cout << "The output stack is:" << std::endl;
	stack.print();
}
