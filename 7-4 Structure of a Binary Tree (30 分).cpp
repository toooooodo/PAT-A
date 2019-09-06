#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 30

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};
int in[MAX], post[MAX];

tree insert(int in_left, int in_right, int post_left, int post_right) {
	if (in_left > in_right)
		return NULL;
	int mid = in_left;
	while (in[mid] != post[post_right])
		mid++;
	tree root = (tree)malloc(sizeof(struct node));
	root->key = in[mid];
	root->left = insert(in_left, mid - 1, post_left, post_left + mid - in_left - 1);
	root->right = insert(mid + 1, in_right, post_left + mid - in_left, post_right - 1);
	return root;
}

void find(vector<int> &path, vector<int> &tmp, int x, tree root) {
	if (root == NULL)
		return;
	tmp.push_back(root->key);
	if (root->key != x) {
		find(path, tmp, x, root->left);
		find(path, tmp, x, root->right);
	}
	else {
		path = tmp;
	}
	tmp.pop_back();
}

void judge_left(int a, int b, tree root, bool &flg) {
	if (flg == true) {
		return;
	}
	if (root == NULL)
		return;
	if (root->key == a) {
		if (root->left != NULL && root->left->key == b) {
			flg = true;
			return;
		}
	}
	else {
		judge_left(a, b, root->left, flg);
		judge_left(a, b, root->right, flg);
	}
}

void judge_right(int a, int b, tree root, bool &flg) {
	if (flg == true) {
		return;
	}
	if (root == NULL)
		return;
	if (root->key == a) {
		if (root->right != NULL && root->right->key == b) {
			flg = true;
			return;
		}
	}
	else {
		judge_right(a, b, root->left, flg);
		judge_right(a, b, root->right, flg);
	}
}

bool check_full(tree root) {
	if (root == NULL)
		return true;
	if (root->left != NULL && root->right != NULL || root->left == NULL && root->right == NULL)
		return check_full(root->left) && check_full(root->right);
	else
		return false;
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	tree root = insert(0, n - 1, 0, n - 1);
	cin >> m;
	getchar();
	/*
	A is the root
	A and B are siblings
	A is the parent of B
	A is the left child of B
	A is the right child of B
	A and B are on the same level
	It is a full tree
	*/
	for (int i = 0; i < m; i++) {
		string x;
		getline(cin, x);
		vector<int> path_a, path_b, tmp_a, tmp_b;
		if (x.find("root") != -1) {
			int root_num = stoi(x.substr(0, x.find(" ")));
			if (root->key == root_num)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (x.find("siblings") != -1) {
			x.erase(x.find(" are"));
			int a = stoi(x.substr(0, x.find(" ")));
			x.erase(0, x.find("and"));
			int b = stoi(x.substr(x.find(" "), x.size()));
			find(path_a, tmp_a, a, root);
			find(path_b, tmp_b, b, root);
			if (path_a.size() == path_b.size() && path_a.size() >= 2 && path_a[path_a.size() - 2] == path_b[path_b.size() - 2])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
	
		}
		else if (x.find("parent") != -1) {
			int a = stoi(x.substr(0, x.find(" ")));
			x.erase(0, x.find("of"));
			int b = stoi(x.substr(x.find(" "), x.size()));
			find(path_a, tmp_a, a, root);
			find(path_b, tmp_b, b, root);
			if (path_a.size() == path_b.size() - 1 && a == path_b[path_b.size() - 2])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (x.find("left") != -1) {
			int a = stoi(x.substr(0, x.find(" ")));
			x.erase(0, x.find("of"));
			int b = stoi(x.substr(x.find(" "), x.size()));
			bool flg = false;
			judge_left(b, a, root, flg);
			if (flg)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (x.find("right") != -1) {
			int a = stoi(x.substr(0, x.find(" ")));
			x.erase(0, x.find("of"));
			int b = stoi(x.substr(x.find(" "), x.size()));
			bool flg = false;
			judge_right(b, a, root, flg);
			if (flg)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if (x.find("level") != -1) {
			x.erase(x.find(" are"));
			int a = stoi(x.substr(0, x.find(" ")));
			x.erase(0, x.find("and"));
			int b = stoi(x.substr(x.find(" "), x.size()));
			find(path_a, tmp_a, a, root);
			find(path_b, tmp_b, b, root);
			if (path_a.size() == path_b.size())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else {
			if (check_full(root))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}