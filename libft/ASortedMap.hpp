/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASortedMap.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 00:13:52 by aisraely          #+#    #+#             */
/*   Updated: 2021/12/05 00:13:52 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASORTEDMAP_HPP
# define ASORTEDMAP_HPP

# include "AMap.hpp"
# include "ISortedMap.hpp"

template <typename K, typename V>
class	ASortedMap : public ISortedMap<K, V>, public AMap<K, V>
{
	
};

#endif
