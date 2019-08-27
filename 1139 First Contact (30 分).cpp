#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define MAX 10000

bool graph[MAX][MAX] = { false };
vector<int> same_gender_friends[MAX];

struct F {
	int a, b;
	F(int a, int b) :a(a), b(b) {}
};

void search(vector<F> &res, int a, int b) {
	// a---c---d---b
	for (int i = 0; i < same_gender_friends[a].size(); i++) {
		for (int j = 0; j < same_gender_friends[b].size(); j++) {
			int c = same_gender_friends[a][i];
			int d = same_gender_friends[b][j];
			if (c == d || c == b || a == d)
				continue;
			if (graph[c][d] == true) {
				res.push_back(F(c, d));
			}
		}
	}
}

bool cmp(F a, F b) {
	if (a.a != b.a)
		return a.a < b.a;
	else
		return a.b < b.b;
}

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string a, b;
		cin >> a >> b;
		if (a.size() == b.size()) {
			same_gender_friends[abs(stoi(a))].push_back(abs(stoi(b)));
			same_gender_friends[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		graph[abs(stoi(a))][abs(stoi(b))] = graph[abs(stoi(b))][abs(stoi(a))] = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		vector<F> res;
		search(res, abs(a), abs(b));
		sort(res.begin(), res.end(), cmp);
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			printf("%04d %04d\n", res[i].a, res[i].b);
		}
	}
	return 0;
}