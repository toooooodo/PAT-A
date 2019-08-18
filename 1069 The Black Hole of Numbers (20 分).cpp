#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int to_int(string s) {
	return (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
}

int main() {
	string number;
	cin >> number;
	while (number.size() < 4)
		number.insert(0, "0");
	do {
		string a, b;
		a = b = number;
		sort(a.begin(), a.end(), cmp);
		sort(b.begin(), b.end());
		int diff = to_int(a) - to_int(b);
		number = to_string(diff);
		while (number.size() < 4)
			number.insert(0, "0");
		// 7766 - 6677 = 1089
		printf("%s - %s = %s\n", a.c_str(), b.c_str(), number.c_str());
	} while (number != "6174"&&number != "0000");
	return 0;
}