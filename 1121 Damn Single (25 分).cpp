#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000

struct guest {
	int _friend;
	bool appear;
	guest() :_friend(-1), appear(false) {}
}guests[MAX];

vector<int> total, lonely;

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		guests[a]._friend = b;
		guests[b]._friend = a;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		guests[x].appear = true;
		total.push_back(x);
	}
	for (int i = 0; i < m; i++) {
		if (guests[total[i]]._friend == -1)
			lonely.push_back(total[i]);
		else if (guests[guests[total[i]]._friend].appear == false)
			lonely.push_back(total[i]);
	}
	sort(lonely.begin(), lonely.end());
	cout << lonely.size() << endl;
	for (int i = 0; i < lonely.size(); i++) {
		if (i == 0)
			printf("%05d", lonely[i]);
		else
			printf(" %05d", lonely[i]);
	}
	return 0;
}