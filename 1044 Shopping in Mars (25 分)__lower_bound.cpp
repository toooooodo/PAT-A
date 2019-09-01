#include <iostream>
#include <vector>

using namespace std;

#define MAX 100010

int diam[MAX] = { 0 };
struct node {
	int left, right;
	node() {}
	node(int left, int right) :left(left), right(right) {}
};
vector<node> res;

int low_bound(int left, int right, int x) {
	while (left < right) {
		int mid = (left + right) / 2;
		if (diam[mid] < x)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int main() {
	int n, m, min_diff = 0x7fffffff;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> diam[i];
		diam[i] += diam[i - 1];
	}
	for (int i = 0; i <= n; i++) {
		int right = low_bound(i, n + 1, diam[i] + m);
		if (right != n + 1) {
			int diff = diam[right] - diam[i];
			if (diff < min_diff) {
				min_diff = diff;
				res.clear();
				res.push_back(node(i + 1, right));
			}
			else if (diff == min_diff)
				res.push_back(node(i + 1, right));
		}
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i].left << "-" << res[i].right << endl;
	return 0;
}