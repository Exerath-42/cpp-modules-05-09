#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(0), _signGrade(150), _executeGrade(150)
{
	std::cout << "Form constructor called." << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
    std::cout << "Form constructor called." << std::endl;
}

Form::Form(const Form &form) : _name(form._name), _isSigned(form._isSigned), _signGrade(form._signGrade), _executeGrade(form._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &form)
{
	std::cout << "Form assignment constructor called" << std::endl;
	_isSigned = form._isSigned;
	return (*this);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignedInfo() const
{
	return (this->_isSigned);
}

int	Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecuteGrade() const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getSignGrade())
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->getName() << " can be signed by " << bureaucrat.getName() << std::endl;
	this->_isSigned = 1;
}



std::ostream &operator<<(std::ostream &out, const Form &rhs)
{
	out << "	Form name: " << rhs.getName() << std::endl << "	Is signed: " << rhs.getSignedInfo() << \
	std::endl << "	Sign grade: " << rhs.getSignGrade() << std::endl << "	Execute grade: " << \
	rhs.getExecuteGrade() << std::endl;

	return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException : Grade too height!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException : Bureaucrat grade too low for signing!";
}

const char* Form::UnsignedFormException::what() const throw()
{
	return "UnsignedFormException : Cannot execute an unsigned form!";
}

Form::~Form()
{
    std::cout << "Form destructor called." << std::endl;
}