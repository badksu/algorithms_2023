#include <iostream>
#include <vector>

template<typename T>
std::vector<T> Merge(std::vector<T> &left, std::vector<T> &right, int &count_of_inversions) {
	std::vector<T> result(left.size() + right.size());
	size_t i = 0;
	size_t j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] > right[j]) {
			result[i + j] = right[j];
			++j;
			count_of_inversions += left.size() - i;
		} else {
			result[i + j] = left[i];
			++i;
		}
	}
	while (i < left.size()) {
		result[i + j] = left[i];
		++i;
	}
	while (j < right.size()) {
		result[i + j] = right[j];
		++j;
	}

	return result;
}

template<typename T>
int MergeSort(std::vector<T> &arr) {
	if (arr.size() <= 1) { return 0; }

	int count_of_inversions = 0;
	int middle = arr.size() >> 1;
	std::vector<T> left(arr.begin(), arr.begin() + middle);
	std::vector<T> right(arr.begin() + middle, arr.end());
	count_of_inversions += MergeSort(left);
	count_of_inversions += MergeSort(right);

	arr = Merge(left, right, count_of_inversions);
	return count_of_inversions;
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	size_t size;
	std::cin >> size;
	std::vector<int> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	std::cout << MergeSort(arr);
}
