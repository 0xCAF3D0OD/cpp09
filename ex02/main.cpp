//
// Created by Kevin Di nocera on 4/2/23.
//

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe merge;

	if (ac != 2)
		return (1);
	merge.check_input(av[1]);
	return (0);
}
