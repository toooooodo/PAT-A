#include <iostream>
#include <cmath>

using namespace std;

#define MAX 10000

int table[MAX] = { 0 };

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sqr = (int)sqrt(x);
	for (int i = 2; i <= sqr; i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}

bool insert(int x, int m_size) {
	for (int i = 0; i < m_size; i++) {
		int pos = (x + i * i) % m_size;
		if (table[pos] == 0) {
			table[pos] = x;
			return true;
		}
	}
	return false;
}

int search(int x, int m_size) {
	int cnt = 0;
	while (cnt <= m_size) {
		int pos = (x + cnt * cnt) % m_size;
		cnt++;
		if (table[pos] == x) {
			break;
		}
		else if (table[pos] == 0) {
			break;
		}
	}
	return cnt;
}

int main() {
	int m_size, n, m, cnt = 0;
	cin >> m_size >> n >> m;
	while (is_prime(m_size) == false)
		m_size++;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (insert(x, m_size) == false)
			printf("%d cannot be inserted.\n", x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cnt += search(x, m_size);
	}
	printf("%.1f\n", (double)(cnt * 1.0 / m));
	return 0;
}