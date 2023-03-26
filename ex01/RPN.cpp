//
// Created by Kevin Di nocera on 3/26/23.
//
#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	this->stack = src.stack;
	return (*this);
}

int	RPN::check_arguments(std::string arg) {
	std::cout << "argument: " << arg << std::endl;
	std::stringstream ss(arg);
	std::stringstream sa;
	std::string word;
	int			i = 0;

	while (ss >> word) {
		if ((word.compare("+") != 0) && (word.compare("-") != 0)
			&& (word.compare("*") != 0) && (word.compare("/") != 0))
		{
			bool all_digits = true;
			for(size_t j = 0; j < word.size(); ++j)
			{
				if (!std::isdigit(word[j])) {
					all_digits = false;
					break ;
				}
			}
			if (!all_digits) {
				std::cerr << "string contain character" << std::endl;
				return (1);
			}
			sa << word;
			if ((sa >> i && (i > 9 || i < 0))) {
				std::cerr << "number is superior as 10 or less than 0" << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

int	RPN::operator_function(int first, int second, std::string operat) {
	int res = 0;

	if (!operat.compare("+"))
		res = first + second;
	else if (!operat.compare("-"))
		res = first - second;
	else if (!operat.compare("*"))
		res = first * second;
	else if (!operat.compare("/"))
		res = first / second;
	return (res);
}

int	RPN::calculus(std::string arg) {
	std::stringstream ss(arg);
	std::stringstream sa;
	std::string word;
	int	i = 0;
	int	j = 0;
	int res = 0;
	int first = 0;
	int second = 0;

	std::cout << "argument2: " << arg << std::endl;

	while (arg[j]) {
		while (ss >> word) {
			if (!(word.compare("+")) || !(word.compare("-"))
				|| !(word.compare("*")) || !(word.compare("/")))
				break;
			i = std::atoi(word.c_str());
			stack.push(i);
		}
		std::cout << word << std::endl;
		if (stack.size() == 2) {
			first = stack.top();
			stack.pop();
			second = stack.top();
			stack.pop();
		}
		if (stack.size() == 1) {
			first = res;
			second = stack.top();
			stack.pop();
		}

		res = operator_function(first, second, word);
		std::cout << res << std::endl;

//		std::cout << first << " and " << second << std::endl;
		j++;
	}

	return (0);
}

RPN::~RPN() {}