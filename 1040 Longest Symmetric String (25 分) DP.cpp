#include <iostream>
#include <string>

using namespace std;

#define MAX 1001

int dp[MAX][MAX] = { 0 };

int main() {
	string s = "";
	int ans = 1;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		dp[i][i] = 1;
		if (i < s.size() - 1 && s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int l = 3; l <= s.size(); l++) {
		for (int i = 0; i + l - 1 < s.size(); i++) {
			int j = i + l - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
				dp[i][j] = 1;
				ans = l;
			}
		}
	}
	cout << ans << endl;
	return 0;
}