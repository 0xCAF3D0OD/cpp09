//
// Created by Kevin Di nocera on 4/2/23.
//
#include "PmergeMe.hpp"

int main(int ac, char **av) {
	PmergeMe test;

	if (ac <= 2 && test.check_args_is_digit(av, ac))
		return (1);
	else if (test.check_args_is_digit(av, ac))
		return (1);
	test.stock_args_string(av, ac);
//	test.check_input(av)
	return (0);
//
//	for (int i = 0; av[i]; ++i)
//		test.check_input(av[i]);
//	for (int i = 0; i < 3000; ++i) {
//		int n = rand() % 10000 + 1;
//		v.push_back(n);
//		l.push_back(n);
//	}
//
//	display_sequence_vector(v, "Unsorted sequence using vector");
//	display_sequence_list(l, "Unsorted sequence using list");
//
//	sort_sequence(v, l);
//
//	display_sequence_vector(v, "Sorted sequence using vector");
//	display_sequence_list(l, "Sorted sequence using list");
//
//	return 0;
}

//int main(int ac, char **av)
//{
//	PmergeMe merge;
//
//	if (ac != 2)
//		return (1);
//	merge.check_input(av[1]);
//	merge.mergeInSorte(av[1]);
//	return (0);
//}
