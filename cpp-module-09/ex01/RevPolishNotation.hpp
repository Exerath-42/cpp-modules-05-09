#ifndef REVPOLISHNOTATION_HPP
#define REVPOLISHNOTATION_HPP
#include <iostream>
#include <cstring>
#include <stack>
#include <stdlib.h>


class RevPolishNotation
{

    private:

        std::stack<int> stack;

    public:

        RevPolishNotation();
        RevPolishNotation(char *line);
        RevPolishNotation(const RevPolishNotation &RevPolishNotation);
        RevPolishNotation& operator= (const RevPolishNotation &RevPolishNotation);
        ~RevPolishNotation();

};

void ft_error(std::string err);

#endif