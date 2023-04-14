//
// Created by Kevin Di nocera on 4/2/23.
//
#include <stdio.h>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const& src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	this->_v = src._v;
	this->_l = src._l;
	return (*this);
}

void	print_av(char **av, std::vector<int> number, int id)
{
	if (id == 1) {
		for (int i = 0; av[i]; ++i)
			std::cout << "av[" << i << "] = " << av[i] << std::endl;
	}
	if (id == 2) {
		for (size_t it = 0; it < number.size(); ++it)
			std::cout << "it[" << it << "] = " << number[it] << std::endl;
	}
}

int PmergeMe::check_args_is_digit(char **av, int ac)
{
	std::string 		tmp;

	for (int it = 1; av[it]; ++it) {
		tmp = av[it];
		if (ac > 2) {
			if (tmp.find_first_not_of("0123456789") != std::string::npos) {
				if (strchr(tmp.c_str(), '-'))
					std::cerr << "error: digit must be positive => ";
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
		else {
			if (tmp.find_first_not_of("0123456789 ") != std::string::npos) {
				if (strchr(tmp.c_str(), '-'))
					std::cerr << "error: digit must be positive => ";
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

std::vector<int> stock_1_string(char **av, std::vector<int> tab_num)
{
	std::stringstream	ss;
	int					num;

	for (int i = 1; av[i]; ++i)
		ss << av[i];
	while (ss >> num)
		tab_num.push_back(num);
	return (tab_num);
}

std::vector<int> stock_many_strings(char **av, std::vector<int> tab_num)
{
	for (int i = 1; av[i]; i++)
		tab_num.push_back(std::atoi(av[i]));
	return (tab_num);
}

void	PmergeMe::stock_args_string(char **av, int ac)
{
	std::vector<int> 	numbers;

	if (ac == 2)
		numbers = stock_1_string(av, numbers);
	else
		numbers = stock_many_strings(av, numbers);
	this->_v = numbers;
}

int	PmergeMe::check_input(char *src)
{
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

void PmergeMe::sort_sequence(std::vector<int>& v, std::list<int>& l)
{
	clock_t start_time = clock();
	std::sort(v.begin(), v.end());
	clock_t end_time = clock();
	double time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	std::cout << "Sort time using vector: " << time << " seconds" << std::endl;

	start_time = clock();
	l.sort();
	end_time = clock();
	time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	std::cout << "Sort time using list: " << time << " seconds" << std::endl;
}

void PmergeMe::display_sequence_vector(const std::vector<int>& v, const std::string& title)
{
	std::cout << title << ": ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::display_sequence_list(const std::list<int>& v, const std::string& title)
{
	std::cout << title << ": ";
	for (std::list<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe(void) {}