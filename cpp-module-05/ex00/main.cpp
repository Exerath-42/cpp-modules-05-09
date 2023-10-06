#include "Bureaucrat.hpp"

int main()
{
	std::cout << "______________1_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 42);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;



	std::cout << "______________2_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 150);
		std::cout << bob << std::endl;
		std::cout << "Try to descrise." << std::endl;
		bob.gradeDec();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;



	std::cout << "______________3_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 1);
		std::cout << bob << std::endl;
		std::cout << "Try to incrise." << std::endl;
		bob.gradeInc();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;



	std::cout << "______________4_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 10);
		std::cout << bob << std::endl;
		std::cout << "Try to incrise." << std::endl;
		bob.gradeInc();
		std::cout << bob << std::endl;
		std::cout << "Try to descrise." << std::endl;
		bob.gradeDec();
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;


	std::cout << "______________5_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 151);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	
	
	std::cout << "______________6_____________" << std::endl;
	try
	{
		Bureaucrat bob("bob", 0);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
}