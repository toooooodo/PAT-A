#include <iostream>
#include <string>
#include <set>

using namespace std;

#define MAX 1010

string names[MAX];
set<string> winner;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	for (int i = 1; i <= m; i++)
		cin >> names[i];
	int index = s;
	if (index > m)
		cout << "Keep going..." << endl;
	else {
		while (index <= m) {
			while (winner.find(names[index]) != winner.end() && index <= m) {
				index++;
			}
			if (index <= m) {
				winner.insert(names[index]);
				cout << names[index] << endl;
				index += n;
			}
		}
	}
	return 0;
}