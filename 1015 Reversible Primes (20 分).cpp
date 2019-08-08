#include <iostream>
#include <cmath>

using namespace std;

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

int rever(int x, int radix) {
	int result = 0;
	while (x != 0) {
		int digit = x % radix;
		x /= radix;
		result = result * radix + digit;
	}
	return result;
}

int main() {
	int n, d;
	cin >> n;
	while (n > 0) {
		cin >> d;
		int reverse_n = rever(n, d);
		if (is_prime(n) && is_prime(reverse_n))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> n;
	}
	return 0;
}