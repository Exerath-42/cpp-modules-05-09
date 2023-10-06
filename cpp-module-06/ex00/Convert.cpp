#include "Convert.hpp"
#include <string> 

Convert::Convert(char * input)
{
	this->input = input;
	this->type = 0;
	this->int_imp = 0;
	this->fl_imp = 0;
    std::cout << "Convert constructor called." << std::endl;
}

Convert::Convert(const Convert &convert)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = convert;
}

Convert &Convert::operator=(const Convert &rhs)
{
	std::cout << "Assignment constructor called" << std::endl;
	this->input = rhs.input;
	this->type = rhs.type;
	return (*this);
}

bool	canConvertToChar(double number)
{
	if (number - static_cast<int>(number) != 0 || number > 127 || number < 0)
		std::cout << "Char:	Impossible" << std::endl;
	else if (number <= 31 || number == 127)
		std::cout << "Char:	Non displayable" << std::endl;
	else
		return 1;
	return 0;
}

const char	*printDotZero(double n)
{
	if (n - static_cast<int>(n) == 0.0)
		return (".0");
	return ("");
}

bool	canConvertToInt(double value)
{
	return (value <= std::numeric_limits<int>::max() && value >= std::numeric_limits<int>::min() 
			&& value != std::numeric_limits<double>::infinity() && value != -std::numeric_limits<double>::infinity() 
			&& value != std::numeric_limits<double>::quiet_NaN());
}

bool	canConvertToFloat(double value)
{
	return ((value <= std::numeric_limits<float>::max() && value >= -std::numeric_limits<float>::max()) 
			|| value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity() 
			|| std::isnan(value));
}

void Convert::print_float()
{
	if(this->type == 1)
		std::cout << "Float:	" << static_cast<float>(this->c_value) << ".0f" << std::endl;
	if(this->type == 2)
		std::cout << "Float:	" << static_cast<float>(this->i_value) << ".0f" << std::endl;
	if(this->type == 3)
		std::cout << "Float:	" << this->f_value  << printDotZero(static_cast<float>(this->f_value)) << "f" << std::endl;
	if(this->type == 4)
	{
		if (canConvertToFloat(this->d_value))
			std::cout << "Float:	" << static_cast<float>(this->d_value)  << printDotZero(static_cast<float>(this->f_value)) << "f" << std::endl;
		else
			std::cout << "Float:	Impossible" << std::endl;
	}
}

void Convert::print_int()
{
	if(this->type == 1)
		std::cout << "Int:	" << static_cast<int>(this->c_value) << std::endl;
	if(this->type == 2)
		std::cout << "Int:	" << this->i_value << std::endl;
	if(this->type == 3)
	{
		if (canConvertToInt(this->f_value))
			std::cout << "Int:	" << static_cast<int>(this->f_value) << std::endl;
		else
			std::cout << "Int:	Impossible" << std::endl;
	}
	if(this->type == 4)
	{
		if (canConvertToInt(this->d_value))
			std::cout << "Int:	" << static_cast<int>(this->d_value) << std::endl;
		else
			std::cout << "Int:	Impossible" << std::endl;
	}
}

void Convert::print_double()
{
	if(this->type == 1)
		std::cout << "Double:	" << static_cast<double>(this->c_value) << ".0" << std::endl;
	if(this->type == 2)
		std::cout << "Double:	" << static_cast<double>(this->i_value) << ".0" << std::endl;
	if(this->type == 3)
		std::cout << "Double:	" << static_cast<double>(this->f_value) << printDotZero(static_cast<float>(this->f_value)) << std::endl;
	if(this->type == 4)
		std::cout << "Double:	" << this->d_value << printDotZero(static_cast<float>(this->d_value)) << std::endl;
}

void Convert::print_char()
{

	if(this->type == 1)
	{
		std::cout << "Char:	'" << static_cast<char>(this->c_value) << "'" << std::endl;
	}
	if(this->type == 2)
	{
		if (canConvertToChar((double)this->i_value))
			std::cout << "Char:	'" << static_cast<char>(this->i_value)<< "'" << std::endl;
	}
	if(this->type == 3)
	{
		if (canConvertToChar((double)this->f_value))
			std::cout << "Char:	'" << static_cast<char>(this->f_value) << "'" << std::endl;
	}
	if(this->type == 4)
	{
		if (canConvertToChar(this->d_value))
			std::cout << "Char:	'" << static_cast<char>(this->d_value) << "'" << std::endl;
	}
}

void Convert::getInputValue()
{
	if (type == 1)
		this->c_value = this->input[0];
	if (type == 2)
		this->i_value = atoi(this->input);
	if (type == 3)
		this->f_value = atof(this->input);
	if (type == 4)
		this->d_value = atof(this->input);
}

void Convert::converter()
{
	selectType();
	getInputValue();
	print_char();
	print_int();
	print_float();
	print_double();
}

int		numeric_case(char *input)
{
	int	i = 0;
	int	dotCnt = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
		return (0);
	while (input[i] == '.' || isdigit(input[i]))
	{
		if (input[i] == '.')
			dotCnt++;
		if (input[i] == '.' && !input[i + 1])	
			return 2;
		if (dotCnt > 1)
			return 0;
		i++;
	}
	if (!input[i])
	{
		if (dotCnt == 1)
			return 4;
		return 2;
	}
	else if (input[i] == 'f' && !input[i + 1] && dotCnt == 1)
		return 3;
	return 0;
}

int		special_case(char *input)
{
	const std::string	special_doubles[] =
	{
		"inf", "+inf", "-inf", "nan"
	};
	const std::string	special_floats[] =
	{
		"inff", "+inff", "-inff", "nanf"
	};

	for (int i = 0; i < 4; i++)
	{
		if (special_doubles[i] == input)
			return 4;
		else if (special_floats[i] == input)
			return 3;
	}
	return 0;
}

void Convert::selectType()
{
	double tmp = atof(this->input);;
	if (!std::isinf(tmp) && !std::isnan(tmp) && (tmp > INT_MAX || tmp < INT_MIN))
		throw std::runtime_error("Impossible");
	this->type = special_case(this->input);
	if (type != 0)
		return ;
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-' || input[0] == '.')
	{
		this->type = numeric_case(this->input);
		if (this->type != 0)
			return ;
	}
	if (input[1])
		throw std::runtime_error("Wrong input!");
	this->type = 1;
}

void Convert::print()
{
	std::cout << "Char:		" << std::endl;
	std::cout << "Int:		" << this->i_value << std::endl;
	std::cout << "Float:		" << this->f_value << std::endl;
	std::cout << "double:		" << this->d_value << std::endl;
}

Convert::~Convert()
{
    std::cout << "Convert destructor called." << std::endl;
}