#include <iostream>
#include <cmath>

using namespace std;

#define MAX 10000

struct stu {
	int rank;
	bool checked;
	bool appear;
	stu() :checked(false), appear(false) {}
}stu[MAX];

bool is_prime(int x) {
	if (x <= 1)
		return false;
	int sqr = (int)sqrt(x);
	for (int i = 2; i <= sqr; i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}

void print(int id) {
	if (stu[id].appear == false)
		printf("%04d: Are you kidding?\n", id);
	else if (stu[id].checked)
		printf("%04d: Checked\n", id);
	else {
		stu[id].checked = true;
		if (stu[id].rank == 1)
			printf("%04d: Mystery Award\n", id);
		else if (is_prime(stu[id].rank))
			printf("%04d: Minion\n", id);
		else
			printf("%04d: Chocolate\n", id);
	}
}

int main() {
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int id;
		cin >> id;
		stu[id].rank = i + 1;
		stu[id].appear = true;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int id;
		cin >> id;
		print(id);
	}
	return 0;
}