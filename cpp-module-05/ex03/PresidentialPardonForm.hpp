#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{

    private:

        std::string _target;

    public:

        virtual void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;

        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator= (const PresidentialPardonForm &rhs);
        ~PresidentialPardonForm();

};

#endif