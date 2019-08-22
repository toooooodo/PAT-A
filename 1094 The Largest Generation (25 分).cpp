#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100

vector<int> family[MAX];

void calc(int root, int &max_layer, int &max_num) {
	queue<int> q;
	q.push(root);
	max_layer = 1;
	max_num = 1;
	int this_layer_num = max_num;
	int layer = max_layer;
	while (q.empty() == false) {
		int next_layer_num = 0;
		for (int i = 0; i < this_layer_num; i++) {
			int front = q.front();
			q.pop();
			for (int j = 0; j < family[front].size(); j++) {
				q.push(family[front][j]);
				next_layer_num++;
			}
		}
		this_layer_num = next_layer_num;
		layer++;
		if (this_layer_num > max_num) {
			max_num = this_layer_num;
			max_layer = layer;
		}
	}
}

int main() {
	int n, m, root = 1, layer, num;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			int child;
			cin >> child;
			family[id].push_back(child);
		}
	}
	calc(root, layer, num);
	cout << num << " " << layer << endl;
	return 0;
}