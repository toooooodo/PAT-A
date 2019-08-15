#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> mp;

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (mp.find(x) == mp.end())
				mp[x] = 1;
			else
				mp[x] += 1;
		}
	}
	for (auto it = mp.begin(); it != mp.end(); it++) {
		if (it->second > m*n / 2)
			cout << it->first << endl;
	}
	return 0;
}