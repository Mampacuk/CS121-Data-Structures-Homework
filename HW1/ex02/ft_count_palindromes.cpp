/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_palindromes.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:23:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/04 18:32:56 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Helper that inspects from the beginning of the array 
 */
int	ft_inspect_arr(int *arr, int arr_size, int low, int high)
{
	/*
	 * Do not search for a length-3 palindrome 
	 */
	if (high - low + 1 == 2)
		return (arr[low] == arr[low + 1]);
	/*
	 * Compare current one with the next one (length-2) and with
	 * the next-next one (length-3)
	 */
	return ((arr[low] == arr[low + 1]) + (arr[low] == arr[low + 2]));
}

/*
 * Takes in an array to be inspected and its size as the next argument; 
 * `low` is expected to be 0 whereas high is expected to be `arr_size - 1`.
 * ATTENTION: it is assumed that `arr_size` is a positive integer;
 * error handling is NOT implemented and it is assumed that the input is valid
 */
int	ft_count_palindromes(int *arr, int arr_size, int low, int high)
{
	if (low >= high)
		return (0);
	return (ft_inspect_arr(arr, arr_size, low, high)
		+ ft_count_palindromes(arr, arr_size, low + 1, high));
}
