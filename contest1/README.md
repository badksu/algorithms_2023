# Binary search and Sorting algorithms
***
### Merge sort 
<details>
<summary> realization </summary>

```c++
template<typename T>
std::vector<T> Merge(std::vector<T> &left, std::vector<T> &right) {
	std::vector<T> result(left.size() + right.size());
	size_t i = 0;
	size_t j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] > right[j]) {
			result[i + j] = right[j];
			++j;
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
void MergeSort(std::vector<T> &arr) {
	if (arr.size() <= 1) { return; }

	int middle = arr.size() >> 1;
	std::vector<T> left(arr.begin(), arr.begin() + middle);
	std::vector<T> right(arr.begin() + middle, arr.end());
	MergeSort(left);
	MergeSort(right);

	arr = Merge(left, right);
}
```
</details>

### Quick sort
* Выбираем случайный элемент(пивот) в массиве.
* Перемещаем все элементы меньше пивота влево, больше него - вправо.
* Рекурсивно сортируем левый и правый кусок.

<details>
<summary> realization </summary>

```c++
std::random_device rd;
std::mt19937 random_num(rd());

template<typename T>
size_t Partition(std::vector<T> &arr, size_t left_border, size_t right_border) {
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
void QuickSort(std::vector<T> &arr, size_t begin, size_t end) {
	if (end - begin <= 1) {
		return;
	}

	size_t pivot_position = Partition(arr, begin, end);
	QuickSort(arr, begin, pivot_position + 1	);
	QuickSort(arr, pivot_position + 1, end);
}
}
```
</details>

### Quick select
