//
// Created by Kevin Di nocera on 3/18/23.
//
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void) av;
	if (ac < 2) {
		std::cout << "Error: Could not open file" << std::endl;
		return (1);
	}
	BitcoinExchange test;
	test.init_csv();
	test.data_base(av[1]);
	return (0);
}

#include <cstring>
#include <iostream>

//int main()
//{
//	std::string old_date = "2011-11-12";
//	std::string new_date = "2011-01-01";
//
//	std::cout << old_date << std::endl;
//	std::cout << new_date << std::endl;
//
//	std::cout << "is new date bigger than old? :" << std::boolalpha << (new_date > old_date) << std::endl;
//	return 0;
//}

//
//int main() {
//	std::string str = "42";
//	std::istringstream iss(str);
//	int num;
//	iss >> num;
//	std::cout << "Le numéro extrait est : " << num << std::endl;
//	return 0;
//}