/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:38:12 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:38:13 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
	MutantStack() : std::stack<T>(){};
	MutantStack(const MutantStack<T> &other): std::stack<T>(other){};
	MutantStack<T> &operator=(const MutantStack<T> &other){
		if (this == &other)
			return *this;
		this->c = other.c;
		return *this;
	};

	~MutantStack(){};

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin(){return this->c.begin();};
	iterator end(){return this->c.end();};
	const_iterator begin() const{return this->c.begin();};
	const_iterator end() const{return this->c.end();};

};
