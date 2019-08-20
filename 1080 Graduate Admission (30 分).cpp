#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 40000
#define MAXM 100
#define MAXK 5

int quota[MAXM];
struct appli {
	int ge, gi, _sum;
	int choices[MAXK];
	int id;
}applics[MAXN];
vector<int> admission[MAXM];

bool cmp(appli a, appli b) {
	if (a._sum != b._sum)
		return a._sum > b._sum;
	else
		return a.ge > b.ge;
}

bool cmp2(int a, int b) {
	return applics[a].id < applics[b].id;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
		cin >> quota[i];
	for (int i = 0; i < n; i++) {
		applics[i].id = i;
		cin >> applics[i].ge >> applics[i].gi;
		applics[i]._sum = applics[i].ge + applics[i].gi;
		for (int j = 0; j < k; j++) {
			cin >> applics[i].choices[j];
		}
	}
	sort(applics, applics + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int j = 0; j < k; j++) {
				int school = applics[i].choices[j];
				if (admission[school].size() < quota[school]) {
					admission[school].push_back(i);
					break;
				}

			}
		}
		else {
			for (int j = 0; j < k; j++) {
				int school = applics[i].choices[j];
				if (admission[school].size() >= quota[school]) {
					int last = admission[school][admission[school].size() - 1];
					if (applics[i]._sum == applics[last]._sum && applics[i].ge == applics[last].ge) {
						admission[school].push_back(i);
						break;
					}
				}
				else {
					admission[school].push_back(i);
					break;
				}

			}
		}
	}
	for (int i = 0; i < m; i++) {
		sort(admission[i].begin(), admission[i].end(), cmp2);
		for (int j = 0; j < admission[i].size(); j++) {
			if (j == 0)
				cout << applics[admission[i][j]].id;
			else
				cout << " " << applics[admission[i][j]].id;
		}
		cout << endl;
	}
	return 0;
}