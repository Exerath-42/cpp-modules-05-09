#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :  Form("Pres", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedInfo() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > getExecuteGrade())
		throw (Form::GradeTooLowException());


	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}