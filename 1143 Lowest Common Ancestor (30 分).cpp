#include <iostream>
#include <unordered_set>

using namespace std;

#define MAX 10000

int numbers[MAX];
unordered_set<int>st;

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		st.insert(numbers[i]);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		auto a_ = st.find(a);
		auto b_ = st.find(b);
		if (a_ == st.end() && b_ == st.end())
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if (a_ == st.end())
			printf("ERROR: %d is not found.\n", a);
		else if (b_ == st.end())
			printf("ERROR: %d is not found.\n", b);
		else {
			int root;
			for (int j = 0; j < n; j++) {
				root = numbers[j];
				if (root >= a && root <= b || root >= b && root <= a)
					break;
			}
			if (root == a)
				printf("%d is an ancestor of %d.\n", a, b);
			else if (root == b)
				printf("%d is an ancestor of %d.\n", b, a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, root);
		}
	}
	return 0;
}