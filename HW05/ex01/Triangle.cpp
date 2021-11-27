/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:01:10 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 14:01:10 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"
#include "../../libft/SortedPriorityQueue.hpp"

double	Triangle::AreaComparator::computeArea(const Triangle &t)
{
	double	s;	// semi-perimeter

	s = (t.getA() + t.getB() + t.getC()) / 2.0;
	return (sqrt(s * (s - t.getA()) * (s - t.getB()) * (s - t.getC())));
}

bool	Triangle::AreaComparator::operator()(const Triangle &a, const Triangle &b) const
{
	return (this->computeArea(a) < this->computeArea(b));
}

Triangle::Triangle(void) {}

Triangle::~Triangle(void) {}

Triangle::Triangle(int _a, int _b, int _c) : _a(_a), _b(_b), _c(_c)
{
	if (_a <= 0 || _b <= 0 || _c <= 0)
		throw std::logic_error("triangle with negative/zero sides is not allowed");
}

Triangle::Triangle(const Triangle &copy) : Triangle(copy._a, copy._b, copy._c) {}

Triangle	&Triangle::operator=(const Triangle &rhs)
{
	this->_a = rhs._a;
	this->_b = rhs._b;
	this->_c = rhs._c;
	return (*this);
}

int	Triangle::getA(void) const
{
	return (this->_a);
}

int	Triangle::getB(void) const
{
	return (this->_b);
}

int	Triangle::getC(void) const
{
	return (this->_c);
}

bool	Triangle::operator<(const Triangle &rhs) const
{
	SortedPriorityQueue<int, char>	this_sides;
	SortedPriorityQueue<int, char>	rhs_sides;

	this_sides.insert(this->_a, 0);
	this_sides.insert(this->_b, 0);
	this_sides.insert(this->_c, 0);
	rhs_sides.insert(rhs._a, 0);
	rhs_sides.insert(rhs._b, 0);
	rhs_sides.insert(rhs._c, 0);
	while (!rhs_sides.empty() && !this_sides.empty())
	{
		if (this_sides.min()->getKey() > rhs_sides.min()->getKey())
			return (false);
		else if (this_sides.min()->getKey() < rhs_sides.min()->getKey())
			return (true);
		this_sides.removeMin();
		rhs_sides.removeMin();
	}
	return (false);
}

std::ostream	&operator<<(std::ostream &o, const Triangle &t)
{
	o << "Area:" << Triangle::AreaComparator::computeArea(t) << "; a:" << t.getA() << "; b:" << t.getB() << "; c:" << t.getC() << std::endl;
	return (o);
}