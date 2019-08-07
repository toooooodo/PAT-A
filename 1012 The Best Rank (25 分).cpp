#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 2000

struct student {
	int id;
	int c, m, e, a;
	student() {};
	student(int _id, int _a, int _c, int _m, int _e) :id(_id), a(_a), c(_c), m(_m), e(_e) {}
};
struct student students[MAX];
map<int, int> rank_a, rank_c, rank_m, rank_e;

bool cmp_a(student a, student b) {
	return a.a > b.a;
}

bool cmp_c(student a, student b) {
	return a.c > b.c;
}

bool cmp_m(student a, student b) {
	return a.m > b.m;
}

bool cmp_e(student a, student b) {
	return a.e > b.e;
}

void check(int id, string &course, int &rank) {
	if (rank_a.find(id) == rank_a.end()) {
		course = "N/A";
		rank = -1;
		return;
	}
	rank = MAX + 1;
	if (rank_a[id] < rank) {
		rank = rank_a[id];
		course = "A";
	}
	if (rank_c[id] < rank) {
		rank = rank_c[id];
		course = "C";
	}
	if (rank_m[id] < rank) {
		rank = rank_m[id];
		course = "M";
	}
	if (rank_e[id] < rank) {
		rank = rank_e[id];
		course = "E";
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int id;
		int _a, _c, _m, _e;
		cin >> id >> _c >> _m >> _e;
		_a = (int)((_c + _m + _e) / 3 + 0.5);
		students[i] = student(id, _a, _c, _m, _e);
	}
	sort(students, students + n, cmp_a);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rank_a[students[i].id] = 1;
		}
		else {
			if (students[i].a == students[i - 1].a) {
				rank_a[students[i].id] = rank_a[students[i - 1].id];
			}
			else {
				rank_a[students[i].id] = i + 1;
			}
		}
	}
	sort(students, students + n, cmp_c);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rank_c[students[i].id] = 1;
		}
		else {
			if (students[i].c == students[i - 1].c) {
				rank_c[students[i].id] = rank_c[students[i - 1].id];
			}
			else {
				rank_c[students[i].id] = i + 1;
			}
		}
	}
	sort(students, students + n, cmp_m);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rank_m[students[i].id] = 1;
		}
		else {
			if (students[i].m == students[i - 1].m) {
				rank_m[students[i].id] = rank_m[students[i - 1].id];
			}
			else {
				rank_m[students[i].id] = i + 1;
			}
		}
	}
	sort(students, students + n, cmp_e);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			rank_e[students[i].id] = 1;
		}
		else {
			if (students[i].e == students[i - 1].e) {
				rank_e[students[i].id] = rank_e[students[i - 1].id];
			}
			else {
				rank_e[students[i].id] = i + 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		string course;
		int rank, query;
		cin >> query;
		check(query, course, rank);
		if (rank == -1)
			cout << course << endl;
		else
			cout << rank << " " << course << endl;
	}
	return 0;
}