#include <iostream>
#include <vector>
#include <algorithm>

const int cInf = 2e9 + 1;

bool IsSatisfy(std::vector<int> &coordinates, int max_count_of_segments, int segment_size) {
	int count_of_segments = 1;
	size_t last_covered = 0;
	for (int i = 1; i < coordinates.size(); ++i) {
		if (coordinates[i] - coordinates[last_covered] > segment_size) {
			++count_of_segments;
			last_covered = i;
		}
	}
	return count_of_segments <= max_count_of_segments;
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	size_t size;
	int max_count_of_segments;
	std::cin >> size >> max_count_of_segments;
	std::vector<int> coordinates(size);

	for (int i = 0; i < size; ++i) {
		std::cin >> coordinates[i];
	}
	std::sort(coordinates.begin(), coordinates.end());

	long long left_border = -1;
	long long right_border = cInf;
	while (right_border - left_border > 1) {
		int middle = static_cast<int>((right_border + left_border) / 2);
		if (IsSatisfy(coordinates, max_count_of_segments, middle)) {
			right_border = middle;
		} else { left_border = middle; }
	}
	std::cout << right_border;
}
