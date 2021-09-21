/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_step.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 20:07:54 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stepper.hpp"

int	ft_find_step(int *arr, int low, int high, int arr_size)
{
	int	i;
	int	mid;

	i = 0;
	mid = (low + high) / 2;
	if (arr_size < 0)
		return (-1);
	/*
	 * Trivial case; the sequence is even from the beginning
	 */
	if (arr_size >= 2 && !((arr[0] - arr[1]) % 2) && !low)
		return (0);
	/*
	 * Check for boundaries and false cases
	 */
	if (mid < 1 || mid > arr_size - 2 || low < 0 || high >= arr_size || low > high)
		return (-1);
	/*
	 * Check for the satisfaction of the requirement (left step is odd, right one is even)
	 */
	if ((arr[mid - 1] - arr[mid]) % 2 && !((arr[mid] - arr[mid + 1]) % 2))
		return (mid);
	/*
	 * If both pairs to the left and right of `mid` are odd, then the number is to the right;
	 * consider the right portion. Conversely, if both pairs to the left and right of `mid` are
	 * even, consider the left portion, by updating `low` and `high` in the recursion call.
	 */
	if ((arr[mid - 1] - arr[mid]) % 2 && (arr[mid] - arr[mid + 1]) % 2)
		return (ft_find_step(arr, mid + 1, high, arr_size));
	else if (!((arr[mid - 1] - arr[mid]) % 2) && !((arr[mid] - arr[mid + 1]) % 2))	// if both even, consider left part
		return (ft_find_step(arr, low, mid, arr_size));
	return (-1);
}
