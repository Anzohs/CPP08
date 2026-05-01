	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2026/05/01 03:37:10 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:37:29 by hladeiro         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _size(N){};
Span::Span(const Span &other) : _size(other._size){this->box.assign(other.box.begin(), other.box.end());};

Span& Span::operator=(const Span &other){
	if (this == &other)
		return *this;
	this->_size = other._size;
	this->box.clear();
	this->box.assign(other.box.begin(), other.box.end());
	return *this;
};

Span::~Span(){
	std::cout << "Span class destroyed" << std::endl;
};

void Span::addNumber(int n)
{
	if (this->_size == this->box.size())
		throw std::out_of_range("You’re trying to go past the allowed capacity");
	this->box.push_back(n);
}

int Span::longestSpan() const
{
	if (this->box.size() < 2)
		throw std::logic_error("It’s a misuse of the class API (precondition not met), less than 2 numbers");
	return *std::max_element(this->box.begin(), this->box.end()) - *std::min_element(this->box.begin(), this->box.end());
};

int Span::shortestSpan() const
{
	int best;
	std::vector<int> tmp;

	if (this->box.size() < 2)
		throw std::logic_error("It’s a misuse of the class API (precondition not met), less than 2 numbers");

	tmp = this->box;
	std::sort(tmp.begin(), tmp.end());
	best = tmp[1] - tmp[0];

	for (size_t i = 2; i < tmp.size(); ++i) {
		int d = tmp[i] - tmp[i - 1];
			if (d < best) best = d;
	}
	return best;
};
