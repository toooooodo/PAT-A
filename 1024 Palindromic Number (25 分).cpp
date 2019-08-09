#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool check(string x) {
	for (int i = 0; i < x.size() / 2; i++)
		if (x[i] != x[x.size() - i - 1])
			return false;
	return true;
}

string add(string x) {
	string y = x, result = "";
	reverse(x.begin(), x.end());
	int carry = 0, digit;
	for (int i = x.size() - 1; i >= 0; i--) {
		int d1 = (int)(x[i] - '0');
		int d2 = (int)(y[i] - '0');
		int number = d1 + d2 + carry;
		carry = number / 10;
		result = (char)(number % 10 + '0') + result;
	}
	if (carry != 0)
		result = (char)(carry + '0') + result;
	return result;
}

int main() {
	string n;
	int k, count = -1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		if (check(n)) {
			count = i;
			break;
		}
		n = add(n);
	}
	cout << n << endl;
	if (count != -1) {
		cout << count << endl;
	}
	else {
		cout << k << endl;
	}
	return 0;
}