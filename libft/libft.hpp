/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:37:27 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/19 20:10:58 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

# include <iostream>
# include <string>

# include <stdio.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstadd_back(t_list **lst, int data);
void	ft_lstprint(t_list *lst);
t_list	*ft_lstfind(t_list *lst, int index);
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(char **s1, char **s2);
int		ft_atoi(const char *str);

#endif