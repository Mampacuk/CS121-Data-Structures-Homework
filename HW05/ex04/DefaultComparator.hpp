/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DefaultComparator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:20:31 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/27 19:20:31 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTCOMPARATOR_HPP
# define DEFAULTCOMPARATOR_HPP

# include "../../libft/IComparator.hpp"
# include <algorithm>

template <typename K>
class	DefaultComparator : public IComparator<K>
{
	public:
		bool	operator()(const K &x, const K &y) const
		{
			const K	&maximum = std::max(x, y);
			if (maximum == y)
				return (true);
			return (false);
		}
};

#endif
