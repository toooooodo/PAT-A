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

string add_(string a) {
	string res = "";
	int carry = 0;
	for (int i = 0; i < a.size(); i++) {
		int digit = carry + (int)(a[i] - '0') + (int)(a[a.size() - i - 1] - '0');
		carry = digit / 10;
		res = (char)(digit % 10 + '0') + res;
	}
	if (carry != 0)
		res = (char)(carry + '0') + res;
	return res;
}

int main() {
	string x;
	cin >> x;
	for (int i = 0; i < 10; i++) {
		if (check(x)) {
			printf("%s is a palindromic number.\n", x.c_str());
			return 0;
		}
		string rev = x;
		reverse(rev.begin(),rev.end());
		string res = add_(x);
		printf("%s + %s = %s\n", x.c_str(), rev.c_str(), res.c_str());
		x = res;
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}