#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> convert(int x, int b) {
	vector<string> result;
	do {
		int digit = x % b;
		x /= b;
		result.push_back(to_string(digit));
	} while (x > 0);
	return result;
}

bool judge(vector<string> s) {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1])
			return false;
	}
	return true;
}

int main() {
	int n, b;
	cin >> n >> b;
	vector<string> n_s = convert(n, b);
	if (judge(n_s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = n_s.size() - 1; i >= 0; i--) {
		if (i == n_s.size() - 1)
			cout << n_s[i];
		else
			cout << " " << n_s[i];
	}
	return 0;
}