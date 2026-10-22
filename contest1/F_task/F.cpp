#include <iostream>
#include <vector>
#include <random>

using Ll = long long;

const Ll c45 = 45;
const Ll c123 = 123;
const Ll cMod = 1e7 + 4321;

std::random_device rd;
std::mt19937 random_num(rd());

void MakeArray(std::vector<int> &arr) {
	for (int i = 2; i < arr.size(); ++i) {
		Ll tmp = (arr[i - 1] * c123 + arr[i - 2] * c45) % cMod;
		arr[i] = static_cast<int>(tmp);
	}
}

template<typename T>
size_t Partition(std::vector <T> &arr, size_t left_border, size_t right_border) {
	T pivot = arr[left_border + (random_num() % (right_border - left_border))];
	--right_border;

	while (left_border <= right_border) {
		while (arr[left_border] < pivot) { ++left_border; }
		while (arr[right_border] > pivot) { --right_border; }

		if (left_border >= right_border) { break; }
		std::swap(arr[left_border], arr[right_border]);
		++left_border;
		--right_border;
	}
	return right_border;
}

template<typename T>
size_t QuickSelect(std::vector <T> &arr, size_t position, size_t begin, size_t end) {
	if (end - begin <= 1) {
		return begin;
	}

	size_t pivot_position = Partition(arr, begin, end);
	if (position <= pivot_position) {
		return QuickSelect(arr, position, begin, pivot_position + 1);
	}
	return QuickSelect(arr, position, pivot_position + 1, end);
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	size_t size;
	size_t position;
	std::cin >> size >> position;
	std::vector<int> arr(size);
	std::cin >> arr[0] >> arr[1];
	MakeArray(arr);
	std::cout << arr[QuickSelect(arr, position - 1, 0, size)];
}
