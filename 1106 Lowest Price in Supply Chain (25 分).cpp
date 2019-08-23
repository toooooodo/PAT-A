#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 100000

vector<int> tree[MAX];

void level_order(int root, double p, double r, double &price, int &m) {
	queue<int> q;
	q.push(root);
	int this_level_num = 1;
	int level = 0;
	while (q.empty() == false) {
		int next_level_num = 0;
		int retailer = 0;
		for (int i = 0; i < this_level_num; i++) {
			int front = q.front();
			q.pop();
			if (tree[front].size() == 0)
				retailer++;
			else {
				for (int j = 0; j < tree[front].size(); j++) {
					q.push(tree[front][j]);
					next_level_num++;
				}
			}
		}

		if (retailer != 0) {
			m = retailer;
			price = pow(1 + r / 100, level)*p;
			break;
		}
		level++;
		this_level_num = next_level_num;
	}
}

int main() {
	int n, m;
	double p, r;
	double price;
	cin >> n >> p >> r;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int child;
			cin >> child;
			tree[i].push_back(child);
		}
	}
	level_order(0, p, r, price, m);
	printf("%.4f %d\n", price, m);
	return 0;
}