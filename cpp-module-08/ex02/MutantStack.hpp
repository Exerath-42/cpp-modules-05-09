#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>

template < typename T >
class MutantStack : public std::stack<T>
{
	public:

	MutantStack<T>(void) {std::cout << "MutantStack constructor" << std::endl;}
	MutantStack<T>(const MutantStack<T> &other) { *this = other; }
	~MutantStack<T>(void) {std::cout << "MutantStack destructor" << std::endl;}

	MutantStack<T> &operator=(const MutantStack<T> &rhs)
	{
		(void)rhs;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin( void ) { return this->c.begin(); }
	iterator	end( void ) { return this->c.end(); }
};

#endif