#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100

string lines[MAX];

bool check(int n, int index) {
	for (int i = 1; i < n; i++) {
		if (lines[i][index] != lines[0][index])
			return false;
	}
	return true;
}

int main() {
	int n, min_len = 0x3fffffff;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, lines[i]);
		reverse(lines[i].begin(), lines[i].end());
		if (lines[i].size() < min_len)
			min_len = lines[i].size();
	}
	string suffix = "";
	for (int i = 0; i < min_len; i++) {
		if (check(n, i))
			suffix = lines[0][i] + suffix;
		else
			break;
	}
	if (suffix.size() != 0)
		cout << suffix << endl;
	else
		cout << "nai" << endl;
	return 0;
}