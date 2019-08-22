#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long n;
	long long begin, len = -1;
	cin >> n;
	long long sqr = (long long)sqrt(n);
	for (long long i = 2; i <= sqr; i++) {
		long long product = 1, j = i;
		while (true) {
			product *= j;
			if (n%product != 0) {
				break;
			}
			else {
				if (j - i + 1 > len) {
					len = j - i + 1;
					begin = i;
				}
				j++;
			}
		}
	}
	if (len == -1) {
		len = 1;
		begin = n;
	}
	cout << len << endl;
	for (long long i = begin; i < begin + len; i++) {
		if (i == begin)
			cout << i;
		else
			cout << "*" << i;
	}
	return 0;
}