#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXM 200
#define MAXN 10000

int numbers[MAXN], matrix[MAXM][MAXM];

bool cmp(int a, int b) {
	return a > b;
}

void to_fill(int N, int m, int n) {
	int count = 0;
	int i = 0, j = 0;
	int right_b = n, left_b = -1, bottom_b = m, top_b = -1;
	while (count < N) {
		while (j < right_b) {
			matrix[i][j] = numbers[count++];
			j++;
			if (count == N)
				return;
		}
		j--;
		i++;
		top_b++;
		while (i < bottom_b) {
			matrix[i][j] = numbers[count++];
			i++;
			if (count == N)
				return;
		}
		i--;
		j--;
		right_b--;
		while (j > left_b) {
			matrix[i][j] = numbers[count++];
			j--;
			if (count == N)
				return;
		}
		j++;
		i--;
		bottom_b--;
		while (i > top_b) {
			matrix[i][j] = numbers[count++];
			i--;
			if (count == N)
				return;
		}
		i++;
		j++;
		left_b++;
	}
}

int main() {
	int N, m, n;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	sort(numbers, numbers + N, cmp);
	for (int i = (int)sqrt(N); i <= N; i++) {
		if (N%i == 0) {
			m = i;
			n = N / i;
			if (m < n)
				swap(m, n);
			break;
		}
	}
	to_fill(N, m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == 0)
				cout << matrix[i][j];
			else
				cout << " " << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}