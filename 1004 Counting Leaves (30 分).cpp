#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 101

vector<int>node[MAX];
vector<int>level_leaf;
queue<int>q;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			int child;
			cin >> child;
			node[id].push_back(child);
		}
	}
	q.push(1);
	int this_level_num = 1;
	while (q.empty() == false) {
		int next_level_num = 0;
		int leaf = 0;
		for (int i = 0; i < this_level_num; i++) {
			int node_id = q.front();
			q.pop();
			if (node[node_id].empty()) {
				leaf++;
				continue;
			}
			for (int j = 0; j < node[node_id].size(); j++) {
				next_level_num++;
				q.push(node[node_id][j]);
			}
		}
		this_level_num = next_level_num;
		level_leaf.push_back(leaf);
	}
	for (int i = 0; i < level_leaf.size(); i++) {
		if (i == 0)
			printf("%d", level_leaf[i]);
		else
			printf(" %d", level_leaf[i]);
	}
	return 0;
}