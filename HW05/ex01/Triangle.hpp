/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:38:12 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/25 13:38:12 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

# include <cmath>
# include <exception>
# include <algorithm>
# include <ostream>
# include "../../libft/IComparator.hpp"

class	Triangle
{
	private:
		int	_a;
		int	_b;
		int	_c;
	public:
		class	AreaComparator : public IComparator<Triangle>
		{
			public:
				static double	computeArea(const Triangle &t);
				bool			operator()(const Triangle &a, const Triangle &b)	const;
		};
		Triangle(void);
		~Triangle(void);
		Triangle(int _a, int _b, int _c);
		Triangle(const Triangle &copy);
		Triangle	&operator=(const Triangle &rhs);
		bool		operator<(const Triangle &rhs)	const;
		int			getA(void)						const;
		int			getB(void)						const;
		int			getC(void)						const;
};

std::ostream	&operator<<(std::ostream &o, const Triangle &t);

#endif
