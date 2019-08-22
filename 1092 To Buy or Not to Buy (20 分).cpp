#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int left = 0;
	for (int i = 0; i < s2.size(); i++) {
		int pos = s1.find(s2[i]);
		if (pos == string::npos)
			left++;
		else
			s1.erase(pos, 1);
	}
	if (left == 0) {
		cout << "Yes " << s1.size();
	}
	else {
		cout << "No " << left;
	}
	return 0;
}