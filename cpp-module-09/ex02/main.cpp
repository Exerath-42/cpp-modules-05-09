#include "PmergeMe.hpp"

void ft_error(std::string err)
{
    std::cout << err << std::endl;
    exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error: Wrong argument number");
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; j < (int)strlen(argv[i]); j++)
		{
			if (!isdigit(argv[i][j]))
				ft_error("Error: Wrong argument: Only positive integers are allowed");
		}
	}
	PmergeMe InsertMerge(argc, argv);
}