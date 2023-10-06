#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	std::cout << "__________________My tests__________________" << std::endl;

	Span span1(25);
	for (int i=0; i < 25; i++)
	{
		try
		{
			span1.addNumber(i*2);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << span1 << std::endl << std::endl;
	

	Span span2(20000);
	for (int i=0; i < 20000; i++)
	{
		try
		{
			span2.addNumber(i*2);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << span2 << std::endl << std::endl;

	Span span3(25000);
	std::vector<int>	vect;

	vect.push_back(1);
	vect.push_back(9);
	vect.push_back(-9);
	vect.push_back(123);
	vect.push_back(45);
	vect.push_back(112);
	vect.push_back(38);
	vect.push_back(0);

	span3.addByIteratorRange(vect.begin(),vect.end());
	std::cout << span3 << std::endl << std::endl;

	return 0;
}