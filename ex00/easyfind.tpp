/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:37:54 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:37:57 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <sstream>
#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int i) {

	for(typename T::iterator x = container.begin(); x != container.end(); x++)
	{
			if (*x == i){
				return (x);
			}
	};
	throw std::runtime_error("The value doesn't exist in the current container");
};


/*
 * 	Other way to do it!
 * typename T::iterator easyfind(T& container, int value)
 {
     typename T::iterator it = std::find(container.begin(), container.end(), value);

     if (it != container.end())
         return it;

     throw std::runtime_error("Value not found!");
 }
 *
 *
 *
 */
