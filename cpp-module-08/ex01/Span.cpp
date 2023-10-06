#include "Span.hpp"

Span::Span(unsigned int st_size)
{
	this->st_size = st_size;
    std::cout << "Span constructor called." << std::endl;
}

Span::Span(const Span &span)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = span;
}

Span &Span::operator=(const Span &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	if (this == &rhs)
	this->st_size = rhs.st_size;
	this->storage = rhs.storage;
	return (*this);
}

int Span::getEl(unsigned int i)
{
	if (i < this->st_size)
		return this->storage[i];
	else
		throw std::runtime_error("Index bigger then storage size");

}

int	Span::shortestSpan( void ) const
{
	std::vector<int>			tmp = storage;
	int							res = -1;
	std::vector<int>::iterator	it;

	if (storage.size() <= 1)
		throw std::runtime_error("Storage is empty or only 1 item saved");
	sort(tmp.begin(), tmp.end());
	res = *(tmp.begin() + 1) - *tmp.begin();
	if (this->size() == 2)
		return res;
	for (it = tmp.begin() + 1; it != tmp.end() - 1 && res != 0; it++)
	{
		if (*(it + 1) - *it < res)
			res = *(it + 1) - *it;
	}
	return res;
}

int	Span::longestSpan( void ) const
{
	std::vector<int> tmp = this->storage;

	if (storage.size() <= 1)
		throw std::runtime_error("Storage is empty or only 1 item saved");
	sort(tmp.begin(), tmp.end());
		return *(tmp.end() - 1) - *tmp.begin();
}

std::ostream &operator<<( std::ostream & ostr, Span const & instance)
{
	int	shortest = instance.shortestSpan();
	int	longest = instance.longestSpan();

	ostr << "Span of max size " << instance.maxSize() << " contains "
		<< instance.size() << " numbers, shortest span is "
		<< shortest << " and longest is " << longest;
	return ostr;
}

unsigned int Span::size( void ) const
{
	return this->storage.size();
}

void Span::addNumber(int number)
{
	if (storage.size() == st_size)
		throw std::runtime_error("Storage already full");

	else
		storage.push_back(number);
}

void Span::addByIteratorRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int> tmp(begin, end);

	if (tmp.size() > this->spaceLeft())
		throw std::runtime_error("Cannot add any more numbers");
	copy(tmp.begin(), tmp.end(), std::back_inserter(this->storage));
}


unsigned int Span::maxSize( void ) const
{
	return this->st_size;
}

unsigned int Span::spaceLeft( void ) const
{
	return maxSize() - size();
}

Span::~Span()
{
    std::cout << "Span destructor called." << std::endl;
}