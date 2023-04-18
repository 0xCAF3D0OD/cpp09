//
// Created by Kevin Di nocera on 4/17/23.
//
#include <iostream>
#include <list>
#include <algorithm>

// Function to merge two sorted lists
std::list<int> merge(const std::list<int>& left, const std::list<int>& right) {
	std::list<int> result;
	std::list<int>::const_iterator left_iter = left.begin();
	std::list<int>::const_iterator right_iter = right.begin();

	//	auto left_iter = left.begin();
//	auto right_iter = right.begin();

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
void insertionSort(std::list<int>& lst) {
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
std::list<int> mergeInsertionSort(std::list<int>& lst) {
	if (lst.size() <= 1) {
		return lst;
	} else if (lst.size() <= 11) {
		insertionSort(lst);
		return lst;
	}

	std::list<int>::iterator mid = std::next(lst.begin(), lst.size() / 2);
	std::list<int> left(lst.begin(), mid);
	std::list<int> right(mid, lst.end());

	left = mergeInsertionSort(left);
	right = mergeInsertionSort(right);

	return merge(left, right);
}

int main() {
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(2);
	lst.push_back(8);
	lst.push_back(1);
	lst.push_back(10);
	lst.push_back(7);
	lst.push_back(4);
	lst.push_back(9);
	lst.push_back(3);
	lst.push_back(6);
	std::list<int> sorted_lst = mergeInsertionSort(lst);
	std::list<int>::iterator item;
	for (item = lst.begin(); item != lst.end(); ++item) {
		std::cout << *item << " ";
	}
	std::cout << std::endl;

	return 0;
}
