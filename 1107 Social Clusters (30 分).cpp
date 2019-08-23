#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1010

int father[MAX], hobby[MAX], root[MAX];
vector<int> cluster;

int find_father(int x) {
	if (father[x] == x) {
		return x;
	}
	else {
		int f = find_father(father[x]);
		father[x] = f;
		return f;
	}
}

void _union(int a, int b) {
	int father_a = find_father(a);
	int father_b = find_father(b);
	if (father_a != father_b)
		father[father_a] = father_b;
}

bool cmp(int a, int b) { return a > b; }

int main() {
	int n;
	cin >> n;
	fill(hobby, hobby + MAX, 0);
	fill(root, root + MAX, 0);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d:", &k);
		for (int j = 0; j < k; j++) {
			int h;
			cin >> h;
			if (hobby[h] == 0)
				hobby[h] = i;
			_union(i, hobby[h]);
		}

	}
	for (int i = 1; i <= n; i++) {
		root[find_father(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		if (root[i] > 0) {
			cluster.push_back(root[i]);
		}
	}
	sort(cluster.begin(), cluster.end(), cmp);
	cout << cluster.size() << endl;
	for (auto it = cluster.begin(); it != cluster.end(); it++) {
		if (it == cluster.begin())
			cout << *it;
		else
			cout << " " << *it;
	}
	return 0;
}