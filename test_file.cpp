//
// Created by Kevin Di nocera on 4/16/23.
//

void	print_av(char **av, std::vector<int> number, int id)
{
	if (id == 1) {
		for (int i = 0; av[i]; ++i)
			std::cout << "av[" << i << "] = " << av[i] << std::endl;
	}
	if (id == 2) {
		for (size_t it = 0; it < number.size(); ++it)
			std::cout << "it[" << it << "] = " << number[it] << std::endl;
	}
}

void	PmergeMe::merge(std::vector<int> &v, int left, int mid, int right)
{
	int L_side = mid - left + 1;
	int	R_side = right - mid;

//	std::cout << left << " " << mid << " " << right << std::endl;
//	std::cout << L_side << " " << R_side << std::endl;

	// créer des sous-tableaux temporaire gauche et droite.
	std::vector<int> L(L_side), R(R_side);

	//copier les données dans les sous-tableaux temporaire gauche et droite.
	for (int i = 0; i < L_side; ++i)
		L[i] = v[left + i];
	for (int j = 0; j < R_side; ++j)
		R[j] = v[mid + 1 + j];

	// fusionner les sous-tableaux gauche et droit dans le tableau principal
	int i = 0;
	int j = 0;
	int k = left;

//	display_sequence_vector(L, "L");
//	display_sequence_vector(R, "R");
//	std::cout << std::endl;
	while (i < L_side && j < R_side) {
//		printf(" i[%d] < L_side[%d] && \n j[%d] < R_side[%d]\n", i, L_side, j, R_side);
//		printf("    before v[%d]\n", v[k]);
//		printf("	L[%d] <= R[%d]\n", L[i], R[i]);
		if (L[i] <= R[i]) {
//			printf("		yes ! v[%d] = L[%d]\n\n", v[k], L[i]);
			v[k] = L[i];
			i++;
		}
		else {
//			printf("		nope ! arr[%d] = L[%d]\n\n", v[k], R[j]);
			v[k] = R[j];
			j++;
		}
//		printf("   after v[%d]\n", v[k]);
		k++;
	}

	// copier les éléments restants de L[] s'il en reste
	while (i < L_side) {
		v[k] = L[i];
		i++;
		k++;
	}

	// copier les éléments restants de R[] s'il en reste
	while (j < R_side) {
		v[k] = R[j];
		j++;
		k++;
	}
}

void insertion_sort(std::vector<int>& arr, int left, int right) {
	for (int i = left + 1; i <= right; i++) {
		int key = arr[i];
		int j = i - 1;
//		std::cout << i << " before loop arr[" << arr[i] << "]" << std::endl;
//		std::cout << "    j[" << j << "] >= left[" << left << "] && array[" << arr[j] << "] > key[" << key << "]" << std::endl;
		while (j >= left && arr[j] > key) {
//			std::cout << "	" << j << " inside loop arr(j+1)[" << arr[j + 1] << "] = arr(j)[" << arr[j] << "]" << std::endl;
			arr[j + 1] = arr[j];
//			std::cout << "		arr(j+1)[" << arr[j + 1] << "]" << std::endl;
			j--;
		}
//		std::cout << "	after loop arr(j+1)[" << arr[j + 1] << "], key = " << key << std::endl;
		arr[j + 1] = key;
	}
}

void	PmergeMe::merge_sort(std::vector<int> &v, int left, int right, int max_size_temp_tab)
{
// appliquer tri-insertion pour les sous-tableaux de petite taille
	if ((right - left + 1) <= max_size_temp_tab) {
		insertion_sort(v, left, right);
		return ;
	}
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(v, left, mid, max_size_temp_tab);
		merge_sort(v, mid + 1, right, max_size_temp_tab);
		merge(v, left, mid, right);
	}
}

void PmergeMe::sort_sequence(std::vector<int>& v, std::list<int>& l)
{
	(void) l;
	int	left = 0;
	int right = _v.size() - 1;
	//	Taille maximale des sous-tableaux qui seront triés à l'aide du tri par insertion.
	int	max_size_temp_tab = 5;

	struct timeval start, end;
	gettimeofday(&start, 0);
	merge_sort(v, left, right, max_size_temp_tab);
	gettimeofday(&end, 0);
	_time = ((end.tv_sec - start.tv_sec)  * 1e-6) + (end.tv_usec - start.tv_usec);

//	(void) l;
//	clock_t start_time = clock();
//	std::sort(v.begin(), v.end());
//	clock_t end_time = clock();
//	_time = static_cast<long double>(end_time - start_time) * 1000000 / CLOCKS_PER_SEC;

//	start_time = clock();
//	l.sort();
//	end_time = clock();
//	time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
//	std::cout << "Sort time using list: " << time << " seconds" << std::endl;
}

void	PmergeMe::algo(void)
{
	display_sequence_vector(_v, "Before");

	sort_sequence(_v, _l);
	display_sequence_vector(_v, "After");
	std::cout << "Time to process a range of: " << _v.size() << " elements with std::vector: ";
	std::cout << "Measured time is = " << std::fixed << std::setprecision(5) << _time << " microseconds." << std::endl;
}
PmergeMe::~PmergeMe(void) {}