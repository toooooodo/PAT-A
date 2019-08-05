#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100

struct node {
	int weight;
	vector<int> child;
};
struct node tree[MAX];
vector<int> path;

bool cmp(int a, int b) {
	return tree[a].weight > tree[b].weight;
}

void DFS(int sum_weight, int index, int s) {
	if (sum_weight == s) {
		if (tree[index].child.size() != 0) {
			return;
		}
		for (int i = 0; i < path.size(); i++) {
			if (i == 0)
				printf("%d", tree[path[i]].weight);
			else
				printf(" %d", tree[path[i]].weight);
		}
		printf("\n");
		return;
	}
	if (sum_weight > s) {
		return;
	}
	for (int i = 0; i < tree[index].child.size(); i++) {
		path.push_back(tree[index].child[i]);
		DFS(sum_weight + tree[tree[index].child[i]].weight, tree[index].child[i], s);
		path.pop_back();
	}
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> tree[i].weight;
	}
	for (int i = 0; i < m; i++) {
		int index, num_child;
		cin >> index >> num_child;
		for (int j = 0; j < num_child; j++) {
			int child;
			cin >> child;
			tree[index].child.push_back(child);
		}
		sort(tree[index].child.begin(), tree[index].child.end(), cmp);
	}
	path.push_back(0);
	DFS(tree[0].weight, 0, s);
	return 0;
}