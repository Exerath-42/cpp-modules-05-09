#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include <time.h> 
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{

    private:

        std::string _target;

    public:
    
        virtual void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;

        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator= (const RobotomyRequestForm &rhs);
        ~RobotomyRequestForm();
        

};

#endif