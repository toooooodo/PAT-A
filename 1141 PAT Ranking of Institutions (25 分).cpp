#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100000

struct school {
	int rank, ns;
	string name;
	double tws;
	school() :tws(0) {}
}schools[MAX];
map<string, int> name_to_idx;

bool cmp(school a, school b) {
	if ((int)a.tws != (int)b.tws)
		return a.tws > b.tws;
	else if (a.ns != b.ns)
		return a.ns < b.ns;
	else
		return a.name < b.name;
}

int main() {
	int n, school_count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string id, name;
		int score, index;
		cin >> id >> score >> name;
		for (int j = 0; j < name.size(); j++)
			name[j] = tolower(name[j]);
		if (name_to_idx.find(name) == name_to_idx.end()) {
			schools[school_count].name = name;
			index = school_count;
			name_to_idx[name] = school_count++;
		}
		else {
			index = name_to_idx[name];
		}
		schools[index].ns++;
		if (id[0] == 'B')
			schools[index].tws += score / 1.5;
		else if (id[0] == 'A')
			schools[index].tws += score;
		else
			schools[index].tws += score * 1.5;
	}
	sort(schools, schools + school_count, cmp);
	for (int i = 0; i < school_count; i++) {
		if (i == 0)
			schools[i].rank = 1;
		else {
			if ((int)schools[i].tws == (int)schools[i - 1].tws)
				schools[i].rank = schools[i - 1].rank;
			else
				schools[i].rank = i + 1;
		}
	}
	printf("%d\n", school_count);
	for (int i = 0; i < school_count; i++) {
		printf("%d %s %d %d\n", schools[i].rank, schools[i].name.c_str(), (int)schools[i].tws, schools[i].ns);
	}
	return 0;
}