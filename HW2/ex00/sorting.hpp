#ifndef SORTING_HPP
# define SORTING_HPP

# include <stdlib.h>
# include <iostream>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_selection_sort(char **arr);
void	ft_insertion_sort(char **arr, char **head);

#endif