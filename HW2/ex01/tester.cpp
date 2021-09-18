/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:40 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 18:30:41 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stepper.hpp"

void	ft_print_status(int result, int answer)
{
	if (result == answer)
		printf("%sSUCCESS%s\n", KGRN, KNRM);
	else
		printf("%sFAILURE%s\n", KRED, KNRM);
	printf("\n");
}

int	main(void)
{
	int	result;
	int	test1[] = {1};
	int	test2[] = {1, 2};
	int test3[] = {2, 2};
	int test4[] = {1, 2, 1};
	int test5[] = {1, 2, 3, 4, 6, 8, 10};
	int test6[] = {5, 8, -3, -5, 1, -3, -9};

	result = ft_find_step(test1, 1);
	std::cout << "TEST0: {1}\nEXPECTED: -1; RECEIVED: " << result << std::endl;
	ft_print_status(result, -1);

	result = ft_find_step(test2, 2);
	std::cout << "TEST1: {1, 2}\nEXPECTED: -1; RECEIVED: " << result << std::endl;
	ft_print_status(result, -1);

	result = ft_find_step(test3, 2);
	std::cout << "TEST2: {2, 2}\nEXPECTED: 0; RECEIVED: " << result << std::endl;
	ft_print_status(result, 0);

	result = ft_find_step(test4, 3);
	std::cout << "TEST3: {1, 2, 1}\nEXPECTED: -1; RECEIVED: " << result << std::endl;
	ft_print_status(result, -1);

	result = ft_find_step(test5, 7);
	std::cout << "TEST4: {1, 2, 3, 4, 6, 8, 10}\nEXPECTED: 3; RECEIVED: " << result << std::endl;
	ft_print_status(result, 3);

	result = ft_find_step(test6, 7);
	std::cout << "TEST5: {5, 8, -3, -5, 1, -3, -9}\nEXPECTED: 2; RECEIVED: " << result << std::endl;
	ft_print_status(result, 2);
}