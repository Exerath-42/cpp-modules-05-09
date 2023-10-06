#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{

    private:

        unsigned int        st_size;
        std::vector<int>    storage;

    public:

        Span(unsigned int size);
        Span(const Span &Span);
        Span& operator= (const Span &rhs);

        const Span& operator[](unsigned int i ) const;
        int	shortestSpan( void ) const;
        int	longestSpan( void ) const;
        void addNumber(int number);
        int getEl(unsigned int i);
        unsigned int size( void ) const;
        unsigned int maxSize( void ) const;
        unsigned int spaceLeft( void ) const;
        void addByIteratorRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        ~Span();

};
    std::ostream &	operator<<( std::ostream & ostr, Span const & instance);

#endif