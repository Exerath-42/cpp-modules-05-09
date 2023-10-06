#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat bob("bob", 50);
	Bureaucrat chad("chad", 1);

	Form form_n_1376("form_n_1376", 100, 101);
	Form mr_presedent_impeachment("mr_presedent_impeachment", 1, 2);

	std::cout << std::endl;
	std::cout << form_n_1376 << std::endl << std::endl;

	std::cout << mr_presedent_impeachment << std::endl << std::endl;

	std::cout << "______________1_____________" << std::endl;
	try
	{
		form_n_1376.beSigned(bob);
		bob.signForm(form_n_1376);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________2_____________" << std::endl;
	try
	{
		mr_presedent_impeachment.beSigned(bob);
		bob.signForm(mr_presedent_impeachment);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________3_____________" << std::endl;
	try
	{
		form_n_1376.beSigned(chad);
		chad.signForm(form_n_1376);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________4_____________" << std::endl;
	try
	{
		mr_presedent_impeachment.beSigned(chad);
		chad.signForm(mr_presedent_impeachment);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________5_____________" << std::endl;
	bob.signForm(mr_presedent_impeachment);
	std::cout << std::endl << std::endl;
}