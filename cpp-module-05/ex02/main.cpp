#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robot("robotTarget");
	PresidentialPardonForm  pres("pres");
	Bureaucrat				bob("bob", 1);
	Bureaucrat				stan("stan", 149);

	std::cout << std::endl << std::endl;

	std::cout << "______________1_____________" << std::endl;

	bob.executeForm(robot);
	std::cout << std::endl << std::endl;

	std::cout << "______________2_____________" << std::endl;

	robot.beSigned(bob);
	bob.executeForm(robot);
	std::cout << std::endl << std::endl;

	std::cout << "______________3_____________" << std::endl;

	bob.executeForm(shrub);
	std::cout << std::endl << std::endl;

	std::cout << "______________4_____________" << std::endl;

	shrub.beSigned(bob);
	bob.executeForm(shrub);
	std::cout << std::endl << std::endl;

	std::cout << "______________5_____________" << std::endl;

	bob.executeForm(pres);
	std::cout << std::endl << std::endl;

	std::cout << "______________6_____________" << std::endl;
	
	pres.beSigned(bob);
	bob.executeForm(pres);
	std::cout << std::endl << std::endl;

	std::cout << "______________7_____________" << std::endl;
	stan.executeForm(robot);
	stan.executeForm(shrub);
	stan.executeForm(pres);
	std::cout << std::endl << std::endl;
	
}