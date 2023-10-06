#include "easyfind.hpp"

template<typename T>
void	displayIterator( T it, T end )
{
	if (it != end)
		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

int	main( void )
{
	std::vector<int>			vector;
	std::vector<int>::iterator	iter;

	for (int i = 0; i < 100; i++)
		vector.push_back(i);
	iter = easyfind(vector, 5);
	displayIterator(iter, vector.end());
	iter = easyfind(vector, 55);
	displayIterator(iter, vector.end());
	iter = easyfind(vector, -10);
	displayIterator(iter, vector.end());
	iter = easyfind(vector, 99);
	displayIterator(iter, vector.end());
	iter = easyfind(vector, 100);
	displayIterator(iter, vector.end());
}