//
// Created by Kevin Di nocera on 4/2/23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const& src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	this->_vector = src._vector;
	return (*this);
}

int	PmergeMe::check_input(char *src) {
	std::stringstream ss(src);
	std::string test;
	char		*end;
	long 		converted;
	std::cout << src << std::endl;

	while (ss >> test) {
		std::cout << test << std::endl;

		if (!(converted = strtol(test.c_str(), &end, 10))) {
			std::cout << "error: " << test << std::endl;
			return (1);
		}
	}
	return (0);
}

PmergeMe::~PmergeMe(void) {}