#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	map<string, set<int> > name_to_course;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int course_id, num;
		cin >> course_id >> num;
		for (int j = 0; j < num; j++) {
			string c;
			cin >> c;
			name_to_course[c].insert(course_id);
		}
	}
	for (int i = 0; i < n; i++) {
		string q;
		cin >> q;
		printf("%s %d", q.c_str(), name_to_course[q].size());
		for (auto it = name_to_course[q].begin(); it != name_to_course[q].end(); it++)
			printf(" %d", *it);
		cout << endl;
	}
	return 0;
}