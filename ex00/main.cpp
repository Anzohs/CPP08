/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:37:46 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:37:49 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.h"
#include "easyfind.tpp"

int main() {
    try {
        // Test with std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        std::cout << "Testing with std::vector..." << std::endl;
        std::vector<int>::iterator vecIt = easyfind(vec, 5);
        std::cout << "Found in vector: " << *vecIt << std::endl;

        // Test with std::list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        std::cout << "Testing with std::list..." << std::endl;
        std::list<int>::iterator listIt = easyfind(lst, 50);
        std::cout << "Found in list: " << *listIt << std::endl;

        // Test with std::deque
        std::deque<int> deq;
        deq.push_back(10);
        deq.push_back(20);
        deq.push_back(30);
        deq.push_back(40);
        deq.push_back(50);
        std::cout << "Testing with std::deque..." << std::endl;
        std::deque<int>::iterator deqIt = easyfind(deq, 40);
        std::cout << "Found in deque: " << *deqIt << std::endl;

        // Test with a value that doesn't exist
        std::cout << "Testing with a value that doesn't exist..." << std::endl;
        std::vector<int>::iterator notFoundIt = easyfind(vec, 100);
        std::cout << "Found in vector: " << *notFoundIt << std::endl;
    } catch (const std::exception& e) {
        // Catch and handle the exception
        std::cerr << e.what() << std::endl;
        std::cerr << e.what() << "This error was catch" << std::endl;
    }

    return 0;
}
