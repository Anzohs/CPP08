# CPP08 — Templated Containers, Iterators and Algorithms

CPP08 from 42 school covers the use of **STL (Standard Template Library)** templated containers, iterators, and algorithms in C++98.

---

## Table of Contents

- [General Rules](#general-rules)
- [Exercise 00 — Easy Find](#exercise-00--easy-find)
- [Exercise 01 — Span](#exercise-01--span)
- [Exercise 02 — Mutated Abomination](#exercise-02--mutated-abomination)

---

## General Rules

- All code must compile with `c++` and the flags `-Wall -Wextra -Werror`.
- The standard is **C++98**. No C++11 or later features allowed.
- No memory leaks.
- Classes must follow the **Orthodox Canonical Form** (default constructor, copy constructor, copy assignment operator, destructor) where appropriate.
- The `using namespace std` directive and `friend` keyword are forbidden.

---

## Exercise 00 — Easy Find

**Directory:** `ex00/`

### Goal

Write a **function template** called `easyfind` that accepts a container type `T`, an integer, and searches for the first occurrence of that integer in the container.

### Prototype

```cpp
template <typename T>
T easyfind(T container, int i);
// find the first occurrence of n in container
```

### Behavior

- If the value is **found**, return an iterator pointing to it (or handle it the way you choose).
- If the value is **not found**, throw an exception or return an error value.

### Key concepts

| Concept | Detail |
|---|---|
| Function template | The function works with any STL container that supports iterators (e.g., `std::vector`, `std::list`, `std::deque`). |
| `std::find` | The algorithm from `<algorithm>` that searches through a range `[begin, end)`. |
| Exception handling | Throw an exception (e.g., derived from `std::exception`) when the element is not found. |

### Example

```cpp
std::vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);

easyfind(v, 2); // returns iterator pointing to 2
easyfind(v, 9); // throws an exception — not found
```

---

## Exercise 01 — Span

**Directory:** `ex01/`

### Goal

Create a class `Span` that stores a maximum of `N` integers (where `N` is passed to the constructor) and can compute the **shortest** and **longest** span (difference) between any two numbers it stores.

### Class Interface

```cpp
class Span {
public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);           // add a single number
    int shortestSpan() const;        // smallest difference between any two numbers
    int longestSpan() const;         // largest difference between any two numbers
};
```

### Behavior

- `addNumber` throws an exception if the container is already full (i.e., `N` numbers are already stored).
- `shortestSpan` and `longestSpan` throw an exception if there are fewer than 2 numbers stored (no span can be computed).
- You must also implement a method (or overload of `addNumber`) that adds a **range of iterators** at once, so that thousands of numbers can be inserted efficiently without calling `addNumber` in a loop.

### Key concepts

| Concept | Detail |
|---|---|
| Internal storage | Use an STL container such as `std::vector` or `std::list` to store the numbers. |
| `std::min_element` / `std::max_element` | From `<algorithm>`, used to find the minimum and maximum of the stored values, enabling the longest span calculation. |
| Sorting for shortest span | Sort the container and then find the minimum difference between adjacent elements. |
| Iterator range insertion | Use a method accepting two iterators to bulk-insert values. |

### Example

```cpp
Span sp(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl; // 2  (11 - 9)
std::cout << sp.longestSpan()  << std::endl; // 14 (17 - 3)
```

---

## Exercise 02 — Mutated Abomination

**Directory:** `ex02/`

### Goal

The `std::stack` container is a classic stack (LIFO) adaptor that deliberately **hides its iterators**. Your task is to make it iterable by creating a class `MutantStack` that inherits from `std::stack` and exposes its underlying container's iterators.

### Class Interface

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack();
    MutantStack(const MutantStack<T> &other);
    MutantStack<T> &operator=(const MutantStack<T> &other);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};
```

### Behavior

- `MutantStack` retains all of the normal `std::stack` functionality (`push`, `pop`, `top`, `empty`, `size`).
- It additionally exposes `begin()` and `end()` iterators so the stack can be iterated like any other STL container.
- The iterators traverse the underlying container from bottom to top.

### Key concepts

| Concept | Detail |
|---|---|
| `std::stack` internals | `std::stack` wraps another container (by default `std::deque`) accessible as the protected member `c`. |
| `container_type` | The `typedef` that identifies the underlying container; use it to get the correct `iterator` type. |
| Inheritance | Public inheritance from `std::stack<T>` gives access to the protected member `c`. |
| Iterability | Exposing `begin()` / `end()` makes range-based algorithms and loops work on the stack. |

### Example

```cpp
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl; // 17
mstack.pop();
std::cout << mstack.size() << std::endl; // 1

mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);

MutantStack<int>::iterator it  = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
while (it != ite) {
    std::cout << *it << std::endl; // prints 5 3 5 737 0 (bottom to top)
    ++it;
}
```

---

## Summary of Key STL Tools Used

| Tool | Header | Purpose |
|---|---|---|
| `std::find` | `<algorithm>` | Search for a value in a range |
| `std::sort` | `<algorithm>` | Sort elements in a container |
| `std::min_element` | `<algorithm>` | Find the smallest element |
| `std::max_element` | `<algorithm>` | Find the largest element |
| `std::vector` | `<vector>` | Dynamic array, random-access container |
| `std::list` | `<list>` | Doubly-linked list |
| `std::stack` | `<stack>` | LIFO stack adaptor |
| Iterators | — | Uniform interface for traversing containers |
