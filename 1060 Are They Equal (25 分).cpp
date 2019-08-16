#include <iostream>
#include <string>

using namespace std;

string deal(string s, int n, int &e) {
	string re = "";
	while (s.size() > 0 && s[0] == '0')
		s.erase(s.begin());
	if (s[0] == '.') {
		s.erase(s.begin());
		for (int i = 0; i < s.size() && s[i] == '0'; i++)
			e--;
		while (s.size() > 0 && s[0] == '0')
			s.erase(s.begin());
	}
	else {
		int dot_pos = 0;
		while (s[dot_pos] != '.' && dot_pos < s.size()) {
			dot_pos++;
			e++;
		}
		if (dot_pos != s.size())
			s.erase(dot_pos, 1);
	}
	if (s.size() == 0)
		e = 0;
	for (int i = 0; i < n; i++) {
		if (i < s.size())
			re = re + s[i];
		else {
			re += '0';
		}
	}
	return re;
}

int main() {
	int n, e1 = 0, e2 = 0;
	string s1, s2;
	cin >> n >> s1 >> s2;
	string s1_deal = deal(s1, n, e1);
	string s2_deal = deal(s2, n, e2);
	if (s1_deal == s2_deal && e1 == e2)
		cout << "YES 0." << s1_deal << "*10^" << e1 << endl;
	else {
		cout << "NO 0." << s1_deal << "*10^" << e1 << " " << "0." << s2_deal << "*10^" << e2 << endl;
	}
	return 0;
}