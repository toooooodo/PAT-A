#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 101
#define MAXK 300
struct testee {
	string id;
	int score;
	int final_rank, local_rank;
	int location;
};
struct testee testees[MAX*MAXK];

bool cmp(testee a, testee b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}

int main() {
	int n, total_n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> testees[total_n].id >> testees[total_n].score;
			testees[total_n].location = i;
			total_n++;
		}
		sort(testees + total_n - k, testees + total_n, cmp);
		for (int j = total_n - k; j < total_n; j++) {
			if (j == total_n - k)
				testees[j].local_rank = 1;
			else {
				if (testees[j].score == testees[j - 1].score)
					testees[j].local_rank = testees[j - 1].local_rank;
				else
					testees[j].local_rank = j - total_n + k + 1;
			}
		}
	}
	sort(testees, testees + total_n, cmp);
	for (int i = 0; i < total_n; i++) {
		if (i == 0) {
			testees[i].final_rank = 1;
		}
		else {
			if (testees[i - 1].score == testees[i].score) {
				testees[i].final_rank = testees[i - 1].final_rank;
			}
			else {
				testees[i].final_rank = i + 1;
			}
		}
	}
	cout << total_n << endl;
	for (int i = 0; i < total_n; i++) {
		printf("%s %d %d %d\n", testees[i].id.c_str(), testees[i].final_rank, testees[i].location, testees[i].local_rank);
	}
	return 0;
}