#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


vector<int> tmp, result;

void dfs(int n, int sum, int fac_sum, int i, int p, int k, int& max_fac_sum) {
	if (i == 0)
		return;
	if (sum > n || tmp.size() > k)
		return;
	if (sum == n && tmp.size() == k) {
		if (fac_sum > max_fac_sum) {
			max_fac_sum = fac_sum;
			result = tmp;
		}
	}
	else {
		tmp.push_back(i);
		dfs(n, sum + (int)pow(i, p), fac_sum + i, i, p, k, max_fac_sum);
		tmp.pop_back();
		dfs(n, sum, fac_sum, i - 1, p, k, max_fac_sum);
	}
}

int main() {
	int n, k, p, max_fac_sum = -1;
	cin >> n >> k >> p;
	dfs(n, 0, 0, (int)sqrt(n), p, k, max_fac_sum);
	if (result.size() == 0)
		cout << "Impossible" << endl;
	else {
		// 169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2
		cout << n << " =";
		for (int i = 0; i < result.size(); i++) {
			if (i != 0)
				cout << " +";
			cout << " " << result[i] << "^" << p;
		}
	}

	return 0;
}