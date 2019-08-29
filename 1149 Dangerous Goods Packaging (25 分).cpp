#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

#define MAX 100000

vector<int> incom[MAX];

bool check(unordered_set<int> &goods) {
	for (auto it = goods.begin(); it != goods.end(); it++) {
		int good = *it;
		for (int i = 0; i < incom[good].size(); i++) {
			if (goods.find(incom[good][i]) != goods.end())
				return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int g1, g2;
		cin >> g1 >> g2;
		incom[g1].push_back(g2);
		incom[g2].push_back(g1);
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		unordered_set<int> goods;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			goods.insert(x);
		}
		if (check(goods) == false)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}