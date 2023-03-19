//
// Created by Kevin Di nocera on 3/18/23.
//
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& origin)
{
	*this = origin;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & origin)
{
	this->_map = origin._map;
	return *this;
}

void	BitcoinExchange::init_csv(void)
{
	std::ifstream csv("data.csv");
	std::string read;
	float nb = 0.0;
	size_t size;

	/* Getline put the line in the string read*/
	while(std::getline(csv, read))
	{
		/* We verify if read doesn't contain the string "date,exchange_rate"*/
		if (read != "date,exchange_rate")
		{
			/* Find the "," character and we put the emplacement in size.*/
			size = read.find(',');
			/* With the size, whe extract the number in the string and convert it in float with
			 * the function std::istringstream. */
			std::istringstream(read.substr(size + 1, read.length())) >> nb;
			/* We stock the float in our map containers. */
			_map[read.substr(0, size)] = nb;
		}
	}
}
//
int	BitcoinExchange::data_base(const char *av)
{
	if (!av)
		return (1);
	std::ifstream infile(av);
	if (!infile.is_open()) {
		std::cerr << "failed to open file." << std::endl;
		return (1);
	}
	std::string read;
	size_t size;
	float nb = 0.0;
	std::map<std::string, float>::const_iterator it;
	while(std::getline(infile, read)) {
		if (read != "date | value") {
			if ((size = read.find('|')) >= read.size()) {
				std::cout << "Error: No separation pipe in file" << std::endl;
				continue;
			}
			if ((read[size - 1] != ' ') || (read[size - 2] == ' ')) {
				std::cout << "Error: Wrong format of datum." << std::endl;
				continue;
			}
			std::string key = read.substr(0, size - 1);
			std::string value = read.substr(size + 1, read.size());
			if (value.find("-") == 1) {
				std::cout << "Error: Value is negative" << std::endl;
				continue;
			}
			std::istringstream(read.substr(size + 1, read.length())) >> nb;
			if (nb > 1000) {
				std::cout << "Error: Value is higher as 1000" << std::endl;
				continue;
			}
			if (_map.find(key) == _map.end()) {
				float i;
				for (it = _map.begin(); it != _map.end(); ++it) {
					if (it->first >= key) {
						it--;
						break;
					}
				}
				i = it->second;
				i *= nb;
 				std::cout << it->first << " | " << i << std::endl;
//				std::cout << "Date: " << it->first << " Taux de change: " << it->second << std::endl;
			}
			else {
				float i;
				i = it->second;
				i *= nb;
				std::cout << key << " | " << i << std::endl;
			}
		}
	}
	return (0);
}

BitcoinExchange::~BitcoinExchange() {}