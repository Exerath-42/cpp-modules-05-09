#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Error: wrong argument number" << std::endl;
        return (1);
    }
    
    BitcoinExchange btc(argv[1]);
}