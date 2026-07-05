/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:37:25 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:37:27 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include <stdexcept>

class Span{
	private:
	unsigned int	_size;
	std::vector<int>	box;
	public:
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename Iterator>
    void addNumbers(Iterator first, Iterator last)
    {
        if (box.size() + static_cast<unsigned int>(std::distance(first, last)) > _size)
            throw std::runtime_error("You’re trying to go past the allowed capacity");

        box.insert(box.end(), first, last);
    }
};
