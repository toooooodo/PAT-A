#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define MAX 10010

int father[MAX];
set<int> birds;

int find_father(int x) {
	if (father[x] == x)
		return x;
	else {
		int f = find_father(father[x]);
		father[x] = f;
		return f;
	}
}

void _union(int a, int b) {
	int f_a = find_father(a);
	int f_b = find_father(b);
	if (f_a != f_b)
		father[f_a] = f_b;
}

int main() {
	for (int i = 0; i < MAX; i++)
		father[i] = i;
	int n, q, forest = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k, b;
		cin >> k >> b;
		birds.insert(b);
		for (int j = 1; j < k; j++) {
			int b2;
			cin >> b2;
			_union(b, b2);
			birds.insert(b2);
		}
	}
	for (auto it = birds.begin(); it != birds.end(); it++) {
		if (find_father(*it) == *it)
			forest++;
	}
	cout << forest << " " << birds.size() << endl;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (find_father(a) == find_father(b))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}