#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called." << std::endl;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	(void)rhs;
	return (*this);
}

static Form	*new_robot(std::string target)
{
	Form	*robot = new RobotomyRequestForm(target);
	return (robot);
}

static Form	*new_pres(std::string target)
{
	Form	*pres = new PresidentialPardonForm(target);
	return (pres);
}

static Form	*new_shrub(std::string target)
{
	Form	*shrub = new ShrubberyCreationForm(target);
	return (shrub);
}

const char* Intern::NonExistentForm::what() const throw()
{
	return "NonExistentForm : Unknown Form exception!";
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	Form	*(*fct[3])(std::string target) = { new_shrub, new_robot, new_pres};
	std::string	msg[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	Form	*ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (form_name == msg[i])
			ret = fct[i](form_target);
	}
	if (ret)
		std::cout << "Intern creates:"<< std::endl << "{"<< std::endl << *ret << "}"<< std::endl;
	else
		throw (Intern::NonExistentForm());
	return (ret);
}


Intern::~Intern()
{
    std::cout << "Intern destructor called." << std::endl;
}