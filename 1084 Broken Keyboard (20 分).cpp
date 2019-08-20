#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char>broken;

bool search(char ch) {
	for (int i = 0; i < broken.size(); i++)
		if (broken[i] == ch)
			return true;
	return false;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s2.find(s1[i]) == string::npos) {
			if (isalpha(s1[i])) {
				s1[i] = toupper(s1[i]);
			}
			if (search(s1[i]) == false)
				broken.push_back(s1[i]);
		}
	}

	for (int i = 0; i < broken.size(); i++)
		cout << broken[i];
	return 0;
}