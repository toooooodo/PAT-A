#include <iostream>
#include <cmath>

using namespace std;

#define MAX 10000

bool table[MAX] = { false };

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sq = (int)sqrt(x);
	for (int i = 2; i <= sq; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main() {
	int m, n;
	cin >> m >> n;
	while (is_prime(m) == false)
		m++;
	for (int i = 0; i < n; i++) {
		int x, pos;
		cin >> x;
		bool flg = false;
		for (int j = 0; j < m; j++) {
			pos = (x + j * j) % m;
			if (table[pos] == false) {
				table[pos] = true;
				flg = true;
				break;
			}
		}
		if (i == 0) {
			if (flg)
				cout << pos;
			else
				cout << "-";
		}
		else {
			if (flg)
				cout << " " << pos;
			else
				cout << " -";
		}
	}
	return 0;
}