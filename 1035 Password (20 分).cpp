#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 1000
struct user {
	string id;
	string password;
}users[MAX];
vector<int> modified;

bool modify(string& s) {
	bool flag = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1' || s[i] == '0' || s[i] == 'l' || s[i] == 'O') {
			flag = true;
			if (s[i] == '1')
				s[i] = '@';
			else if (s[i] == '0')
				s[i] = '%';
			else if (s[i] == 'l')
				s[i] = 'L';
			else
				s[i] = 'o';
		}
	}
	return flag;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> users[i].id >> users[i].password;
		if (modify(users[i].password))
			modified.push_back(i);
	}
	if (modified.size() == 0 && n == 1)
		printf("There is 1 account and no account is modified\n");
	else if (modified.size() == 0)
		printf("There are %d accounts and no account is modified\n", n);
	else {
		cout << modified.size() << endl;
		for (int i = 0; i < modified.size(); i++)
			cout << users[modified[i]].id << " " << users[modified[i]].password << endl;
	}
	return 0;
}