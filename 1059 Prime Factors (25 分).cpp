#include <iostream>
#include <cmath>

using namespace std;

struct factor {
	int n;
	int count;
	factor() :n(0), count(0) {}
}factors[10];

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sq = (int)sqrt(x);
	for (int i = 2; i <= sq; i++) {
		if (x % 2 == 0)
			return false;
	}
	return true;
}

int main() {
	int n, count = 0;
	cin >> n;
	int sq = (int)sqrt(n);
	int num = n;
	for (int i = 2; i <= sq; i++) {
		if (is_prime(i) && n%i == 0) {
			factors[count].n = i;
			while (n%i == 0) {
				factors[count].count++;
				n /= i;
			}
			count++;
		}
	}
	// 97532468=2^2*11*17*101*1291
	if (count == 0) {
		printf("%d=%d\n", num, num);
	}
	else {
		printf("%d=", num);
		for (int i = 0; i < count; i++) {
			if (i == 0) {
				if (factors[i].count == 1)
					printf("%d", factors[i].n);
				else
					printf("%d^%d", factors[i].n, factors[i].count);
			}
			else {
				if (factors[i].count == 1)
					printf("*%d", factors[i].n);
				else
					printf("*%d^%d", factors[i].n, factors[i].count);
			}
		}
	}
	return 0;
}