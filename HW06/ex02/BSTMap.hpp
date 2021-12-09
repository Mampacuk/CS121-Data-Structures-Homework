/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSTMap.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:00:29 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/06 17:00:29 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTMAP_HPP
# define BSTMAP_HPP

# include "../../libft/ASortedMap.hpp"
# include "../../libft/LinkedBinaryTree.hpp"
# include <memory>

template <typename K, typename V>
class	BSTMap : public ASortedMap<K, V>
{
	typedef typename LinkedBinaryTree<std::unique_ptr<typename IMap<K, V>::Entry>>::Node TreeNode;
	typedef typename IMap<K, V>::Entry Entry;

	private:
		LinkedBinaryTree<std::unique_ptr<Entry>>	_tree;
	public:
		BSTMap();
		explicit BSTMap(IComparator<K> *comp);
		int				size() const;
		const V			&at(const K &key) const;
		const V			&put(const K &k, const V &v);
		void			erase(const K &k);
		List<Entry*>	entries() const;
		Entry			*firstEntry() const;
		Entry			*lastEntry() const;
		Entry			*ceilingEntry(const K &k) const;
		Entry			*floorEntry(const K &k) const;
		Entry			*lowerEntry(const K &k) const;
		Entry			*higherEntry(const K &k) const;
		List<Entry*> 	submap(const K &k1, const K &k2) const;
		friend			typename LinkedBinaryTree<std::unique_ptr<typename IMap<int, int>::Entry>>::Node *ft_separate_root(BSTMap<int, int> &tree);
	private:
		Entry			*expandExternal(TreeNode *p, Entry *entry);
		TreeNode		*treeSearch(TreeNode *p, const K &k) const;
		void			submap_recur(const K &k1, const K &k2, TreeNode *p, List<Entry*> &buf) const;
	protected:
		TreeNode		*treeMax(TreeNode *p) const;
		TreeNode		*treeMin(TreeNode *p) const;
};

template <typename K, typename V>
BSTMap<K, V>::BSTMap()
{
	this->_tree.addRoot();
}

template <typename K, typename V>
BSTMap<K, V>::BSTMap(IComparator<K> *comp) : ASortedMap<K, V>::ASortedMap(comp)
{
	this->_tree.addRoot();
}

