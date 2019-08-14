#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int seq[MAX];

int search(int left, int right, int x) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (seq[mid] < x)
			left = mid + 1;
		else if (seq[mid] > x)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main() {
	int n, m, final_end, final_begin = 0x7fffffff;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	sort(seq, seq + n);
	for (int i = 0; i < n - 1; i++) {
		int end = search(i + 1, n - 1, m - seq[i]);
		if ( end != -1) {
			final_begin = seq[i];
			final_end = seq[end];
			break;
		}
	}
	if (final_begin != 0x7fffffff)
		cout << final_begin << " " << final_end << endl;
	else
		cout << "No Solution" << endl;
	return 0;
}