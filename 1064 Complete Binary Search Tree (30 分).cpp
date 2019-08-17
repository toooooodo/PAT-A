#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001

int tree[MAX], seq[MAX];

void inorder(int root, int &index, int n) {
	if (root > n)
		return;
	inorder(root * 2, index, n);
	tree[root] = seq[index++];
	inorder(root * 2 + 1, index, n);
}

int main() {
	int n, index = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> seq[i];
	sort(seq + 1, seq + 1 + n);
	inorder(1, index, n);
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			cout << tree[i];
		else
			cout << " " << tree[i];
	}

	return 0;
}