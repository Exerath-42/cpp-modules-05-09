#include "BitcoinExchange.hpp"

bool isValidData(std::string str)
{
	std::vector<std::string> line = ft_split(str, "-");
	
	if (line.size() !=3)
		return 0;
	else if (line[0].size() != 4)
		return 0;
	else if (line[1].size() != 2 && (line[1].size() > 12 || line[1].size() < 1))
		return 0;
	else if (line[2].size() != 2 && (line[2].size() > 31 || line[2].size() < 1))
		return 0;
	else
		return 1;
}

int data_convert(std::string data)
{
	std::vector<std::string>file = ft_split(data, "-");
	std::string res = "";
	std::vector<std::string>::iterator vecEnd = file.end();

	for(std::vector<std::string>::iterator vecBegin = file.begin(); vecBegin != vecEnd; vecBegin++)
	{
		res.append(*vecBegin);
	}
	return(atof(res.c_str()));
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::string tmp = getFile("./data.csv")[0];
	std::vector<std::string>file = ft_split(tmp, "\n");
	std::vector<std::string>::iterator vecEnd = file.end();

	for(std::vector<std::string>::iterator vecBegin = ++file.begin(); vecBegin != vecEnd; vecBegin++)
	{
		std::string tmp = *vecBegin;
		std::vector<std::string> line = ft_split(tmp, ",");
		if (line[0] != "data")
		{
			if (line.size() != 2)
				error("Error: wrong file content");
			if (!isValidData(line[0]))
				error("Error: wrong file content");
			_data.insert(std::pair<int,double >(data_convert(line[0]),atof(line[1].c_str())));
		}
	}
	std::string tmp2 = getFile(filename)[0];
	// if (tmp2.size() < 1)
	// 	error("Error: empty file");
	std::vector<std::string>file2 = ft_split(tmp2, "\n");

	std::vector<std::string>::iterator vecEnd2 = file2.end();

	for(std::vector<std::string>::iterator vecBegin = file2.begin(); vecBegin != vecEnd2; vecBegin++)
	{
		std::string tmp2 = *vecBegin;
		std::vector<std::string> line = ft_split(tmp2, " | ");
		if (line.size() != 2)
			error("Error: wrong file content");
		if (!isValidData(line[0]))
			error("Error: wrong file content");
		_inputData.push_back(data_convert(line[0]));
		_inputIndex.push_back(atof(line[1].c_str()));
	}
	result();
}



BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
	*this = bitcoinexchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	this->_error = rhs._error;
	return (*this);
}

int BitcoinExchange::error(std::string description)
{
	this->_error = 1;
	std::cout << description << std::endl;
	exit(1);
	return (1);
}

BitcoinExchange::~BitcoinExchange()
{
}

bool isValidNum (double num)
{
	if (num < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	else if (num > 1000)
	{
		std::cout << "Error: number is bigger than 1000." << std::endl;
		return 0;
	}
	else
		return 1;
}

bool isValidDataInt(int data)
{
	if (data < 20090102)
	{
		std::cout << "Error: date too early." << std::endl;
		return 0;
	}
	else
		return 1;
}

int day(int data)
{
	return (data % 100);
}

int month(int data)
{
	return (data % 10000 / 100);
}

int rollData(int data)
{
	if (data % 100 > 1)
	{
		return (data - 1);
	}
	else if (data % 10000 / 100 > 1)
	{
		return (data - 100 + 30);
	}
	else
	{
		return (data - 10000 + 1100 + 30);
	}
}

void print_data(int date)
{
	std::cout << date / 10000 << "-";
	std::cout << date % 10000 / 100 << "-";
	std::cout << date % 100;
}

void BitcoinExchange::result()
{
	int tmp;
	long double res;
	std::vector<int>::iterator vecDataEnd = this->_inputData.end();
	std::vector<double>::iterator vecIndexStart = this->_inputIndex.begin();
	for (std::vector<int>::iterator vecDataStart = _inputData.begin(); vecDataStart != vecDataEnd; vecDataStart++, vecIndexStart++)
	{
		if (isValidNum(*vecIndexStart) && isValidDataInt(*vecDataStart))
		{
			tmp = *vecDataStart;
			while(_data.find(tmp) == _data.end())
			{
				tmp = rollData(tmp);
			}
			res = *vecIndexStart * _data.find(tmp)->second;
			print_data(*vecDataStart);
			std::cout << " => " << *vecIndexStart << " = " <<  res << std::endl;
		}
	}

}

std::vector<std::string> BitcoinExchange::getFile(std::string filename)
{
	std::string str;
	std::ifstream file;
	file.open(filename.c_str());

	if (!file)
		error("Error: the file was not opened");
	if  (file.peek() == std::ifstream::traits_type::eof())
		error("Error: file is empty");
	std::vector<std::string> content;
	
	while (getline (file, str, '\0'))
	{
		content.push_back(str);
	}
	file.close();
	return (content);
}

bool	ft_in_charset(char const c, const std::string &charset)
{
	int	i_charset;

	i_charset = 0;
	while (charset[i_charset])
	{
		if (c == charset[i_charset++])
			return true;
	}
	return false;
}

std::vector<std::string> ft_split(const std::string &str, const std::string &charset)
{
	std::vector<std::string> res;
	std::string			tmp;
	unsigned long		i;

	i = 0;
	while (i < str.length())
	{
		while (i < str.length() && ft_in_charset(str[i], charset))
			i++;
		if (i < str.length())
		{
			tmp = "";
			while (i < str.length() && !ft_in_charset(str[i], charset))
				tmp += str[i++];
			res.push_back(tmp);
		}
	}
	return res;
}