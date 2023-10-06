#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	Form	*shurb_form;
	Form	*robot_form;
	Form	*pres_form;
	Form	*unknown;
	
	std::cout << std::endl << std::endl;

	std::cout << "______________1_____________" << std::endl;
	
	try
	{
		shurb_form = intern.makeForm("shrubbery creation", "shurb_by_intern");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________2_____________" << std::endl;
	
	try
	{
		robot_form = intern.makeForm("robotomy request", "robot_by_intern");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "______________3_____________" << std::endl;
	
	try
	{
		pres_form = intern.makeForm("presidential pardon", "pres_by_intern");
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;

	std::cout << "______________4_____________" << std::endl;

	try
	{
		unknown = intern.makeForm("unknown", "unknown_by_intern");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	
}