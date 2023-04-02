//
// Created by Kevin Di nocera on 4/2/23.
//

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#endif //CPP09_PMERGEME_HPP
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>

class PmergeMe
{
private:
	std::vector<int> _vector;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& src);

	int		check_input(char*);
	void	mergeInSorte(char*);

	~PmergeMe(void);

};