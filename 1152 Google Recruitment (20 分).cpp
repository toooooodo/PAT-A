#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sqr = sqrt(x);
	for (int i = 2; i <= sqr; i++)
		if (x%i == 0)
			return false;
	return true;
}

int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	for (int i = 0; i <= n - k; i++) {
		string x = s.substr(i, k);
		if (is_prime(stoi(x))) {
			cout << x << endl;
			return 0;
		}
	}
	cout << 404 << endl;
	return 0;
}