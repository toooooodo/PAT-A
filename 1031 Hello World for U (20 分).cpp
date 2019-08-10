#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.length();
	int n1, n2, n3;
	for (int i = 3; i <= len; i++) {
		if ((len + 2 - i) % 2 == 0) {
			n1 = n3 = (len + 2 - i) / 2;
			if (n1 <= i) {
				n2 = i;
				break;
			}
		}
	}
	for (int i = 0; i < n1 - 1; i++) {
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++)
			cout << " ";
		cout << s[len - i - 1] << endl;
	}
	cout << s.substr(n1 - 1, n2) << endl;
	return 0;
}