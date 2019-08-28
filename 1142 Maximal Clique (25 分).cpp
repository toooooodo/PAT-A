#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 210

bool graph[MAX][MAX] = { false };
bool in_set[MAX];

int check_clique(vector<int>& vec, int n) {
	//0 => Not a Clique; 1 => Not Maximal; 2 => Yes
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i + 1; j < vec.size(); j++) {
			if (graph[vec[i]][vec[j]] == false)
				return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (in_set[i] == true)
			continue;
		bool flg = true;
		for (int j = 0; j < vec.size(); j++) {
			if (graph[i][vec[j]] == false) {
				flg = false;
				break;
			}
		}
		if (flg == true)
			return 1;
	}
	return 2;
}

int main() {
	int nv, ne, m;
	cin >> nv >> ne;
	for (int i = 0; i < ne; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = graph[v2][v1] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int k, flg;
		vector<int> vec;
		cin >> k;
		vec.resize(k);
		fill(in_set, in_set + MAX, false);
		for (int j = 0; j < k; j++) {
			cin >> vec[j];
			in_set[vec[j]] = true;
		}
		flg = check_clique(vec, nv);
		if (flg == 0)
			cout << "Not a Clique" << endl;
		else if (flg == 1)
			cout << "Not Maximal" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}