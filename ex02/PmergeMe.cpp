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

std::list<int> PmergeMe::merge_lists(const std::list<int>& left, const std::list<int>& right)
{
	std::list<int> result;
	std::list<int>::const_iterator left_it = left.begin();
	std::list<int>::const_iterator right_it = right.begin();
	while (left_it != left.end() && right_it != right.end())
	{
		if (*left_it <= *right_it)
		{
			result.push_back(*left_it);
			++left_it;
		}
		else
		{
			result.push_back(*right_it);
			++right_it;
		}
	}
	// on ajoute les éléments restants de la liste de gauche
	while (left_it != left.end())
	{
		result.push_back(*left_it);
		++left_it;
	}
	// on ignore les éléments restants de la liste de droite
	// car ils sont plus grands que tous les éléments de la liste de gauche
	return result;
}

void	PmergeMe::merge_insertion_sort_list(std::list<int>& lst, size_t k)
{
	if (lst.size() < k)
	{
		// tri par insertion pour les sous-listes plus petites que k
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		{
			// recherche du point d'insertion
			std::list<int>::iterator insertion_point = lst.begin();
			while (insertion_point != it && *insertion_point < *it) ++insertion_point;
			// insertion de l'élément à sa position
			if (insertion_point != it) lst.insert(insertion_point, *it);
			else if (++insertion_point != it) lst.insert(insertion_point, *it);
			// il n'est pas nécessaire de faire une insertion s'il est déjà à la bonne position
		}
		return;
	}
	// tri fusion pour les sous-listes plus grandes que k
	std::list<int> left, right;
	std::list<int>::iterator it = lst.begin();
	std::advance(it, lst.size() / 2);
//	left.splice(left.begin(), lst, lst.begin(), it);
//	right.splice(right.begin(), lst, it, lst.end());
//	merge_insertion_sort_list(left, k);
//	merge_insertion_sort_list(right, k);
//	std::list<int> merged_list = merge_lists(left, right);
//	lst.merge(merged_list);
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
	merge_insertion_sort_list(l, 5);
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