template <typename K, typename V>
int	BSTMap<K, V>::size() const
{
	return ((this->_tree.size() - 1) / 2);
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::expandExternal(TreeNode *p, Entry *entry)
{
	(**p).reset(entry);
	this->_tree.addLeft(p);
	this->_tree.addRight(p);
	return ((**p).get());
}

template <typename K, typename V>
typename BSTMap<K, V>::TreeNode	*BSTMap<K, V>::treeSearch(TreeNode *p, const K &k) const
{
	if (p->isExternal() || this->equals(k, (**p).get()->getKey()))
		return (p);
	if (this->compare(k, (**p).get()))
		return (this->treeSearch(p->left(), k));
	return (this->treeSearch(p->right(), k));
}

template <typename K, typename V>
const V	&BSTMap<K, V>::at(const K &key) const
{
	TreeNode	*finding = this->treeSearch(this->_tree.root(), key);
	if (!(**finding).get())
		throw std::out_of_range("no value found for the given key");
	return ((**finding).get()->getValue());
}

template <typename K, typename V>
const V	&BSTMap<K, V>::put(const K &k, const V &v)
{
	TreeNode	*finding = this->treeSearch(this->_tree.root(), k);
	if (finding->isExternal())
		return (this->expandExternal(finding, new typename AMap<K, V>::MapEntry(k, v))->getValue());
	const V	&old = (**finding).get()->getValue();
	(**finding).reset(new typename AMap<K, V>::MapEntry(k, v));
	return (old);
}

template <typename K, typename V>
typename BSTMap<K, V>::TreeNode	*BSTMap<K, V>::treeMax(TreeNode *p) const
{
	while (p->isInternal())
		p = p->right();
	return (p->parent());
}

template <typename K, typename V>
typename BSTMap<K, V>::TreeNode	*BSTMap<K, V>::treeMin(TreeNode *p) const
{
	while (p->isInternal())
		p = p->left();
	return (p->parent());
}

template <typename K, typename V>
void	BSTMap<K, V>::erase(const K &k)
{
	TreeNode	*p = this->treeSearch(this->_tree.root(), k);
	if (p->isExternal())
		return ;
	if (p->left()->isInternal() && p->right()->isInternal())
	{
		TreeNode	*inorder_before = this->treeMax(p->left());
		(**p).swap(**inorder_before);
		p = inorder_before;
	}
	TreeNode	*leaf = p->left()->isExternal() ? p->left() : p->right();
	this->_tree.remove(leaf);
	this->_tree.remove(p);
}

template <typename K, typename V>
List<typename BSTMap<K, V>::Entry*>	BSTMap<K, V>::entries() const
{
	List<Entry*>	entries;
	auto nodes = this->_tree.nodes();
	for (auto it = nodes.begin(); it != nodes.end(); ++it)
		if ((***it).get())
			entries.insertBack((***it).get());
	return (entries);
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::lastEntry()	const
{
	if (this->empty())
		return (nullptr);
	return ((**this->treeMax(this->_tree.root())).get());
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::firstEntry()	const
{
	if (this->empty())
		return (nullptr);
	return ((**this->treeMin(this->_tree.root())).get());
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::floorEntry(const K &k)	const
{
	TreeNode	*p = this->treeSearch(this->_tree.root(), k);
	if (p->isInternal())
		return ((**p).get());
	while (!p->isRoot())
	{
		if (p == p->parent()->right())
			return ((**p->parent()).get());
		p = p->parent();
	}
	return (nullptr);
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::ceilingEntry(const K &k)	const
{
	TreeNode	*p = this->treeSearch(this->_tree.root(), k);
	if (p->isInternal())
		return ((**p).get());
	while (!p->isRoot())
	{
		if (p == p->parent()->left())
			return ((**p->parent()).get());
		p = p->parent();
	}
	return (nullptr);
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::lowerEntry(const K &k)	const
{
	TreeNode	*p = this->treeSearch(this->_tree.root(), k);
	if (p->isInternal() && p->left()->isInternal())
		return ((**this->treeMax(p->left())).get());
	while (!p->isRoot())
	{
		if (p == p->parent()->right())
			return ((**p->parent()).get());
		p = p->parent();
	}
	return (nullptr);
}

template <typename K, typename V>
typename BSTMap<K, V>::Entry	*BSTMap<K, V>::higherEntry(const K &k)	const
{
	TreeNode	*p = this->treeSearch(this->_tree.root(), k);
	if (p->isInternal() && p->right()->isInternal())
		return ((**this->treeMin(p->left())).get());
	while (!p->isRoot())
	{
		if (p == p->parent()->left())
			return ((**p->parent()).get());
		p = p->parent();
	}
	return (nullptr);
}

template <typename K, typename V>
List<typename BSTMap<K, V>::Entry*> BSTMap<K, V>::submap(const K &k1, const K &k2) const
{
	List<Entry*>	buf;
	if (this->compare(k1, k2))
		this->submap_recur(k1, k2, this->_tree.root(), buf);
	return (buf);
}

template <typename K, typename V>
void	BSTMap<K, V>::submap_recur(const K &k1, const K &k2, TreeNode *p, List<Entry*> &buf) const
{
	if (p->isInternal())
	{
		if (this->compare((**p).get(), k1))
			this->submap_recur(k1, k2, p->right(), buf);
		else
		{
			this->submap_recur(k1, k2, p->left(), buf);
			if (this->compare((**p).get(), k2))
			{
				buf.insertBack((**p).get());
				this->submap_recur(k1, k2, p->right(), buf);
			}
		}
	}
}

#endif
