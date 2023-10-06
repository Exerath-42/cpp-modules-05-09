#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{

    private:

        std::string _target;

    public:

        virtual void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;

        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator= (const ShrubberyCreationForm &rhs);
        ~ShrubberyCreationForm();

};

#endif