/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:31:24 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/04 18:42:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Student.hpp"

Student::~Student(void)
{
	
}

Student::Student(std::string &name, int questions) : _name(name), _questions(questions), _current(1)
{
	
}

Student::Student(const Student &copy) : _name(copy._name), _questions(copy._questions), _current(copy._current)
{

}

std::string	Student::getName(void) const
{
	return (this->_name);
}

int	Student::getQuestions(void) const
{
	return (this->_questions);
}

int	Student::getCurrent(void) const
{
	return (this->_current);
}

void	Student::incrementCurrent(void)
{
	this->_current++;
}

void	Student::printName(void) const
{
	std::cout << this->_name;
}

void	Student::printCurrent(void) const
{
	std::cout << this->_current;
}
