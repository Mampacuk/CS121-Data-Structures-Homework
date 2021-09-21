/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitstr.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:15:56 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 20:15:57 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.hpp"

int	ft_isdigitstr(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			if (!(*str == '-' && ft_isdigit(*(str + 1)) && *(str + 1) != '0'))
				return (0);
		str++;
	}
	return (1);
}
