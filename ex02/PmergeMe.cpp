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

	while (ss >> test) {
		if (!(converted = strtol(test.c_str(), &end, 10))) {
			std::cout << "error: " << test << std::endl;
			return (1);
		}
		if (std::strchr(test.c_str(), '-')) {
			std::cout << "must be positive" << std::endl;
			return (1);
		}
	}
	return (0);
}

void PmergeMe::mergeInSorte(char *src) {

	std::stringstream	ss(src);
	std::string 		input;
	std::vector<int>::iterator it;
	while (ss >> input)
		_vector.push_back(std::atoi(input.c_str()));
	for (it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << std::endl;
}

PmergeMe::~PmergeMe(void) {}