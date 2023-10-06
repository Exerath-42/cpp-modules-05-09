#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    std::cout << std::endl << "________________________My tests________________________" << std::endl << std::endl;

	Array<int> test_array(20);

	for (size_t i = 0; i <= 21; i++)
	{
		try
		{
			test_array[i] = 20 - i;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Wrong index [" << i << "] " << e.what() << '\n';
		}
	}

        try
		{
			test_array[-2] = 123;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Wrong index [-2] " << e.what() << '\n';
		}

	for (size_t i = 0; i < 20; i++)
	{
		std::cout << "Value of [" << i << "] is: " << test_array[i] << std::endl;
	}

    delete [] mirror;
    return 0;
}
