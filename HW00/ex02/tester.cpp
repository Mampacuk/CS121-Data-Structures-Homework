/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:23:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/03 22:23:28 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int	ft_count_palindromes(int *arr, int arr_size, int low, int high);

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
	int	test3[] = {2, 2};
	int	test4[] = {1, 2, 3};
	int	test5[] = {3, 1, 3};
	int	test6[] = {3, 3, 3};
	int	test7[] = {1, 1, 2, 2, 2};
	int	test8[] = {1, 2, 3, 4, 5, 6, 7};
	int	test9[] = {5, 7, 1, 1, 2, 2, 2, 8};
	int	test10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int	test11[] = {1, 1, 1, 1};
	int	test12[] = {6, 6, 6, 5, 6, 5, 5, 6, 5, 6};

	result = ft_count_palindromes(test1, 1, 0, 0);
	std::cout << "TEST1: {1}\n0 VS " << result << std::endl;
	ft_print_status(result, 0);

	result = ft_count_palindromes(test2, 2, 0, 1);
	std::cout << "TEST2: {1, 2}\n0 VS " << result << std::endl;
	ft_print_status(result, 0);

	result = ft_count_palindromes(test3, 2, 0, 1);
	std::cout << "TEST3: {2, 2}\n1 VS " << result << std::endl;
	ft_print_status(result, 1);

	result = ft_count_palindromes(test4, 3, 0, 2);
	std::cout << "TEST4: {1, 2, 3}\n0 VS " << result << std::endl;
	ft_print_status(result, 0);

	result = ft_count_palindromes(test5, 3, 0, 2);
	std::cout << "TEST5: {3, 1, 3}\n1 VS " << result << std::endl;
	ft_print_status(result, 1);

	result = ft_count_palindromes(test6, 3, 0, 2);
	std::cout << "TEST6: {3, 3, 3}\n3 VS " << result << std::endl;
	ft_print_status(result, 3);

	result = ft_count_palindromes(test7, 5, 0, 4);
	std::cout << "TEST7: {1, 1, 2, 2, 2}\n4 VS " << result << std::endl;
	ft_print_status(result, 4);

	result = ft_count_palindromes(test8, 7, 0, 6);
	std::cout << "TEST8: {1, 2, 3, 4, 5, 6, 7}\n0 VS " << result << std::endl;
	ft_print_status(result, 0);

	result = ft_count_palindromes(test9, 8, 0, 7);
	std::cout << "TEST9: {5, 7, 1, 1, 2, 2, 2, 8}\n4 VS " << result << std::endl;
	ft_print_status(result, 4);

	result = ft_count_palindromes(test10, 10, 0, 9);
	std::cout << "TEST10: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}\n17 VS " << result << std::endl;
	ft_print_status(result, 17);

	result = ft_count_palindromes(test11, 4, 0, 3);
	std::cout << "TEST11: {1, 1, 1, 1}\n5 VS " << result << std::endl;
	ft_print_status(result, 5);

	result = ft_count_palindromes(test12, 10, 0, 9);
	std::cout << "TEST12: {6, 6, 6, 5, 6, 5, 5, 6, 5, 6}\n8 VS " << result << std::endl;
	ft_print_status(result, 8);
}