void Swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void BubbleSort(int array[], int size) {
	// һ��Ҫ���� n ��ð�ݹ��̣�һ��ð�ݹ��̣����԰�һ�������������
	for (int i = 0; i < size; i++) {
		int sorted = 1;	// ���������Ѿ�������

		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				Swap(array + j, array + j + 1);
				// �����������ˣ����򲻳���
				sorted = 0;
			}
		}

		// ð���꣬��Ȼ����
		if (sorted == 1) {
			return;
		}
	}
}

// ����ұգ�Ҫ�ҵ������� array[left, right]
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


// ����ҿ���Ҫ�ҵ������� array[left, right)
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