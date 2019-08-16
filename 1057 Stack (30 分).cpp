#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

#define BLOCK_NUM 316
#define MAX 100001

stack<int> stk;
int block[BLOCK_NUM + 1] = { 0 }, table[MAX] = { 0 };

int pick_med(int pos) {
	int sum = 0, index = 0;
	while (sum + block[index] < pos) {
		sum += block[index++];
	}
	int num = index * BLOCK_NUM;
	while (sum + table[num] < pos) {
		sum += table[num++];
	}
	return num;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "Pop") {
			if (stk.empty())
				cout << "Invalid" << endl;
			else {
				int x = stk.top();
				stk.pop();
				block[x / BLOCK_NUM]--;
				table[x]--;
				cout << x << endl;
			}
		}
		else if (cmd == "PeekMedian") {
			if (stk.empty())
				cout << "Invalid" << endl;
			else {
				int pos;
				if (stk.size() % 2 == 0)
					pos = stk.size() / 2;
				else
					pos = (stk.size() + 1) / 2;
				cout << pick_med(pos) << endl;
			}
		}
		else {
			int x;
			cin >> x;
			stk.push(x);
			block[x / BLOCK_NUM]++;
			table[x]++;
		}
	}
	return 0;
}