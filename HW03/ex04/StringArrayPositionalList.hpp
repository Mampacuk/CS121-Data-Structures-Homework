/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:17 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 20:12:38 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGARRAYPOSITIONALLIST_HPP
# define STRINGARRAYPOSITIONALLIST_HPP

# include "../../libft/IList.hpp"
# include "../../libft/IIterator.hpp"
# include <string>

class	StringArrayPositionalList : public IList<std::string>
{
	public:
				Position		&operator=(const Position &rhs);
				D				&operator*(void);
				bool			operator==(const Position &p)	const;
				bool			operator!=(const Position &p)	const;
				Position		&operator++(void);
				Position		&operator--(void);
				friend class	StringArrayPositionalList;
			private:
				int			_i;
				std::string	_str;
		}
		StringArrayPositionalList(void);
		~StringArrayPositionalList(void);
		StringArrayPositionalList(const StringArrayPositionalList &copy);
		StringArrayPositionalList	&operator=(const StringArrayPositionalList &rhs);
		int							size(void)	const;
		bool						empty(void)	const;
		void						print(void)	const;
		void						insertFront(const D &e);
		void						insertBack(const D &e);
		void						insert(Position &p, const D &e);
		void						eraseFront(void);
		void						eraseBack(void);
		void						erase(Position &p);
	private:
		int							_capacity;
		int							_n;
		Position					*_data;
}

#endif