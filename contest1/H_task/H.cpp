#include <iostream>
#include <vector>
#include <random>

std::random_device rd;
std::mt19937 random_num(rd());

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
void QuickSort(std::vector <T> &arr, size_t begin, size_t end) {
	if (end - begin <= 1) {
		return;
	}

	size_t pivot_position = Partition(arr, begin, end);
	QuickSort(arr, begin, pivot_position + 1);
	QuickSort(arr, pivot_position + 1, end);
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	QuickSort(a, 0, n);
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}
}
