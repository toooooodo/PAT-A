#include <iostream>
#include <string>

using namespace std;

string get_base(string s) {
	string base = "";
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]) || s[i] == '.') {
			base += s[i];
		}
		else if (s[i] == 'E')
			break;
	}
	return base;
}

int get_exp(string s) {
	int e_pos = s.find('E'), exp = 0, times = 1;
	bool neg = s[e_pos + 1] == '-' ? true : false;
	for (int i = s.size() - 1; i > e_pos + 1; i--) {
		exp += times * (s[i] - '0');
		times *= 10;
	}
	return neg == true ? -exp : exp;
}

int main() {
	string s;
	cin >> s;
	bool neg = s[0] == '-' ? true : false;
	string base = get_base(s);
	int exp = get_exp(s);
	int dot_pos = base.find('.');
	if (exp <= 0) {
		int count = 0;
		while (count > exp) {
			count--;
			base = '0' + base;
		}
		base.erase(base.find('.'), 1);
		base.insert(1, ".");
	}
	else {
		int count = 0;
		for (int i = dot_pos + 1; i < base.size(); i++) {
			count++;
			if (count == exp && i != base.size() - 1) {
				base.insert(i + 1, ".");
			}
		}

		while (count < exp) {
			count++;
			base += '0';
		}
		base.erase(dot_pos, 1);


	}
	if (neg)
		cout << "-";
	cout << base << endl;
	return 0;
}