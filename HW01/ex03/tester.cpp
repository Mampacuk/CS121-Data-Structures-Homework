/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:55:08 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/25 20:04:23 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.hpp"

// int	main(void)
// {
// 	s_list	*a;
// 	s_list	*b;
// 	s_list	*c;
// 	a = NULL;
// 	b = NULL;
// 	ft_lstadd_back(&a, 0);
// 	ft_lstadd_back(&a, 2);
// 	ft_lstadd_back(&a, 8);
// 	ft_lstadd_back(&b, -1);
// 	ft_lstadd_back(&b, 1);
// 	ft_lstadd_back(&b, 3);
// 	c = ft_lstmerge(&a, &b);
// 	ft_lstprint(c);
// }

int	main(void)
{
	s_list<int>	*a;
	s_list<int>	*b;
	s_list<int>	*c;
	a = NULL;
	b = NULL;
	ft_lstadd<int>(&a, 6);
	ft_lstadd<int>(&a, 5);
	// ft_lstadd<int>(&a, 4);
	// ft_lstadd<int>(&a, 3);
	// ft_lstadd<int>(&a, 2);
	// ft_lstadd<int>(&a, 1);
	// ft_lstprint(a);

	// std::cout << "HEAD'S DATA:" << a->data << std::endl;
	// std::cout << std::endl;

	// s_list<int>	**b;

	// b = ft_lstsplit<int>(&a);
	// ft_lstprint(b[0]);
	// std::cout << std::endl;
	// ft_lstprint(b[1]);
	ft_lstadd<int>(&b, 3);
	ft_lstadd<int>(&b, 4);
	std::cout << "a" << std::endl;
	ft_lstprint(a);
	std::cout << "b" << std::endl;
	ft_lstprint(b);
	std::cout << "c" << std::endl;

	c = ft_lstmerge(&a, &b);
	ft_lstprint(c);
}

// int	main(void)
// {
// 	s_list	*a;
// 	s_list	*b;
// 	s_list	**test1;
// 	a = NULL;
// 	ft_lstadd_back(&a, 1);
// 	ft_lstadd_back(&a, 3);
// 	ft_lstadd_back(&a, 3);
// 	ft_lstadd_back(&a, 4);
// 	ft_lstadd_back(&a, 9);
// 	ft_lstadd_back(&a, 0);
// 	ft_lstadd_back(&a, -1);
// 	std::cout << "Contents of a:" << std::endl;
// 	ft_lstprint(a);
// 	test1 = ft_lstsplit(&a);
// 	std::cout << "Contents of a's even list:" << std::endl;
// 	ft_lstprint(test1[0]);
// 	std::cout << "Contents of a's odd list:" << std::endl;
// 	ft_lstprint(test1[1]);
// 	delete [] test1;
// 	b = NULL;
// 	ft_lstadd_back(&b, 1);
// 	ft_lstadd_back(&b, 3);
// 	ft_lstadd_back(&b, 3);
// 	std::cout << "Contents of b:" << std::endl;
// 	ft_lstprint(b);
// 	test1 = ft_lstsplit(&b);
// 	std::cout << "Contents of b's even list:" << std::endl;
// 	ft_lstprint(test1[0]);
// 	std::cout << "Contents of b's odd list:" << std::endl;
// 	ft_lstprint(test1[1]);
// 	delete [] test1;
// }
