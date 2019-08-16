#include <iostream>
#include <set>

using namespace std;

#define MAXN 51
#define RANGE 1000000001

set<int> sets[MAXN];
//bool table[MAXN][RANGE] = { false };


int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int x;
			cin >> x;
			//table[i][x] = true;
			sets[i].insert(x);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, common = 0;
		cin >> a >> b;
		for (auto it = sets[a].begin(); it != sets[a].end(); it++) {
			if (sets[b].find(*it) != sets[b].end())
				common++;
			//if (table[b][*it] == true)
			//	common++;
		}
		int total = sets[a].size() + sets[b].size();
		printf("%.1f%%\n", (100.0*(common) / (total - common)));
	}
	return 0;
}