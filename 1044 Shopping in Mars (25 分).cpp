#include <iostream>
#include <vector>

using namespace std;

#define MAX 100001

struct p {
	int begin, end;
	p() {}
	p(int begin, int end) :begin(begin), end(end) {}
};
vector<p> res;
int sum[MAX];

int upper_bound(int left, int right, int x) {
	/*
	返回在[left, right)范围内第一个大于x的位置
	return: [left, right]
	*/
	while (left < right) {
		int mid = (left + right) / 2;
		if (sum[mid] > x)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

int main() {
	int n, m;
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}
	int min_diff = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, sum[i - 1] + m);
		if (sum[j - 1] - sum[i - 1] == m) {
			if (min_diff != 0) {
				min_diff = 0;
				res.clear();
			}
			res.push_back(p(i, j - 1));
		}
		else if (j != n + 1) {
			if (sum[j] - sum[i - 1] - m < min_diff) {
				min_diff = sum[j] - sum[i - 1] - m;
				res.clear();
				res.push_back(p(i, j));
			}
			else if (sum[j] - sum[i - 1] - m == min_diff) {
				res.push_back(p(i, j));
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		printf("%d-%d\n", res[i].begin, res[i].end);
	}
	return 0;
}