#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 10000

struct people {
	string name;
	int height;
}lst[MAX];
int matrix[MAX][MAX];

bool cmp(people a, people b) {
	if (a.height != b.height)
		return a.height > b.height;
	else
		return a.name < b.name;
}

int main() {
	int n, k, m1, m2, pointer = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> lst[i].name >> lst[i].height;
	}
	sort(lst, lst + n, cmp);
	m2 = n / k;
	m1 = n - (k - 1)*m2;
	for (int i = 0; i < k; i++) {
		if (i == 0) {
			int mid = m1 / 2;
			int count = 1;
			matrix[i][mid] = pointer++;
			for (int step = 1; count < m1; step++) {
				matrix[i][mid - step] = pointer++;
				count++;
				if (count == m1)
					break;
				matrix[i][mid + step] = pointer++;
				count++;
			}
			for (int j = 0; j < m1; j++) {
				if (j == 0)
					cout << lst[matrix[i][j]].name;
				else
					cout << " " << lst[matrix[i][j]].name;
			}
			cout << endl;
		}
		else {
			int mid = m2 / 2;
			int count = 1;
			matrix[i][mid] = pointer++;
			for (int step = 1; count < m2; step++) {
				matrix[i][mid - step] = pointer++;
				count++;
				if (count == m2)
					break;
				matrix[i][mid + step] = pointer++;
				count++;
			}
			for (int j = 0; j < m2; j++) {
				if (j == 0)
					cout << lst[matrix[i][j]].name;
				else
					cout << " " << lst[matrix[i][j]].name;
			}
			cout << endl;
		}
	}
	return 0;
}