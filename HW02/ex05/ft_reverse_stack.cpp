/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_stack.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:43:03 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/08 13:43:58 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IStack.hpp"

void	ft_reverse_stack(IStack &a)
{
	IStack	b(a.size());
	
	while (!a.empty())
	{
		b.push(a.top());
		a.pop();
	}
	while (!b.empty())
	{
		a.push(b.top());
		b.pop();
	}
}
