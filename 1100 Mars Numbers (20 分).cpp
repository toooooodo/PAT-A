#include <iostream>
#include <string>

using namespace std;

string digit[] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string ten[] = { "tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };

int mars_to_earth(string x) {
	int t = -1, d = -1;
	string first, second;
	bool flg = false;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == ' ') {
			flg = true;
		}
		else {
			if (flg)
				second += x[i];
			else
				first += x[i];
		}

	}
	if (flg) {
		for (int i = 0; i < 13; i++) {
			if (digit[i] == second) {
				d = i;
				break;
			}
		}
		for (int i = 0; i < 12; i++) {
			if (ten[i] == first) {
				t = i + 1;
				break;
			}
		}
		return t * 13 + d;
	}
	else {
		for (int i = 0; i < 13; i++) {
			if (digit[i] == first) {
				d = i;
				break;
			}
		}
		if (d != -1)
			return d;
		else {
			for (int i = 0; i < 13; i++) {
				if (ten[i] == first) {
					d = i + 1;
					break;
				}
			}
			return d * 13;
		}
	}
}

string earth_to_mars(string x) {
	int number = stoi(x);
	string mars = "";
	if (number / 13 == 0)
		mars = digit[number];
	else {
		if (number % 13 != 0)
			mars = ten[number / 13 - 1] + " " + digit[number % 13];
		else
			mars = ten[number / 13 - 1];
	}
	return mars;
}

int main() {
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string x;
		getline(cin, x);
		if (isdigit(x[0])) {
			cout << earth_to_mars(x) << endl;
		}
		else {
			cout << mars_to_earth(x) << endl;
		}
	}
	return 0;
}