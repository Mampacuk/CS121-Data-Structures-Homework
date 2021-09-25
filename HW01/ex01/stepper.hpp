/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stepper.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:30:36 by aisraely          #+#    #+#             */
/*   Updated: 2021/09/21 15:15:44 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STEPPER_HPP
# define STEPPER_HPP

# include "../../libft/libft.hpp"

int	ft_check_step(int *arr, int arr_size);
int	ft_find_step(int *arr, int low, int high, int arr_size);

#endif