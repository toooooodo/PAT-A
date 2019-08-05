#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add_format(string s) {
	bool neg = (s[0] == '-');
	if (neg)
		s = s.substr(1);
	string result = "";
	int count = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		result = s[i] + result;
		if (++count == 3 && i != 0) {
			count = 0;
			result = "," + result;
		}
	}
	if (neg == true)
		result = "-" + result;
	return result;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << add_format(to_string(a + b)) << endl;
	return 0;
}