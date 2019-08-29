#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define MAX 10000

struct edge {
	int v, u;
}edges[MAX];

int check(vector<int> &colors, int m) {
	set<int> cl;
	for (int i = 0; i < m; i++) {
		if (colors[edges[i].u] == colors[edges[i].v])
			return -1;
	}
	for (int i = 0; i < colors.size(); i++)
		cl.insert(colors[i]);
	return cl.size();
}

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edges[i].v >> edges[i].u;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> colors(n);
		for (int j = 0; j < n; j++)
			cin >> colors[j];
		int res = check(colors, m);
		if (res == -1)
			cout << "No" << endl;
		else
			cout << res << "-coloring" << endl;
	}
	return 0;
}