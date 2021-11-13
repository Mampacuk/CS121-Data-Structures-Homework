/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringArrayPositionalList.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:53:17 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/26 23:36:29 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGARRAYPOSITIONALLIST_HPP
# define STRINGARRAYPOSITIONALLIST_HPP

# include "../../libft/libft.hpp"
# include <string>

class	StringArrayPositionalList : public IList<std::string>
{
	public:
		class	Position : IIterator<std::string>
		{
			public:
				std::string		&operator*(void)							const;
				bool			operator==(const IIterator<std::string> &p)	const;
				bool			operator!=(const IIterator<std::string> &p)	const;
				Position		&operator++(void);
				Position		&operator--(void);
				friend class	StringArrayPositionalList;
				friend class	SortedIterator;
			private:
				Position(void) : _i(0), _str(NULL) {}
				Position(int _i, std::string *_str) : _i(_i), _str(_str) {}
				int				_i;
				std::string		*_str;
		};
		class	SortedIterator : IIterator<std::string>
		{
			public:
				std::string		&operator*(void)							const;
				bool			operator==(const IIterator<std::string> &p)	const;
				bool			operator!=(const IIterator<std::string> &p)	const;
				SortedIterator	&operator++(void);
				SortedIterator	&operator--(void);
				friend class	StringArrayPositionalList;
			private:
				SortedIterator(Position *pos, int size);
				int			_i;
				Position	**_pos;
				void	ft_swap(Position **arr, int firstindex, int secondindex)
				{
					Position	*temp;
				
					temp = arr[firstindex];
					arr[firstindex] = arr[secondindex];
					arr[secondindex] = temp;
				}
				int	ft_partition(Position **arr, int p, int r)
				{
					int q;
					int i;
				
					i = p;
					q = p;
					while (i < r)
					{
						if (ft_strcmp((*(*arr[i])).c_str(), (*(*arr[r])).c_str()) <= 0)
							ft_swap(arr, q++, i);
						i++;
					}
					ft_swap(arr, r, q);
					return (q);
				}
				void	ft_quicksort(Position **arr, int p, int r)
				{
					int q;
				
					q = 0;
					if (p < r)
					{
						q = ft_partition(arr, p, r);
						ft_quicksort(arr, p, q - 1);
						ft_quicksort(arr, q + 1, r);
					}
				}
		};
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
		SortedIterator				beginSorted(void)	const;
	private:
		int							_capacity;
		int							_n;
		Position					*_data;
};

#endif
