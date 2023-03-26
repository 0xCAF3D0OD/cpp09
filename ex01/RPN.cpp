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
//			&& (word.compare(" ") != 0) && (word.compare("\t") != 0))
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

int	RPN::calculus(std::string arg) {
	std::stringstream ss(arg);
	std::stringstream sa;
	std::string word;
	int	i = 0;

	std::cout << "argument2: " << arg << std::endl;

	while (ss >> word) {
		if ((word.compare("+")) && (word.compare("-"))
			&& (word.compare("*")) && (word.compare("/")))
			break ;
		std::cout << word << std::endl;
		i = std::atoi(word.c_str());
		stack.push(i);
	}
	if (stack.size() >= 1 || stack.size() == 2) {
		while (!stack.empty()) {
			std::cout << stack.top() << " ";
			stack.pop();
		}
	}

	return (0);
}

RPN::~RPN() {}