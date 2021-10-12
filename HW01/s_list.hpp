/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:11:40 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/28 21:57:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIST_HPP
# define S_LIST_HPP

template <typename D>
struct	s_list
{
	D		data;
	s_list	*next;
};

template <typename D>
s_list<D>	*ft_lstnew(D data)
{
	s_list<D>	*head;

	head = new s_list<D>;
	if (!head)
		return (NULL);
	head->data = data;
	head->next = NULL;
	return (head);
}

template <typename D>
void	ft_lstprint(s_list<D> *lst)
{
	s_list<D>	*curr;

	if (!lst)
	{
		std::cout << "(null)" << std::endl;
		return ;
	}
	curr = lst;
	while (curr)
	{
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}

template <typename D>
s_list<D>	*ft_lstlast(s_list<D> *lst)
{
	s_list<D>	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

template <typename D>
void	ft_lstadd_back(s_list<D> **lst, s_list<D> *node)
{
	s_list<D>	*last;

	if (lst && node)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = node;
		}
		else
			*lst = node;
	}
}

template <typename D>
void	ft_lstadd(s_list<D> **lst, s_list<D> *node)
{
	if (lst && node)
	{
		if (*lst)
		{
			node->next = *lst;
			*lst = node;
		}
		else
		{
			*lst = node;
			node->next = NULL;
		}
	}
}

template <typename D>
void	ft_lstadd(s_list<D> **lst, D data)
{
	s_list<D>	*new_head;

	if (lst)
	{
		if (*lst)
		{
			new_head = ft_lstnew(data);
			new_head->next = *lst;
			*lst = new_head;
		}
		else
			*lst = ft_lstnew(data);
	}
}

template <typename D>
/*
 * `result[0]` is always the odd list;
 * `result[1]` is always the even list
 */
s_list<D>	**ft_lstsplit(s_list<D> **head)
{
	int			i;
	s_list<D>	**result;
	s_list<D>	*curr;
	s_list<D>	*next_node;

	if (!head)
		return (NULL);
	result = new s_list<D> *[2];
	/*
	 * If a head is empty, then there was no odd/even
	 * members in the list, and it's NULL
	 */
	result[0] = NULL;
	result[1] = NULL;
	curr = *head;
	i = 0;
	while (curr)
	{
		next_node = curr->next;
		if (i % 2 != 0)
			ft_lstadd<D>(&result[0], curr);
		else
			ft_lstadd<D>(&result[1], curr);
		curr = next_node;
		i++;
	}
	return (result);
}

template <typename D>
s_list<D>	*ft_lstmerge(s_list<D> **lst1, s_list<D> **lst2)
{
	s_list<D>	*head;
	s_list<D>	*tail;
	s_list<D>	*curr1;
	s_list<D>	*curr2;
	
	if (!lst1 || !lst2)
		return (NULL);
	/*
	 * If one of the lists is empty, then it's
	 * trivially sorted 
	 */
	if (!(*lst1))
		return (*lst2);
	if (!(*lst2))
		return (*lst1);
	/*
	 * Check which one of the lists to take as the head
	 * to build on
	 */
	if ((*lst1)->data < (*lst2)->data)
	{
		head = (*lst1);
		/*
		 * If it doesn't have any other elements, then
		 * just make it point to the head of the other
		 * list and return (in `else` of this branch)
		 */
		if (head->next)
		{
			/*
			 * Should we relink the head to the other list
			 * (if), or continue building atop the selected
			 * one (else)?
			 */
			if ((*lst2)->data < head->next->data)
			{
				curr1 = head->next;
				curr2 = (*lst2)->next;
				head->next = (*lst2);
			}
			else
			{
				curr1 = head->next->next;
				curr2 = (*lst2);
				tail = head->next;
			}
		}
		else
		{
			head->next = (*lst2);
			return (head);
		}
	}
	/*
	 * Is symmetric to the previous branch
	 */
	else
	{
		head = (*lst2);
		if (head->next)
		{
			if (head->next && (*lst1)->data < head->next->data)
			{
				curr1 = (*lst1)->next;
				curr2 = head->next;
				head->next = (*lst1);
			}
			else
			{
				curr1 = (*lst1);
				curr2 = head->next->next;
				tail = head->next;
			}
		}
		else
		{
			head->next = (*lst1);
			return (head);
		}
	}
	tail = head->next;
	while (curr1 && curr2)
	{
		if (curr1->data < curr2->data)
		{
			tail->next = curr1;
			curr1 = curr1->next;
		}
		else
		{
			tail->next = curr2;
			curr2 = curr2->next;
		}
		tail = tail->next;
	}
	if (!curr1)
		tail->next = curr2;
	else if (!curr2)
		tail->next = curr1;
	return (head);
}

