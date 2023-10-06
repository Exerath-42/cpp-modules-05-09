#include "RevPolishNotation.hpp"

RevPolishNotation::RevPolishNotation()
{
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c== '*' || c == '/')
		return true;
	else
		return false;
}

RevPolishNotation::RevPolishNotation(char *line)
{
	int a,b;

	for (int i = 0; i < (int)strlen(line); i++)
	{
		if (isdigit(line[i]))
			stack.push(line[i] - '0');
		else if (isOperator(line[i]) && stack.size() >= 2)
		{
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			switch (line[i])
			{
				case '+':
					stack.push(b + a);
					break;
				case '-':
					stack.push(b - a);
					break;
				case '*':
					stack.push(b * a);
					break;
				case '/':
					stack.push(b / a);
					break;

			}
		}
		else if (isOperator(line[i]) && stack.size() < 2)
		{
			ft_error("Error: Wrong line");
		}
	}
	std::cout << "result: " << stack.top() << std::endl;
}

RevPolishNotation::RevPolishNotation(const RevPolishNotation &revpolishnotation)
{
	*this = revpolishnotation;
}

RevPolishNotation &RevPolishNotation::operator=(const RevPolishNotation &rhs)
{
	this->stack = rhs.stack;
	return (*this);
}

RevPolishNotation::~RevPolishNotation()
{
}