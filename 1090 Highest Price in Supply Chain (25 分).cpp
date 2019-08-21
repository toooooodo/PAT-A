#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100000

vector<int> tree[MAX];

void cal(int n, int root, int &num, double &price, double p, double r) {
	queue<int> q;
	q.push(root);
	num = 1;
	int layer = 0;
	while (q.empty() == false) {

		int next_layer_num = 0;

		for (int j = 0; j < num; j++) {
			int front = q.front();
			q.pop();
			for (int i = 0; i < tree[front].size(); i++) {
				q.push(tree[front][i]);
				next_layer_num++;
			}
		}

		if (next_layer_num != 0) {
			num = next_layer_num;
			layer++;
		}

	}
	price = pow(1 + r / 100, layer)*p;
}

int main() {
	int n, root, num;
	double p, r, price;
	cin >> n >> p >> r;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == -1)
			root = i;
		else {
			tree[x].push_back(i);
		}
	}
	cal(n, root, num, price, p, r);
	printf("%.2f %d\n", price, num);
	return 0;
}