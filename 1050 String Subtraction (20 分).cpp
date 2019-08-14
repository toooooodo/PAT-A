#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	string s1, s2, result = "";
	getline(cin, s1);
	getline(cin, s2);
	set<char> s;
	for (int i = 0; i < s2.size(); i++)
		s.insert(s2[i]);
	for (int i = 0; i < s1.size(); i++)
		if (s.find(s1[i]) == s.end())
			result += s1[i];
	cout << result << endl;
	return 0;
}