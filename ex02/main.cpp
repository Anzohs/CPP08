/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hladeiro <hladeiro@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 03:38:21 by hladeiro          #+#    #+#             */
/*   Updated: 2026/05/01 03:38:22 by hladeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main() {
    // Create a MutantStack of integers
    MutantStack<int> mstack;

    // Add elements to the stack
    mstack.push(5);
    mstack.push(17);

    // Print the top element
    std::cout << "Top element: " << mstack.top() << std::endl;

    // Remove the top element
    mstack.pop();

    // Print the size of the stack
    std::cout << "Stack size: " << mstack.size() << std::endl;

    // Add more elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterate over the stack using iterators
    std::cout << "Stack elements:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    // Test copy constructor
    std::cout << "Testing copy constructor:" << std::endl;
    MutantStack<int> copyStack(mstack);
    MutantStack<int>::iterator copyIt = copyStack.begin();
    MutantStack<int>::iterator copyIte = copyStack.end();
    while (copyIt != copyIte) {
        std::cout << *copyIt << std::endl;
        ++copyIt;
    }

    // Test assignment operator
    std::cout << "Testing assignment operator:" << std::endl;
    MutantStack<int> assignedStack;
    assignedStack = mstack;
    MutantStack<int>::iterator assignIt = assignedStack.begin();
    MutantStack<int>::iterator assignIte = assignedStack.end();
    while (assignIt != assignIte) {
        std::cout << *assignIt << std::endl;
        ++assignIt;
    }

    return 0;
}
