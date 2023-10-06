#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  Form("Shurb", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	this->_target = rhs.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedInfo() == false)
		throw (Form::UnsignedFormException());
	if (executor.getGrade() > getExecuteGrade())
		throw (Form::GradeTooLowException());

	std::string	tree = 
	"                                           .\n" 		 
	"                                    .         ;  \n" 	 
	"       .              .              ;%     ;;   \n" 	 
	"          ,           ,                :;%  %;   \n" 	 
	"          :         ;                   :;%;'     ., \n"    
	" ,.        %;     %;            ;        %;'    ,;\n" 	 
	"   ;       ;%;  %%;        ,     %;    ;%;    ,%'\n" 	 
	"    %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" 	 
	"     ;%;      %;        ;%;        % ;%;  ,%;'\n" 		 
	"      `%;.     ;%;     %;'         `;%%;.%;'\n" 		 
	"       `:;%.    ;%%. %@;        %; ;@%;%'\n" 			 
	"         `:%;.  :;bd%;          %;@%;'\n" 				 
	"           `@%:.  :;%.         ;@@%;'   \n" 			 
	"             `@%.  `;@%.      ;@@%;         \n" 		 
	"               `@%%. `@%%    ;@@%;        \n" 			 
	"                 ;@%. :@%%  %@@%;       \n"			 
	"                   %@bd%%%bd%%:;     \n" 				 
	"                     #@%%%%%:;;\n" 					 
	"                      %@@%%%::;\n" 						 
	"                     %@@@%(o);  . '         \n" 		 
	"                      %@@@o%;:(.,'         \n" 			 
	"                  `.. %@@@o%::;         \n" 			 
	"                     `)@@@o%::;         \n" 			 
	"                      %@@(o)::;        \n" 				 
	"                     .%@@@@%::;         \n" 			 
	"                     ;%@@@@%::;.          \n" 			 
	"                    ;%@@@@%%:;;;. \n" 					 
	"                ...;%@@@@@%%:;;;;,..   ";
	char *tmp = new char[_target.size() + 1];
	std::string fileName = _target;
	fileName.append("_shrubbery");

	std::copy(fileName.begin(), fileName.end(), tmp);

	std::ofstream out(tmp);
	out << tree;
	delete []tmp;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}