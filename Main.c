void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(int array[], int size) {
	// 一共要经过 n 次冒泡过程，一次冒泡过程，可以把一个最大的数放最后
	for (int i = 0; i < size; i++) {
		int sorted = 1;	// 假设数组已经有序了

		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				// 发生过交换了，有序不成立
				sorted = 0;
			}
		}

		// 冒泡完，仍然有序
		if (sorted == 1) {
			return;
		}
	}
}

// 左闭右闭，要找的区间是 array[left, right]
int BinarySearch(int array[], int size, int v) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (v == array[mid]) {
			return mid;
		}
		else if (v < array[mid]) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}


// 左闭右开，要找的区间是 array[left, right)
int BinarySearch(int array[], int size, int v) {
	int left = 0;
	int right = size;

	while (left < right) {
		int mid = left + (right - left) / 2;
		if (v == array[mid]) {
			return mid;
		}
		else if (v < array[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

long long Factorial(int n) {
	if (n < 2) {
		return n;
	}

	return n * Factorial(n - 1);
}

long long Fib(int n) {
	if (n < 2) {
		return n;
	}

	return Fib(n - 1) + Fib(n - 2);
}