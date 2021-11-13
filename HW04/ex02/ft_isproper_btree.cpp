/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isproper_btree.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:41:37 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/12 22:41:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Integer.hpp"

enum	e_state
{
	present,
	absent,
	out_of_bounds,
	error
};

static e_state	ft_check_state(Integer *elem)
{
	if (!elem)
		return (absent);
	return (present);
}

static int	ft_isproper_btree(Integer **arr, int arr_len, int i)
{
	int	left_state;
	int	right_state;

	if (i >= arr_len)
		return (out_of_bounds);
	left_state = ft_isproper_btree(arr, arr_len, 2 * i + 1);
	right_state = ft_isproper_btree(arr, arr_len, 2 * i + 2);
	if (left_state == error || right_state == error || (left_state == present && right_state == out_of_bounds)
		|| (left_state == present && right_state == absent)
		|| (left_state == absent && right_state == present))
		return (error);
	return (ft_check_state(arr[i]));
}

bool	ft_isproper_btree(Integer **arr, int arr_len)
{
	return (!ft_isproper_btree(arr, arr_len, 0));
}
