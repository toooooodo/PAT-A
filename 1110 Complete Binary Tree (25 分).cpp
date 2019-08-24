#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX 20

struct node {
	int key;
	int left, right;
	node() :left(-1), right(-1) {}
}tree[MAX];
bool appear[MAX] = { false };

bool check(int root, int n, int& value) {
	queue<int> q;
	int total = 1, this_level_num = 1;
	q.push(root);
	bool termi = false;
	while (q.empty() == false) {
		int next_level_num = 0;
		for (int i = 0; i < this_level_num; i++) {
			int front = q.front();
			q.pop();
			if (tree[front].left != -1 && tree[front].right == -1) {
				q.push(tree[front].left);
				value = tree[front].left;
				next_level_num++;
				termi = true;
				break;
			}
			else if (tree[front].left == -1 && tree[front].right == -1) {
				termi = true;
				break;
			}
			else if (tree[front].left == -1 && tree[front].right != -1) {
				return false;
			}
			else {
				q.push(tree[front].left);
				q.push(tree[front].right);
				value = tree[front].right;
				next_level_num += 2;
			}
		}
		total += next_level_num;
		if (termi == true) {
			return total == n;
		}
		this_level_num = next_level_num;
	}
}

int main() {
	int n, root, value;
	cin >> n;
	for (int i = 0; i < n; i++) {
		tree[i].key = i;
		string left, right;
		cin >> left >> right;
		if (left != "-") {
			tree[i].left = stoi(left);
			appear[tree[i].left] = true;
		}
		if (right != "-") {
			tree[i].right = stoi(right);
			appear[tree[i].right] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (appear[i] == false) {
			root = i;
			break;
		}
	}
	if (check(root, n, value) == true)
		cout << "YES " << value << endl;
	else
		cout << "NO " << root << endl;
	return 0;
}