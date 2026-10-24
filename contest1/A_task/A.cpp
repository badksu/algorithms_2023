#include <iostream>
#include <vector>

std::vector<int> CalcPrefixMin(std::vector<int> &arr) {
	std::vector<int> prefix_min(arr.size());
	prefix_min[0] = arr[0];
	for (int i = 1; i < arr.size(); ++i) {
		prefix_min[i] = std::min(prefix_min[i - 1], arr[i]);
	}
	return prefix_min;
}

std::vector<int> CalcSuffixMin(std::vector<int> &arr) {
	std::vector<int> suffix_min(arr.size());
	suffix_min[arr.size() - 1] = arr[arr.size() - 1];
	for (int i = arr.size() - 2; i > -1; --i) {
		suffix_min[i] = std::min(suffix_min[i + 1], arr[i]);
	}
	return suffix_min;
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
	std::vector<int> prefix_min = CalcPrefixMin(arr);
	std::vector<int> suffix_min = CalcSuffixMin(arr);

	size_t queries;
	std::cin >> queries;
	for (int i = 0; i < queries; ++i) {
		size_t left_border;
		size_t right_border;
		std::cin >> left_border >> right_border;
		std::cout << std::min(prefix_min[left_border - 1], suffix_min[right_border - 1]) << '\n';
	}
}
