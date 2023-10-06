#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arr, int size, void(*f)(T const &value))
{
    for (int i = 0; i < size; i++)
		(*f)(arr[i]);
}

template <typename T>
void print_element(T const &el)
{
    std::cout << el << std::endl;
}

#endif