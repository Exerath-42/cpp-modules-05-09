#ifndef FORM_HPP
#define FORM_HPP
# include <iostream>
# include <exception>
# include <cstdlib>
# include <time.h>
# include <fstream>
# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

    private:

        const std::string   _name;
        bool                _isSigned;
        const int           _signGrade;
        const int           _executeGrade;

    public:

        std::string getName() const;
        bool        getSignedInfo() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;
        void		beSigned(const Bureaucrat& bureaucrat);
        void        signForm();

        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form &Form);
        Form& operator= (const Form &Form);
        virtual ~Form();
        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception
	    {
	        public:

		        virtual const char* what() const throw();
	    };

        class GradeTooLowException : public std::exception
	    {
	        public:

		        virtual const char* what() const throw();
	    };

        class UnsignedFormException : public std::exception
	    {
	        public:

		        virtual const char* what() const throw();
	    };
};
    std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif