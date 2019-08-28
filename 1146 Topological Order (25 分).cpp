#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

vector<int> edge[MAX];
vector<int> in_degree, res;

bool check(vector<int> &seq, int n) {
	vector<int> in = in_degree;
	for (int i = 0; i < n; i++) {
		int v = seq[i];
		if (in[v] == 0) {
			for (int j = 0; j < edge[v].size(); j++) {
				in[edge[v][j]]--;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m, k;
	cin >> n >> m;
	in_degree.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		in_degree[v2]++;
		edge[v1].push_back(v2);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> seq;
		seq.resize(n);
		for (int j = 0; j < n; j++)
			cin >> seq[j];
		if (check(seq, n) == false)
			res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++) {
		if (i == 0)
			cout << res[i];
		else
			cout << " " << res[i];
	}
	return 0;
}