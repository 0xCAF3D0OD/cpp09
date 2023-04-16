//
// Created by Kevin Di nocera on 4/16/23.
//
#include <iostream>
#include <list>

using namespace std;

const int k = 5; // size of sublists

void merge_insertion_sort(list<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i += k) {
		list<int>::iterator it1 = A.begin();
		advance(it1, i);
		list<int>::iterator it2 = it1;
		advance(it2, k);
		A.insert(it2, A.end());
		A.sort(it1, it2);
	}
	for (int j = k; j < n; j *= 2) {
		for (int i = 0; i < n; i += 2*j) {
			list<int>::iterator it1 = A.begin();
			advance(it1, i);
			list<int>::iterator it2 = it1;
			advance(it2, j);
			list<int>::iterator it3 = it2;
			advance(it3, j);
			if (it3 == A.end()) {
				it3 = A.begin();
				advance(it3, n);
			}
			list<int> B;
			A.merge(B, it1, it2);
			A.merge(B, it2, it3);
		}
	}
}

int main() {
	list<int> A;
	A.push_back(12);
	A.push_back(15);
	A.push_back(26);
	A.push_back(2);
	A.push_back(5);
	A.push_back(14);
	merge_insertion_sort(A);
	for (list<int>::iterator it = A.begin(); it != A.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}
