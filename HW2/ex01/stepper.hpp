/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepper.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:36 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/18 18:30:37 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEPPER_HPP
# define STEPPER_HPP

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# include <stdio.h>
# include <iostream>

int	ft_check_step(int *arr, int arr_size);
int	ft_find_step(int *arr, int arr_size);

#endif