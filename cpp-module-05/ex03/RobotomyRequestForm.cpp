#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :  Form("Robot", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedInfo() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > getExecuteGrade())
		throw (Form::GradeTooLowException());


	std::cout << "*some drilling noises*" << std::endl;
	srand(time(NULL));
	int i = rand();
	if (i % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}