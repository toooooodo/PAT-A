#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<char> stu_set, not_stu_set;
vector<char> stu_vec;

int main() {
	int k, index = 0;
	string s;
	cin >> k >> s;
	while (index < s.size()) {
		int len = 1;
		char ch = s[index];
		while (index + 1 < s.size() && s[index + 1] == ch) {
			index++;
			len++;
		}
		if (len%k == 0 && not_stu_set.find(ch) == not_stu_set.end()) {
			if (stu_set.find(ch) == stu_set.end()) {
				stu_set.insert(ch);
				stu_vec.push_back(ch);
			}
		}
		if (len%k != 0) {
			not_stu_set.insert(ch);
			if (stu_set.find(ch) != stu_set.end()) {
				stu_set.erase(ch);
				for (auto it = stu_vec.begin(); it != stu_vec.end(); it++) {
					if (*it == ch) {
						stu_vec.erase(it);
						break;
					}
				}
			}
		}
		index++;
	}
	for (int i = 0; i < stu_vec.size(); i++)
		cout << stu_vec[i];
	cout << endl;
	index = 0;
	while (index < s.size()) {
		if (stu_set.find(s[index]) == stu_set.end()) {
			cout << s[index];
			index++;
		}
		else {
			cout << s[index];
			index += k;
		}
	}
	return 0;
}