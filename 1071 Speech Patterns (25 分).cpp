#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, int> mp;
	string s, word = "";
	getline(cin, s);
	bool in_word = false;
	for (int i = 0; i < s.size(); i++) {
		if (isalpha(s[i])) {
			s[i] = tolower(s[i]);
		}
		if (isalnum(s[i])) {
			word += s[i];
			if (in_word == false)
				in_word = true;
		}
		else {
			if (in_word == true) {
				mp[word]++;
				in_word = false;
				word = "";
			}
				
		}
	}
	if (in_word == true)
		mp[word]++;
	int max_c = -1;
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > max_c) {
			max_c = it->second;
			word = it->first;
		}
	}
	cout << word << " " << max_c << endl;
	return 0;
}