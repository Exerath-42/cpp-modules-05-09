#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <climits>


class BitcoinExchange
{

    private:

        bool                            _error;
        std::map<int, double>   _data;
        std::vector<int>      _inputData;
        std::vector<double>      _inputIndex;

    public:

        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &BitcoinExchange);
        BitcoinExchange& operator= (const BitcoinExchange &BitcoinExchange);
        ~BitcoinExchange();

        int error(std::string description);
        std::vector<std::string> getFile(std::string filename);
        void result();



};

std::vector<std::string> ft_split(const std::string &str, const std::string &charset);


#endif