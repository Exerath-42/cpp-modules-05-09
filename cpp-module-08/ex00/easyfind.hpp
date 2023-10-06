#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


template < typename T >
typename T::iterator easyfind(T &cont, int elem_to_find)
{
	typename T::iterator res = find(cont.begin(), cont.end(), elem_to_find);

	if (res == cont.end())
		return cont.end();
	return
		res;
}

#endif