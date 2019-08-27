#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#define MAX 30000

struct student {
	string id;
	int g_p, g_mid, g_final;
	double g;
	student() :g_mid(-1), g_p(-1), g_final(-1) {}
}students[MAX], real_stu[MAX];
map<string, int> id_to_idx;

bool cmp(student a, student b) {
	if ((int)a.g != (int)b.g)
		return a.g > b.g;
	else
		return a.id < b.id;
}

int main() {
	int p, m, n, count = 0, real_cnt = 0, grade;
	string id;
	cin >> p >> m >> n;
	for (int i = 0; i < p; i++) {
		cin >> id >> grade;
		if (id_to_idx.find(id) == id_to_idx.end()) {
			students[count].id = id;
			id_to_idx[id] = count++;
		}
		students[id_to_idx[id]].g_p = grade;
	}
	for (int i = 0; i < m; i++) {
		cin >> id >> grade;
		if (id_to_idx.find(id) == id_to_idx.end()) {
			students[count].id = id;
			id_to_idx[id] = count++;
		}
		students[id_to_idx[id]].g_mid = grade;
	}
	for (int i = 0; i < n; i++) {
		cin >> id >> grade;
		if (id_to_idx.find(id) == id_to_idx.end()) {
			students[count].id = id;
			id_to_idx[id] = count++;
		}
		students[id_to_idx[id]].g_final = grade;
	}
	for (int i = 0; i < count; i++) {
		if (students[i].g_final == -1 || students[i].g_p < 200)
			continue;
		if (students[i].g_mid > students[i].g_final)
			students[i].g = students[i].g_mid*0.4 + students[i].g_final*0.6 + 0.5;
		else
			students[i].g = students[i].g_final;
		if (students[i].g < 60)
			continue;
		real_stu[real_cnt++] = students[i];
	}
	sort(real_stu, real_stu + real_cnt, cmp);
	for (int i = 0; i < real_cnt; i++) {
		printf("%s %d %d %d %d\n", real_stu[i].id.c_str(), real_stu[i].g_p, real_stu[i].g_mid, real_stu[i].g_final, (int)real_stu[i].g);
	}
	return 0;
}