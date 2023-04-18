//
// Created by Kevin Di nocera on 4/2/23.
//
#include <sys/time.h>
#include <iomanip>
#include <stdio.h>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const& src) {
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
	this->_v = src._v;
	this->_l = src._l;
	this->_timeV = src._timeV;
	this->_timeL = src._timeL;
	return (*this);
}

std::list<int> stock_1_string_L(char **av, std::list<int> tab_num)
{
	std::stringstream	ss;
	int					num;

	for (int i = 1; av[i]; ++i)
		ss << av[i];
	while (ss >> num) {
		if (num > INT_MAX || num < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(num);
	}
	return (tab_num);
}

std::list<int> stock_many_strings_L(char **av, std::list<int> tab_num) {
	for (int i = 1; av[i]; i++) {
		if (std::atoi(av[i]) > INT_MAX || std::atoi(av[i]) < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(std::atoi(av[i]));
	}
	return (tab_num);
}

// Function to merge two sorted lists
std::list<int> PmergeMe::merge(const std::list<int>& left, const std::list<int>& right) {
	std::list<int> result;
	std::list<int>::const_iterator left_iter = left.begin();
	std::list<int>::const_iterator right_iter = right.begin();

	while (left_iter != left.end() && right_iter != right.end()) {
		if (*left_iter <= *right_iter) {
			result.push_back(*left_iter);
			++left_iter;
		} else {
			result.push_back(*right_iter);
			++right_iter;
		}
	}

	result.insert(result.end(), left_iter, left.end());
	result.insert(result.end(), right_iter, right.end());

	return result;
}

// Function to perform insertion sort on a list
void PmergeMe::insertionSort(std::list<int>& lst) {
	std::list<int>::iterator i;
	for (i = lst.begin(); i != lst.end(); ++i) {
		std::list<int>::iterator j = i;
		while (j != lst.begin() && *std::prev(j) > *j) {
			std::iter_swap(j, std::prev(j));
			--j;
		}
	}
}

// Function to perform merge-insertion sort on a list
std::list<int> PmergeMe::merge_insertion_sort(std::list<int>& lst) {
	if (lst.size() <= 1) {
		return lst;
	} else if (lst.size() <= 11) {
		insertionSort(lst);
		return lst;
	}

	std::list<int>::iterator mid = std::next(lst.begin(), lst.size() / 2);
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());

	left = merge_insertion_sort(left);
	right = merge_insertion_sort(right);

	return merge(left, right);
}

void PmergeMe::display_sequence_list(const std::list<int>& v, const std::string& title)
{
	std::cout << title << ":	";
	for (std::list<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/*----------------------------------------------------vector------------------------------------------------------------*/

void	PmergeMe::merge_V(std::vector<int>& v, int left, int mid, int right)
{
	int L_side = mid - left + 1;
	int	R_side = right - mid;

	// Créer des sous-tableaux temporaire gauche et droite.
	std::vector<int> L(L_side), R(R_side);

	// Copier les données dans les sous-tableaux temporaire gauche et droite.
	for (int i = 0; i < L_side; ++i)
		L[i] = v[left + i];
	for (int j = 0; j < R_side; ++j)
		R[j] = v[mid + 1 + j];

	// Fusionner les sous-tableaux gauche et droit dans le tableau principal
	int i = 0;
	int j = 0;
	int k = left;

	while (i < L_side && j < R_side) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i++;
		}
		else {
			v[k] = R[j];
			j++;
		}
		k++;
	}

	// Copier les éléments restants de L[] s'il en reste
	while (i < L_side) {
		v[k] = L[i];
		i++;
		k++;
	}

	// Copier les éléments restants de R[] s'il en reste
	while (j < R_side) {
		v[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::insertion_sort(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= left && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void	PmergeMe::merge_sort(std::vector<int> &v, int left, int right, int max_size_temp_tab)
{
	// Appliquer tri-insertion pour les sous-tableaux de petite taille
	if ((right - left + 1) <= max_size_temp_tab) {
		insertion_sort(v, left, right);
		return ;
	}
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid, max_size_temp_tab);
		merge_sort(v, mid + 1, right, max_size_temp_tab);
		merge_V(v, left, mid, right);
	}
}

std::vector<int> stock_1_string(char **av, std::vector<int> tab_num)
{
	std::stringstream	ss;
	int					num;

	for (int i = 1; av[i]; ++i)
		ss << av[i];
	while (ss >> num) {
		if (num > INT_MAX || num < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit(1);
		}
		tab_num.push_back(num);
	}
	return (tab_num);
}

std::vector<int> stock_many_strings(char **av, std::vector<int> tab_num)
{
	for (int i = 1; av[i]; i++)
	{
		if (std::atoi(av[i]) > INT_MAX || std::atoi(av[i]) < 0) {
			std::cerr << "error: INT_MIN INT_MAX" << std::endl;
			exit (1);
		}
		tab_num.push_back(std::atoi(av[i]));
	}
	return (tab_num);
}

void PmergeMe::sort_sequence(std::vector<int>& v, std::list<int>& l)
{
	int	left = 0;
	int right = _v.size() - 1;
	//	Taille maximale des sous-tableaux qui seront triés à l'aide du tri par insertion.
	int	max_size_temp_tab = 5;
	struct timeval start, end;

	gettimeofday(&start, 0);
	merge_sort(v, left, right, max_size_temp_tab);
	gettimeofday(&end, 0);
	_timeV = ((end.tv_sec - start.tv_sec)  * 1e-6) + (end.tv_usec - start.tv_usec);

	gettimeofday(&start, 0);
	merge_insertion_sort(l);
	gettimeofday(&end, 0);
	_timeL = ((end.tv_sec - start.tv_sec)  * 1e-6) + (end.tv_usec - start.tv_usec);
}

void PmergeMe::display_sequence_vector(const std::vector<int>& v, const std::string& title)
{
	std::cout << title << ":	\" ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\"" << std::endl;
}


void	PmergeMe::algo(void)
{
	display_sequence_vector(_v, "vector before");
	display_sequence_list(_l, "list before");

	sort_sequence(_v, _l);

	display_sequence_vector(_v, "\nvector after");
	display_sequence_list(_l, "list after");
	std::cout << "\nTime to process a range of: " << _v.size() << " elements with std::vector: ";
	std::cout << "Measured time is = " << std::fixed << std::setprecision(5) << _timeV << " microseconds." << std::endl;
	std::cout << "Time to process a range of: " << _l.size() << " elements with std::list: ";
	std::cout << "Measured time is = " << std::fixed << std::setprecision(5) << _timeL << " microseconds." << std::endl;
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

void	PmergeMe::stock_args_string(char **av, int ac)
{
	std::vector<int> 	v_numbers;
	std::list<int> 		l_numbers;

	if (ac == 2) {
		v_numbers = stock_1_string(av, v_numbers);
		l_numbers = stock_1_string_L(av, l_numbers);
	}
	else {
		v_numbers = stock_many_strings(av, v_numbers);
		l_numbers = stock_many_strings_L(av, l_numbers);
	}
	if (v_numbers.size() == 1 || l_numbers.size() == 1)
	{
		std::cerr << "error: less arguments" << std::endl;
		exit(1);
	}
	this->_v = v_numbers;
	this->_l = l_numbers;
}

PmergeMe::~PmergeMe(void) {}

