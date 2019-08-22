#include <iostream>
#include <string>

using namespace std;

#define MAX 100000

int p[MAX] = { 0 }, t[MAX] = { 0 };

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') {
			if (i == 0)
				p[i] = 1;
			else
				p[i] = p[i - 1] + 1;
		}
		else {
			if (i != 0)
				p[i] = p[i - 1];
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'T') {
			if (i == s.size() - 1)
				t[i] = 1;
			else
				t[i] = t[i + 1] + 1;
		}
		else {
			if (i != s.size() - 1)
				t[i] = t[i + 1];
		}
	}
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')
			count = (count + (p[i] * t[i]) % 1000000007) % 1000000007;
	}
	cout << count % 1000000007 << endl;
	return 0;
}