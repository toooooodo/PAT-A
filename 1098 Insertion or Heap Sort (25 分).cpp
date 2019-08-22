#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int origin[MAX], insert[MAX], heap[MAX], goal[MAX];

bool check(int n, int a[]) {
	for (int i = 0; i < n; i++)
		if (goal[i] != a[i])
			return false;
	return true;
}

bool insert_sort(int n) {
	bool flg = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && check(n, insert)) {
			flg = true;
		}
		int j = i, tmp = insert[j];
		while (j > 0 && insert[j - 1] > tmp) {
			insert[j] = insert[j - 1];
			j--;
		}
		insert[j] = tmp;
		if (flg)
			break;
	}
	return flg;
}

void perc_down(int n, int i) {
	int tmp, child;
	for (tmp = heap[i]; i * 2 + 1 < n; i = child) {
		child = i * 2 + 1;
		if (child != n - 1 && heap[i * 2 + 1] < heap[i * 2 + 2])
			child++;
		if (heap[child] > tmp)
			heap[i] = heap[child];
		else
			break;
	}
	heap[i] = tmp;
}

void heap_sort(int n) {
	bool flg = false;
	for (int i = n / 2; i >= 0; i--)
		perc_down(n, i);
	for (int i = n - 1; i >= 0; i--) {
		if (i != n - 1 && check(n, heap)) {
			flg = true;
		}
		swap(heap[0], heap[i]);
		perc_down(i, 0);
		if (flg)
			break;
	}
}

void print(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cout << a[i];
		else
			cout << " " << a[i];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> origin[i];
		insert[i] = heap[i] = origin[i];
	}
	for (int i = 0; i < n; i++)
		cin >> goal[i];
	if (insert_sort(n)) {
		cout << "Insertion Sort" << endl;
		print(n, insert);
	}
	else {
		cout << "Heap Sort" << endl;
		heap_sort(n);
		print(n, heap);
	}
	return 0;
}