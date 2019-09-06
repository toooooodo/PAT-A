#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

set<string> alumni;
vector<string>guest, al_guest;

bool cmp(string a, string b) {
	return a.substr(6, 8) < b.substr(6, 8);
}

int main() {
	int n, m;
	string id;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> id;
		alumni.insert(id);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> id;
		guest.push_back(id);
		if (alumni.find(id) != alumni.end()) {
			al_guest.push_back(id);
		}
	}
	cout << al_guest.size() << endl;
	if (al_guest.size() == 0) {
		sort(guest.begin(), guest.end(), cmp);
		cout << guest[0] << endl;
	}
	else {
		sort(al_guest.begin(), al_guest.end(), cmp);
		cout << al_guest[0] << endl;
	}
	return 0;
}