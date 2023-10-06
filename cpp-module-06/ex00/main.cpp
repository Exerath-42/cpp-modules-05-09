#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong argument number!" << std::endl;
		return (1);
	}
	
	Convert convert(argv[1]);
	
	try
	{
		convert.converter();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}