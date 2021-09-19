/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:55:08 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:30:31 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lstsort.hpp"

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*c;
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

// int	main(void)
// {
	// t_list	*a;
	// t_list	*b;
	// t_list	*c;
	// a = NULL;
	// b = NULL;
	// ft_lstadd_back(&a, 1);
	// ft_lstadd_back(&a, 2);
	// ft_lstadd_back(&b, 3);
	// ft_lstadd_back(&b, 4);
	// c = ft_lstmerge(&a, &b);
	// ft_lstprint(c);
// }

int	main(int, char **argv)
{
	t_list	*a;
	argv++;
	while (*argv)
	{
		ft_lstadd_back(&a, ft_atoi(*argv));
		argv++;	
	}
	a = ft_lstmerge_sort(&a);
	// segfaults on tricky inputs
	// a = ft_lstmerge_sort_split(&a);
	ft_lstprint(a);
}

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	**test1;
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
