//
// Created by Kevin Di nocera on 4/2/23.
//

#ifndef CPP09_PMERGEME_HPP
#define CPP09_PMERGEME_HPP

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <sstream>
#include <vector>
#include <string>
#include <list>

//template <typename T>
class PmergeMe
{
private:
	std::vector<int>	_v;
	std::list<int>		_l;
	float 			_timeV;
	float 			_timeL;
public:
	PmergeMe(void);
	PmergeMe(PmergeMe const& src);
	PmergeMe& operator=(PmergeMe const& src);

	void	stock_args_string(char **av, int ac);
	int		check_args_is_digit(char **av, int ac);
	void	sort_sequence(std::vector<int>& v, std::list<int>& l);
	void	merge_sort(std::vector<int> &v, int left, int right, int max_size_temp_tab);
	void	insertion_sort(std::vector<int>& arr, int left, int right);
	void	merge_V(std::vector<int> &v, int left, int mid, int right);

	void	merge_insertion_sort(std::list<int>& A, int k);
//	void	merge_insertion_sort_list(std::list<int>& lst, size_t k);
//	std::list<int> merge_lists(const std::list<int>& left, const std::list<int>& right);

	void	display_sequence_vector(const std::vector<int>& v, const std::string& title);
	void	display_sequence_list(const std::list<int>& v, const std::string& title);
	void	algo(void);

	~PmergeMe(void);

};

#endif //CPP09_PMERGEME_HPP