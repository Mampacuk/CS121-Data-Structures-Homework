/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:55:02 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 21:21:14 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSTSORT_HPP
# define LSTSORT_HPP

# include "../../libft/libft.hpp"

t_list	**ft_lstsplit(t_list **head);
t_list	*ft_lstmerge(t_list **lst1, t_list **lst2);
t_list	*ft_lstmerge_sort(t_list **head);
t_list	*ft_lstmerge_sort_split(t_list **head);

#endif