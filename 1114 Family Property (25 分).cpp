#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 1000
#define MAXD 10000

struct person {
	int id;
	int father, mother;
	int k;
	vector<int> child;
	double estate, area;
	person() :estate(0), area(0) {}
}persons[MAXD];
set<int> appear;
int father[MAXD];
struct family {
	int root, m;
	double sum_est, sum_area;
	double avg_est, avg_area;
	family() {}
	family(int root, int est, int area) :sum_est(est), sum_area(area), root(root), m(1) {}
};
vector<family> families;

bool cmp(family a, family b) {
	if (a.avg_area != b.avg_area)
		return a.avg_area > b.avg_area;
	else
		return a.root < b.root;
}

int find_father(int x) {
	if (father[x] == x) {
		return x;
	}
	else {
		int f = find_father(father[x]);
		father[x] = f;
		return f;
	}
}

void _union(int a, int b) {
	int a_f = find_father(a);
	int b_f = find_father(b);
	if (a_f != b_f) {
		if (a_f < b_f) {
			father[b_f] = a_f;
		}
		else {
			father[a_f] = b_f;
		}
	}
}

int main() {
	int n;
	cin >> n;
	//fill(root, root + MAXD, 0);
	for (int i = 0; i < MAXD; i++) {
		father[i] = i;
	}
	for (int idx = 0; idx < n; idx++) {
		int i;
		cin >> i;
		persons[i].id = i;
		cin >> persons[i].father >> persons[i].mother >> persons[i].k;
		for (int j = 0; j < persons[i].k; j++) {
			int chi;
			cin >> chi;
			persons[i].child.push_back(chi);
			_union(persons[i].id, chi);
			appear.insert(chi);
		}
		cin >> persons[i].estate >> persons[i].area;
		appear.insert(persons[i].id);
		if (persons[i].father != -1) {
			appear.insert(persons[i].father);
			_union(persons[i].id, persons[i].father);
		}
		if (persons[i].mother != -1) {
			appear.insert(persons[i].mother);
			_union(persons[i].id, persons[i].mother);
		}
	}
	for (auto it = appear.begin(); it != appear.end(); it++) {
		int root = find_father(*it);
		int f_index = 0;
		while (f_index < families.size()) {
			if (families[f_index].root == root) {
				break;
			}
			f_index++;
		}
		if (f_index == families.size()) {
			families.push_back(family(root,persons[*it].estate,persons[*it].area));
		}
		else {
			families[f_index].m++;
			families[f_index].sum_est += persons[*it].estate;
			families[f_index].sum_area += persons[*it].area;
		}
	}
	for (int i = 0; i < families.size(); i++) {
		families[i].avg_area = families[i].sum_area / families[i].m;
		families[i].avg_est = families[i].sum_est / families[i].m;
	}
	sort(families.begin(), families.end(), cmp);
	cout << families.size() << endl;
	for (int i = 0; i < families.size(); i++) {
		printf("%04d %d %.3f %.3f\n", families[i].root, families[i].m, families[i].avg_est, families[i].avg_area);
	}
	return 0;
}