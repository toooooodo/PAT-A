#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1010

bool board[MAX][MAX];

bool check_margin(int x, int y, int n) {
	if (x == 0 || y == 0)
		return false;
	if (x > n || y > n)
		return false;
	return true;
}

bool check(vector<int> queens, int n) {
	for (int i = 0; i < queens.size(); i++) {
		for (int j = 1; j <= n; j++) {
			if (board[queens[i]][j] == true && j != i + 1)
				return false;
		}
		int x = queens[i] - 1, y = i;
		while (check_margin(x, y, n)) {
			if (board[x][y] == true)
				return false;
			x--, y--;
		}
		x = queens[i] + 1, y = i + 2;
		while (check_margin(x, y, n)) {
			if (board[x][y] == true)
				return false;
			x++, y++;
		}
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		fill(board[0], board[0] + MAX * MAX, false);
		vector<int> queens;
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			board[x][j] = true;
			queens.push_back(x);
		}
		if (check(queens, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}