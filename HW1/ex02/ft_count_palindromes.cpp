/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_palindromes.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 22:23:07 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/03 22:23:07 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Helper that inspects from the beginning of the array 
 */
int	ft_inspect_low(int *arr, int arr_size, int low)
{
	/*
	 * Do not search for a length-3 palindrome 
	 */
	if (arr_size <= 2)
		return (arr[low] == arr[low + 1]);
	/*
	 * Compare current one with the next one (length-2) and with
	 * the next-next one (length-3)
	 */
	return ((arr[low] == arr[low + 1]) + (arr[low] == arr[low + 2]));
}

/*
 * Helper that inspects from the ending of the array 
 */
int	ft_inspect_high(int *arr, int arr_size, int high)
{
	/*
	 * Do not search for a length-3 palindrome 
	 */
	if (arr_size <= 2)
		return (arr[high] == arr[high - 1]);
	/*
	 * Compare current one with the next one (length-2) and with
	 * the next-next one (length-3)
	 */
	return ((arr[high] == arr[high - 1]) + (arr[high] == arr[high - 2]));
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
	{
		/*
		 * To avoid a duplicate in case of [..., x, x, x, ...] 
		 */
		if (arr_size >= 3)
		{
			/*
			 * There's one duplicate if the length is odd 
			 */
			if (arr_size % 2)
			{
				if (arr[low - 1] == arr[high + 1])
					return (-1);					
			}
			/*
			 * There are two more duplicates than usual if the
			 * length is even 
			 */
			else
			{
				if (arr[low] == arr[high])
					return (-3);
			}
		}
		/*
		 * To avoid a duplicate in case of [x, x] 
		 */
		else if (arr_size == 2)
		{
			if (arr[low] == arr[high])
				return (-1);
		}
		return (0);
	}
	return (ft_inspect_high(arr, arr_size, high)
		+ ft_inspect_low(arr, arr_size, low)
		+ ft_count_palindromes(arr, arr_size, low + 1, high - 1));
}
