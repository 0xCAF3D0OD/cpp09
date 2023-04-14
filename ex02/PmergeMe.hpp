//
// Created by Kevin Di nocera on 4/2/23.
//

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>
#include <string>
#include <list>

class PmergeMe
{
private:
	std::vector<int> _v;
	std::list<int> _l;
	long double _time;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& src);

	void	stock_args_string(char **av, int ac);
	int		check_args_is_digit(char **av, int ac);
	void	sort_sequence(std::vector<int>& v, std::list<int>& l);
	void	display_sequence_vector(const std::vector<int>& v, const std::string& title);
	void	display_sequence_list(const std::list<int>& v, const std::string& title);
	void	algo(void);
//	void	mergeInSorte(char*);

	~PmergeMe(void);

};

#endif //CPP09_PMERGEME_HPP