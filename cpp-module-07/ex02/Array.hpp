#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include <cstdlib>

template < typename T >
class Array
{

    private:

        T *array;
        unsigned int arr_size;

    public:

        Array() : array(new T(0)), arr_size(0) {};
        Array(unsigned int n) : array(new T[n]()), arr_size(n) {};
        Array(const Array &ohter) { *this = ohter; };
        Array& operator= (const Array &rhs)
        {
            if (this == &rhs)
				return (*this);

			if (arr_size != rhs.arr_size)
			{
				arr_size = rhs.arr_size;
				array = new T[arr_size];
			}
			for (size_t i = 0; i < rhs.arr_size; i++)
				array[i] = rhs.array[i];
			return (*this);
        };
		
        void size(){ return this->arr_size; };

        class OutofBounds: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("OutofBounds: The Index is Out of Bounds");
			}
		};

        class NegativeIndex: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("NegativeIndex: The Index is negative");
			}
		};

        T & operator[](long int n )
		{
			if (n < 0)
				throw Array::NegativeIndex();
			else if (arr_size <= n)
				throw Array::OutofBounds();
			return array[n];
		};

        const T & operator[](long int n ) const
		{
			if (n < 0)
				throw Array::NegativeIndex();
			else if (arr_size <= n)
				throw Array::OutofBounds();
			return array[n];
		};
        
        ~Array(){ delete this->array; };

};

#endif