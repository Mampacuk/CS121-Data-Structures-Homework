/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayBinaryTree.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:07:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/11/13 12:07:27 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYBINARYTREE_HPP
# define ARRAYBINARYTREE_HPP

# include "../../libft/IBinaryTree.hpp"
# include "../../libft/IIterator.hpp"

template <typename E>
class	ArrayBinaryTree : public IBinaryTree<E>
{
	public:
		class	Node : public IBinaryTree<E>::Node
		{
			public:
				virtual ~Node(void) {}
				Node(const Node &copy) : _par(copy._par), _left(copy._left), _right(copy._right), _data(copy._data) {}
				E				&operator*(void);
				Node			&operator=(const Node &rhs);
				Node			*left(void)			const;
				Node			*right(void)		const;
				Node			*sibling(void)		const;
				Node			*parent(void)		const;
				List<typename ITree<E>::Node*>
					children(void)					const;
				bool			isRoot(void)		const;
				bool			isExternal(void)	const;
				bool			isInternal(void)	const;
				void			setElement(const E &e);
				friend class	ArrayBinaryTree;
			private:
				Node(void) : _i(0), _data() {}
				Node(int _i, const E &_data) : _i(_i), _data(_data) {}
				int				_i;
				E				_data;
		}
		ArrayBinaryTree(void);
		~ArrayBinaryTree(void);
		ArrayBinaryTree(const ArrayBinaryTree &copy);
		ArrayBinaryTree	&operator=(const ArrayBinaryTree &rhs);
		int				size(void)				const;
		bool			empty(void) 			const;
		Node			*root(void)				const;
		List<typename ITree<E>::Node*>
			nodes(void)								const;
		Iterator		begin(void)				const;
		void			print(void)				const;
		void			addRoot(const E &e);
		void			addLeft(Node *p, const E &e);
		void			addRight(Node *p, const E &e);
		void			remove(Node *p);
	private:
		Node			*_arr;
		int				_n;
};

#endif
