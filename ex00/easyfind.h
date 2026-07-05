/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:37:40 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:37:41 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#define RED "\033[31m"
#define RESET "\033[0m"

template<typename T>
typename T::iterator easyfind(T& container, int i);
