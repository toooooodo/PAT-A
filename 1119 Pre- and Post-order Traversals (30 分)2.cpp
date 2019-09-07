#include <iostream>
#include <vector>

using namespace std;

#define MAX 30

int pre[MAX], post[MAX];
vector<int> in;

//void in_order(int pre_left, int pre_right, int post_left, int post_right, bool &unique) {
//	if (pre_left > pre_right)
//		return;
//	int index = pre_left + 1;
//	while (pre[index] != post[post_right - 1] && index <= pre_right) {
//		index++;
//	}
//	if (pre_left != pre_right && index - pre_left == 1)
//		unique = false;
//	else
//		in_order(pre_left + 1, index - 1, post_left, post_left + index - pre_left - 2, unique);
//	in.push_back(pre[pre_left]);
//	in_order(index, pre_right, post_left + index - pre_left - 1, post_right - 1, unique);
//}

void in_order(int pre_left, int pre_right, int post_left, int post_right, bool &unique) {
	if (pre_left > pre_right)
		return;
	if (pre_left == pre_right) {
		in.push_back(pre[pre_left]);
		return;
	}
	int index = post_left;
	while (index <= post_right && post[index] != pre[pre_left + 1])
		index++;
	in_order(pre_left + 1, pre_left + index - post_left + 1, post_left, index, unique);
	in.push_back(pre[pre_left]);
	if (index == post_left && index + 1 == post_right)
		unique = false;
	else
		in_order(pre_left + index - post_left + 2, pre_right, index + 1, post_right - 1, unique);

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	bool unique = true;
	in_order(0, n - 1, 0, n - 1, unique);
	if (unique)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = 0; i < n; i++) {
		if (i != 0)
			cout << " ";
		cout << in[i];
	}
	cout << endl;
	return 0;
}