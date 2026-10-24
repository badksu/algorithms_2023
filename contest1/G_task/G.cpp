#include <iostream>
#include <vector>
#include <cstdint>

const int cBitCount = 64;

int GetBit(uint64_t value, uint64_t bit) {
	return (value >> bit) & 1;
}

void CountingSort(std::vector<uint64_t> &values, uint64_t current_bit) {
	std::vector<uint64_t> result(values.size());
	std::vector<int> count_of_value(2, 0);
	for (int i = 0; i < values.size(); ++i) {
		++count_of_value[GetBit(values[i], current_bit)];
	}
	for (int i = 1; i < 2; ++i) {
		count_of_value[i] += count_of_value[i - 1];
	}
	for (int i = values.size() - 1; i > -1; --i) {
		int bit = GetBit(values[i], current_bit);
		result[count_of_value[bit] - 1] = values[i];
		--count_of_value[bit];
	}
	values = result;
}

void CountingSort64bit(std::vector<uint64_t> &values) {
	for (int i = 0; i < cBitCount; ++i) {
		CountingSort(values, i);
	}
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	size_t size;
	std::cin >> size;
	std::vector<uint64_t> values(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> values[i];
	}
	CountingSort64bit(values);
	for (int i = 0; i < size; ++i) {
		std::cout << values[i] << '\n';
	}
}
