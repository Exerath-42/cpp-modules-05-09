#include "RevPolishNotation.hpp"

void ft_error(std::string err)
{
    std::cout << err << std::endl;
    exit(1);
}

bool checkLine(char *line)
{
    char allowed[] = "1234567890+-*/ ";
    int count = 0;

    for (int b = 0; b < (int)strlen(line); b++)
    {
        for (int i = 0; i < 15; i++)
        {
            if (line[b] == allowed[i])
                count++;
        }
    }
    if (count == (int)strlen(line))
        return true;
    else
        return false;
}

int main(int argc, char  **argv)
{
    if (argc != 2)
        ft_error("Error: wrong argument number");
    if (!checkLine(argv[1]))
        ft_error("Error: wrong character");
    RevPolishNotation RPN(argv[1]);
}