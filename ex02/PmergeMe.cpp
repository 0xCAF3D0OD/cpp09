//
// Created by Kevin Di nocera on 4/2/23.
//

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
		std::cout << "size = " << number.size() << std::endl;
		for (size_t it = 0; it < number.size(); ++it)
			std::cout << "it[" << it << "] = " << number[it] << std::endl;
	}
}

int check_args_is_digit(char **av, int ac)
{
	std::string 		tmp;

	for (int it = 1; av[it]; ++it) {
		tmp = av[it];
		if (ac != 2) {
			if (tmp.find_first_not_of("0123456789") != std::string::npos) {
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
		else {
			if (tmp.find_first_not_of("0123456789 ") != std::string::npos) {
				std::cerr << "error: is_digit:" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int	PmergeMe::check_args_string(char **av, int ac) {
	std::stringstream	ss;
	std::vector<int> 	numbers;
//	std::string 		space;
//	int					num;

	print_av(av, numbers, 1);
	if (check_args_is_digit(av, ac))
		return (1);

//	// arrays to integer
//	for (int i = 1; av[i]; ++i)
//		ss << av[i];
//	while (ss >> num)
//		numbers.push_back(num);
//	print_av(av, numbers, 2);
//	std::cout << numbers.size() << std::endl;
//	std::cout << ss.str().size() << " " << numbers.size() << std::endl;
//	for (ss >> space)
//	{
//		if (std::strcmp(space, " "))
//
//	}
//	if (ss.str().size() != numbers.size())
//	{
//		std::cerr << ss.str().size() << " " << numbers.size() << " string contain non digit elements" << std::endl;
//		return (1);
//	}
//	for (size_t i = 0; i < numbers.size(); ++i)
//		std::cout << numbers[i] << " ";
	return (0);
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

void PmergeMe::sort_sequence(std::vector<int>& v, std::list<int>& l) {
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

void PmergeMe::display_sequence_vector(const std::vector<int>& v, const std::string& title) {
	std::cout << title << ": ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::display_sequence_list(const std::list<int>& v, const std::string& title) {
	std::cout << title << ": ";
	for (std::list<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

PmergeMe::~PmergeMe(void) {}