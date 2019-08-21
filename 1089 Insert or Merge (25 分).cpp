#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int origin[MAX], insert_seq[MAX], merge_seq[MAX], goal[MAX];

bool cmp(int n, int a[]) {
	for (int i = 0; i < n; i++)
		if (goal[i] != a[i])
			return false;
	return true;
}

void print(int n, int a[]) {
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cout << a[i];
		else
			cout << " " << a[i];
	}
}

bool insert_sort(int n, int a[]) {
	int flg = 0;
	for (int i = 1; i < n; i++) {
		if (cmp(n, a) && i != 1) {
			cout << "Insertion Sort" << endl;
			flg = 1;
		}
		int tmp = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > tmp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
		if (flg == 1)
			break;
	}
	return flg == 1 ? true : false;
}

bool merge_sort(int n, int a[]) {
	bool flg = false;
	for (int step = 2; step / 2 < n; step *= 2) {
		if (cmp(n, a) && step != 2) {
			flg = true;
			cout << "Merge Sort" << endl;
		}
		for (int i = 0; i < n; i += step) {
			sort(a + i, a+min(i+step,n));
		}
		if (flg) {
			break;
		}
	}
	return flg;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> origin[i];
		insert_seq[i] = merge_seq[i] = origin[i];
	}
	for (int i = 0; i < n; i++)
		cin >> goal[i];
	if (insert_sort(n, insert_seq)) {
		print(n, insert_seq);
	}
	if (merge_sort(n, merge_seq)) {
		print(n, merge_seq);
	}
	return 0;
}