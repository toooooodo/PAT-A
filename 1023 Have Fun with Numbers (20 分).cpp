#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string doub(string x) {
	string re = "";
	int i = x.size() - 1;
	int carry = 0, number;
	while (i >= 0 || carry > 0) {
		if (i < 0)
			number = carry;
		else
			number = (int)(x[i] - '0') * 2 + carry;
		carry = number / 10;
		re = (char)('0' + number % 10) + re;
		i--;
	}
	return re;
}

bool cmp(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {
	string n;
	cin >> n;
	while (n[0] == '0')
		n = n.substr(1);
	string double_n = doub(n);
	if (cmp(n, double_n))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << double_n << endl;
	return 0;
}