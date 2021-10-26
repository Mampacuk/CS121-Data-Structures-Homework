/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:17 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 21:34:10 by aisraely         ###   ########.fr       */
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
		class	Position : IIterator<std::string>
		{
			public:
				// Position		&operator=(const Position &rhs);
				std::string		&operator*(void);
				bool			operator==(const IIterator<std::string> &p)	const;
				bool			operator!=(const IIterator<std::string> &p)	const;
				Position		&operator++(void);
				Position		&operator--(void);
				friend class	StringArrayPositionalList;
			private:
				Position(int _i, std::string *_str) : _i(_i), _str(_str) {}
				int			_i;
				std::string	*_str;
		}
		StringArrayPositionalList(void);
		~StringArrayPositionalList(void);
		StringArrayPositionalList(const StringArrayPositionalList &copy);
		StringArrayPositionalList	&operator=(const StringArrayPositionalList &rhs);
		int							size(void)	const;
		bool						empty(void)	const;
		void						print(void)	const;
		void						reserve(int n);
		void						insertFront(const std::string &e);
		void						insertBack(const std::string &e);
		void						insert(const IIterator<std::string> &p, const std::string &e);
		void						eraseFront(void);
		void						eraseBack(void);
		void						erase(const IIterator<std::string> &p);
		Position					begin(void)	const;
		Position					end(void)	const;
	private:
		int							_capacity;
		int							_n;
		Position					*_data;
}

#endif