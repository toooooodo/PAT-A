#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

#define MAX 1001

int call[MAX][MAX] = { 0 };
int father[MAX];
set<int> suspect;
map<int, int> root_to_gang;
vector<int> gangs[MAX];
//vector<vector<int> > gangs;

int find_father(int x) {
	if (x == father[x])
		return x;
	else {
		int f = find_father(father[x]);
		father[x] = f;
		return f;
	}
}

void _union(int a, int b) {
	int fa = find_father(a);
	int fb = find_father(b);
	if (fa != fb)
		father[fa] = fb;
}

bool cmp(vector<int> &a, vector<int> &b) {
	return a[0] < b[0];
}

int main() {
	int k, n, m, gangs_num = 0;
	cin >> k >> n >> m;
	for (int i = 1; i < MAX; i++)
		father[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, len;
		cin >> a >> b >> len;
		call[a][b] += len;
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0, recall_sum = 0;
		for (int j = 1; j <= n; j++) {
			if (call[i][j] > 0 && call[i][j] <= 5) {
				sum++;
				if (call[j][i] > 0)
					recall_sum++;
			}
		}
		if (sum > k && 1.0*recall_sum / sum <= 0.2) {
			suspect.insert(i);
		}
	}
	if (suspect.size() == 0) {
		cout << "None" << endl;
		return 0;
	}
	for (auto it = suspect.begin(); it != suspect.end(); it++) {
		for (int i = 1; i <= n; i++) {
			if (call[*it][i] > 0 && call[i][*it] > 0 && suspect.find(i) != suspect.end()) {
				_union(*it, i);
			}
		}
	}
	for (auto it = suspect.begin(); it != suspect.end(); it++) {
		int gang_index;
		if (root_to_gang.find(find_father(*it)) == root_to_gang.end()) {
			gang_index = gangs_num;
			root_to_gang[find_father(*it)] = gangs_num++;
			gangs[gang_index].push_back(*it);
		}
		else {
			gang_index = root_to_gang[find_father(*it)];
			gangs[gang_index].push_back(*it);
		}
	}
	for (int i = 0; i < gangs_num; i++)
		sort(gangs[i].begin(), gangs[i].end());
	sort(gangs, gangs + gangs_num, cmp);
	for (int i = 0; i < gangs_num; i++) {
		for (int j = 0; j < gangs[i].size(); j++) {
			if (j == 0)
				cout << gangs[i][j];
			else
				cout << " " << gangs[i][j];
		}
		cout << endl;
	}
	return 0;
}