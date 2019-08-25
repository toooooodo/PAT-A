#include <iostream>
#include <vector>

using namespace std;

#define MAX 30

int pre[MAX], post[MAX];
vector<int> in;
bool unique = true;

void in_order(int pre_left, int pre_right, int post_left, int post_right) {
	if (pre_left > pre_right)
		return;
	int index = pre_left + 1;
	while (index <= pre_right && pre[index] != post[post_right - 1])
		index++;
	if (index - pre_left <= 1 && pre_left != pre_right) {
		unique = false;
	}
	else {
		in_order(pre_left + 1, index - 1, post_left, post_left + index - pre_left - 1 - 1);
	}
	in.push_back(pre[pre_left]);
	in_order(index, pre_right, post_left + index - pre_left - 1, post_right - 1);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	in_order(0, n - 1, 0, n - 1);
	if (unique == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < in.size(); i++) {
		if (i != 0)
			cout << " ";
		cout << in[i];
	}
	cout << endl;
	return 0;
}