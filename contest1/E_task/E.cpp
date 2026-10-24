#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
	int left;
	int right;

	bool operator<(Segment other) const {
		if (left == other.left) {
			return right < other.right;
		}
		return left < other.left;
	}

	bool IsIntersect(Segment other) const {
		return (left <= other.left) && (other.left <= right) && (right <= other.right);
	}

	bool IsCover(Segment other) const {
		return (left <= other.left) && (other.right <= right);
	}
};

std::vector<Segment> CombineSegments(std::vector<Segment> &segments) {
	std::vector<Segment> result;
	Segment current_seg = segments[0];
	for (int i = 1; i < segments.size(); ++i) {
		if (current_seg.IsIntersect(segments[i]) &&
				!(current_seg.IsCover(segments[i]))) {
			current_seg.right = segments[i].right;
		} else if (!(current_seg.IsCover(segments[i]))) {
			result.push_back(current_seg);
			current_seg = segments[i];
		}
	}
	result.push_back(current_seg);
	return result;
}

int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);

	size_t size;
	std::cin >> size;
	std::vector<Segment> segments(size);
	for (int i = 0; i < size; ++i) {
		std::cin >> segments[i].left >> segments[i].right;
	}
	std::sort(segments.begin(), segments.end());
	std::vector<Segment> combined_segments = CombineSegments(segments);
	std::cout << combined_segments.size() << '\n';
	for (int i = 0; i < combined_segments.size(); ++i) {
		std::cout << combined_segments[i].left << ' ' << combined_segments[i].right << '\n';
	}
}
