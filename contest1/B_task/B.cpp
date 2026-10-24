#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

const int cTen = 10;

std::vector<double> CalcPrefixSum(std::vector<double> &arr) {
	std::vector<double> prefix_sum(arr.size() + 1, 0.0);
	for (int i = 1; i < arr.size() + 1; ++i) {
		prefix_sum[i] = prefix_sum[i - 1] + log(arr[i - 1]);
	}
	return prefix_sum;
}

double CalcAns(std::vector<double> &prefix_sum, size_t left_border, size_t right_border) {
	double ans = prefix_sum[right_border + 1] - prefix_sum[left_border];
	return exp(ans / static_cast<double>(right_border - left_border + 1));
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	std::cout << std::setprecision(cTen) << std::fixed;

	size_t size;
	std::cin >> size;
	std::vector<double> arr(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> arr[i];
	}
	std::vector<double> prefix_sum = CalcPrefixSum(arr);
	int queries;
	std::cin >> queries;
	for (int i = 0; i < queries; ++i) {
		size_t left_border;
		size_t right_border;
		std::cin >> left_border >> right_border;
		std::cout << CalcAns(prefix_sum, left_border, right_border) << '\n';
	}
}
