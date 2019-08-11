#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct student {
	string name, id;
	char gender;
	int grade;
};
vector<student> students;

int main() {
	int n, male_index = -1, female_index = -1;
	int min_grade = 101, max_grade = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		student stu;
		cin >> stu.name >> stu.gender >> stu.id >> stu.grade;
		students.push_back(stu);
		if (stu.gender == 'M' && stu.grade < min_grade) {
			min_grade = stu.grade;
			male_index = i;
		}
		else if (stu.gender == 'F' && stu.grade > max_grade) {
			max_grade = stu.grade;
			female_index = i;
		}
	}
	if (female_index == -1)
		cout << "Absent" << endl;
	else
		cout << students[female_index].name << " " << students[female_index].id << endl;
	if (male_index == -1)
		cout << "Absent" << endl;
	else
		cout << students[male_index].name << " " << students[male_index].id << endl;
	if (male_index == -1 || female_index == -1)
		cout << "NA" << endl;
	else
		cout << max_grade - min_grade << endl;
	return 0;
}