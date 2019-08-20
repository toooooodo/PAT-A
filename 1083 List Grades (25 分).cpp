#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

#define MAX 110

struct stu {
	string id, name;
	int grade;
}students[MAX];

bool cmp(stu a, stu b) {
	return a.grade > b.grade;
}

int main() {
	int n, grade1, grade2;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> students[i].name >> students[i].id >> students[i].grade;
	sort(students, students + n, cmp);
	cin >> grade1 >> grade2;
	bool flg = false;
	for (int i = 0; i < n; i++) {
		if (students[i].grade >= grade1 && students[i].grade <= grade2) {
			flg = true;
			cout << students[i].name << " " << students[i].id << endl;
		}
	}
	if (!flg)
		cout << "NONE" << endl;
	return 0;
}