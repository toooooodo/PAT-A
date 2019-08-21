#include <iostream>
#include <string>

using namespace std;

string number[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
string digit[] = { "Shi","Bai","Qian","Wan","Yi" };

int main() {
	string s;
	cin >> s;
	int left = 0, right = s.size() - 1;
	if (s[0] == '-') {
		cout << "Fu";
		left++;
	}
	while (left + 4 <= right) {
		right -= 4;
	}
	while (left < s.size()) {
		bool print = false;
		bool zero_left = false;
		while (left <= right) {
			if (left > 0 && s[left] == '0') {
				zero_left = true;
			}
			else {
				if (zero_left == true) {
					cout << " ling";
					zero_left = false;
				}
				if (left > 0)
					cout << " ";
				cout << number[s[left] - '0'];
				print = true;
				if (left != right) {
					cout << " " << digit[right - left - 1];
				}
			}
			left++;
		}
		if (print == true && right != s.size() - 1) {
			cout << " " << digit[(s.size() - 1 - right) / 4 + 2];
		}
		right += 4;
	}
	return 0;
}