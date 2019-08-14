#include <iostream>
#include <stack>

using namespace std;

#define MAXN 1000

int main() {
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int MAX = 0;
		bool flag = true;
		int seq[MAXN];
		stack<int> st;
		for (int j = 0; j < n; j++) {
			cin >> seq[j];
		}
		for (int j = 0; j < n; j++) {
			if (seq[j] > MAX) {
				for (int a = MAX + 1; a <= seq[j]; a++)
					st.push(a);
				if (st.size() > m) {
					flag = false;
					break;
				}
				else {
					st.pop();
					MAX = seq[j];
				}

			}
			else {
				if (seq[j] != st.top()) {
					flag = false;
					break;
				}
				else
					st.pop();

			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}