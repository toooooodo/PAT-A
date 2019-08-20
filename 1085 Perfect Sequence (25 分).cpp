#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

long long numbers[MAX];

int upper_bound(int left, int right, long long x) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (numbers[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	int n, p, max_len = 0;
	cin >> n >> p;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	sort(numbers, numbers + n);
	for (int i = 0; i < n; i++) {
		long long bound = numbers[i] * p;
		int pos = upper_bound(i, n, bound);
		if (pos - i > max_len)
			max_len = pos - i;
	}
	cout << max_len << endl;
	return 0;
}