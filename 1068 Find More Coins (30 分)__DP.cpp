#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10001;
const int maxm = 101;
int dp[maxm] = { 0 }, value[maxn];
bool choice[maxn][maxm], flag[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> value[i];
	sort(value + 1, value + 1 + n, cmp);
	for (int i = 1; i <= n; i++) {
		for (int v = m; v >= value[i]; v--) {
			if (dp[v] <= dp[v - value[i]] + value[i]) {
				dp[v] = dp[v - value[i]] + value[i];
				choice[i][v] = true;
			}
			else {
				choice[i][v] = false;
			}
		}
	}
	if (dp[m] != m)
		cout << "No Solution" << endl;
	else {
		int v = m;
		int count = 0;
		for (int i = n; i > 0; i--) {
			if (choice[i][v] == true) {
				flag[i] = true;
				v -= value[i];
				count++;
			}
		}
		for (int i = n; i > 0; i--) {
			if (flag[i] == true) {
				if (count-- == 1)
					cout << value[i] << endl;
				else
					cout << value[i] << " ";
			}
		}
	}

	return 0;
}