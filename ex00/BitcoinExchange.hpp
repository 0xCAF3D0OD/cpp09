//
// Created by Kevin Di nocera on 3/18/23.
//

#ifndef CPP09_BITCOINEXCHANGE_HPP
#define CPP09_BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <string_view>
#include <sstream>

class	BitcoinExchange
{
private:
	std::map<std::string, float> _map;
public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	BitcoinExchange& operator=(BitcoinExchange const &rhs);

	void	init_csv(void);
	int 	data_base(char const *av);
	~BitcoinExchange(void);
};
#endif //CPP09_BITCOINEXCHANGE_HPP
