#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat assignment constructor called" << std::endl;
	this->_grade = bureaucrat._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::gradeInc()
{
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::gradeDec()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException : Grade too height!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException : Grade too low!";
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSignGrade() < getGrade())
		std::cout << getName() << " couldn't sign " << form.getName() << \
		" because his grade is too low " <<std::endl;
	else if (form.getSignedInfo() == 1)
		std::cout << getName() << " signed " << form.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (out);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called." << std::endl;
}