template <typename D>
s_list<D>	*ft_lstmerge_sort(s_list<D> **head)
{
	s_list<D>	**sublists;
	s_list<D>	*merged;
	
	if (!head || !(*head))
		return (NULL);
	if (!(*head)->next)
		return (*head);
	sublists = ft_lstsplit<D>(head);
	sublists[0] = ft_lstmerge_sort<D>(&sublists[0]);
	sublists[1] = ft_lstmerge_sort<D>(&sublists[1]);
	merged = ft_lstmerge<D>(&sublists[0], &sublists[1]);
	/*
	 * Because memory leaks should be the developer's
	 * responsibility. SAY `NO` TO JAVA'S "GARBAGE COLLECTOR"!!!!
	 */
	delete [] sublists;
	return (merged);		
}

template <typename D>
s_list<D>	*ft_lstbubble_sort(s_list<D> **head)
{
	int			swap;
	s_list<D>	*curr;
	D			temp;
	
	if (!head || !(*head))
		return (NULL);
	swap = 1;
	while (swap)
	{
		swap = 0;
		/*
		 * Restore the pointer
		 */
		curr = *head;
		while (curr->next)
		{
			/*
			 * Do the swap, set the boolean to true
			 */
			if (curr->data > curr->next->data)
			{
				temp = curr->data;
				curr->data = curr->next->data;
				curr->next->data = temp;
				swap = 1;
			}
			curr = curr->next;
		}
	}
	return (*head);
}

// template <typename D>
// s_list<D>	*ft_lstbucket_sort(s_list<D> **head, int max)
// {
// 	int			i;
// 	s_list<D>	*curr;
// 	s_list<D>	*next_node;
// 	s_list<D>	**buckets = new s_list<D> *[max];

// 	if (!head || !(*head))
// 		return (NULL);
// 	curr = *head;
// 	/*
// 	 * Put nodes into buckets
// 	 */
// 	while (curr)
// 	{
// 		next_node = curr->next;
// 		ft_lstadd(&buckets[curr->data], curr);
// 		curr = next_node;
// 	}
// 	*head = NULL;
// 	i = 0;
// 	while (i < max - 1)
// 		ft_lstadd_back(head, buckets[i++]);
// 	delete [] buckets;
// 	return (*head);
// }

template <typename D>
static int	ft_find_msb(s_list<D> *head)
{
	D			max;
	s_list<D>	*curr;

	if (!head)
		return (0);
	max = head->data;
	curr = head->next;
	while (curr)
	{
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	if (!max)
		return (0);
	return (log2(max) + 1);
}

template <typename D>
s_list<D>	*ft_lstradix_sort(s_list<D> **head)
{
	int			i;
	int			bitmask;
	int			msb;
	s_list<D>	*curr;
	s_list<D>	*next_node;
	s_list<D>	*buckets[2] = {};
	
	if (!head || !(*head))
		return (NULL);
	i = 0;
	msb = ft_find_msb(*head);
	while (i < msb)
	{
		/*
		 * To separate the bit by using AND operation
		 */
		bitmask = 1 << i;
		curr = *head;
		/*
		 * Put nodes into buckets
		 */
		while (curr)
		{
			next_node = curr->next;
			ft_lstadd_back(&buckets[(curr->data & bitmask) != 0], curr);
			curr->next = NULL;
			curr = next_node;
		}
		/*
		 * Combine the buckets 
		 */
		*head = NULL;
		ft_lstadd_back(head, buckets[0]);
		ft_lstadd_back(head, buckets[1]);
		buckets[0] = NULL;
		buckets[1] = NULL;
		i++;
	}
	return (*head);
}

template <typename D>
s_list<D>	*ft_lsthybrid_sort(s_list<D> **head)
{
	int			i;
	s_list<D>	*curr;
	s_list<D>	*next_node;
	s_list<D>	*buckets[10000] = {};

	if (!head || !(*head))
		return (NULL);
	curr = *head;
	/*
	 * Put nodes into buckets
	 */
	while (curr)
	{
		next_node = curr->next;
		ft_lstadd(&buckets[curr->data / 10000], curr);
		curr = next_node;
	}
	/*
	 * Commence bubble sort on each bucket
	 */
	i = 0;
	while (i < 10000)
	{
		if (buckets[i])
			buckets[i] = ft_lstbubble_sort(&buckets[i]);
		i++;
	}
	/*
	 * Combine the buckets
	 */
	*head = NULL;
	i = 0;
	while (i < 10000)
		ft_lstadd_back(head, buckets[i++]);
	return (*head);
}

#endif
