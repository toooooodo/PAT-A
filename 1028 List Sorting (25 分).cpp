#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100000

struct student {
	string id, name;
	int score;
}students[MAX];

bool cmp1(student a, student b) {
	return a.id < b.id;
}

bool cmp2(student a, student b) {
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}

bool cmp3(student a, student b) {
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
}

int main() {
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> students[i].id >> students[i].name >> students[i].score;
	}
	if (c == 1)
		sort(students, students + n, cmp1);
	else if (c == 2)
		sort(students, students + n, cmp2);
	else
		sort(students, students + n, cmp3);
	for (int i = 0; i < n; i++)
		cout << students[i].id << " " << students[i].name << " " << students[i].score << endl;
	return 0;
}