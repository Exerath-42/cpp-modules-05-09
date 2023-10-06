#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Form;

class Intern
{
    public:

        Intern();
        Intern(const Intern &Intern);
        Intern& operator= (const Intern &rhs);
        ~Intern();

        Form *makeForm(std::string form_name, std::string form_target);
        
        class NonExistentForm : public std::exception
	    {
	        public:

		        virtual const char* what() const throw();
	    };
};

#endif