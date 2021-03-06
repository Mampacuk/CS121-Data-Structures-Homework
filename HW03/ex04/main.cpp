/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:40:34 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 22:52:19 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringArrayPositionalList.hpp"

int	main(void)
{
	StringArrayPositionalList	seq;

	seq.insertFront(std::string("ho"));
	seq.insertFront(std::string("hai"));
	seq.insertFront(std::string("hasdasdi"));
	seq.insertBack(std::string("no"));
	seq.insertBack(std::string("no"));
	seq.insertBack(std::string("no"));
	seq.insertFront(std::string("yes"));
	seq.insertFront(std::string("yes"));
	seq.eraseFront();
	seq.eraseFront();
	seq.eraseBack();
	seq.print();
}