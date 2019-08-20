#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX 100000

struct node {
	int layer;
	int amount;
	vector<int> children;
}chain[MAX];

double get_sales(int n, double price, double rate) {
	int layer = 0;
	double total_sales = 0;
	queue<int> q;
	int this_layer_num = 1;
	chain[0].layer = 0;
	q.push(0);
	while (q.empty() == false) {
		int next_layer_num = 0;
		layer++;
		for (int i = 0; i < this_layer_num; i++) {
			int front = q.front();
			q.pop();
			if (chain[front].children.empty()) {
				total_sales += pow(1 + rate / 100, (double)chain[front].layer)*price*chain[front].amount;
			}
			else {
				for (int j = 0; j < chain[front].children.size(); j++) {
					int child = chain[front].children[j];
					q.push(child);
					chain[child].layer = layer;
					next_layer_num++;
				}
			}
		}
		this_layer_num = next_layer_num;
	}
	return total_sales;
}

int main() {
	int n;
	double price, rate;
	cin >> n >> price >> rate;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			cin >> chain[i].amount;
		}
		else {
			for (int j = 0; j < num; j++) {
				int child;
				cin >> child;
				chain[i].children.push_back(child);
			}

		}
	}
	printf("%.1f\n", get_sales(n, price, rate));
	return 0;
}