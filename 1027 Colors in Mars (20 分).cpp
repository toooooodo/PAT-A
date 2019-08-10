#include <iostream>
#include <string>

using namespace std;

string conv(int x) {
	string result = "";
	for (int i = 0; i < 2; i++) {
		int dig = x % 13;
		if (dig < 10)
			result = (char)(dig + '0') + result;
		else
			result = (char)(dig - 10 + 'A') + result;
		x /= 13;
	}
	return result;
}

int main() {
	string mars_color = "#";
	for (int i = 0; i < 3; i++) {
		int color;
		cin >> color;
		mars_color += conv(color);
	}
	cout << mars_color << endl;
	return 0;
}