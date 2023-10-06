#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include <string.h>
# include "Form.hpp"

class Form;

class Bureaucrat
{

    private:

        const std::string  _name;
        int               _grade;

    public:

        Bureaucrat();
        Bureaucrat(const std::string name, int range);
        Bureaucrat(const Bureaucrat &Bureaucrat);
        Bureaucrat& operator= (const Bureaucrat &Bureaucrat);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void gradeInc();
        void gradeDec();
        void signForm(Form& form);

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
};
    std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif