#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sqr = (int)sqrt(x);
	for (int i = 2; i <= sqr; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
	int x;
	cin >> x;
	if (is_prime(x - 6) && is_prime(x)) {
		cout << "Yes" << endl;
		cout << x - 6 << endl;
	}
	else if (is_prime(x + 6) && is_prime(x)) {
		cout << "Yes" << endl << x + 6 << endl;
	}
	else {
		cout << "No" << endl;
		for (int i = 1;; i++) {
			if (is_prime(x + i) && is_prime(x + i + 6) || is_prime(x + i) && is_prime(x + i - 6)) {
				cout << x + i << endl;
				break;
			}
		}
	}
	return 0;
}