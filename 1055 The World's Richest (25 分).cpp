#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 100000

struct people {
	char name[10];
	int age;
	int worth;
}lst[MAX], valid[MAX];
int age[201] = { 0 };

bool cmp(people a, people b) {
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name, b.name) < 0;
}

int main() {
	int n, k, valid_n = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", lst[i].name, &lst[i].age, &lst[i].worth);
	}
	sort(lst, lst + n, cmp);
	for (int i = 0; i < n; i++) {
		if (age[lst[i].age] < 100) {
			age[lst[i].age]++;
			valid[valid_n++] = lst[i];
		}
	}
	for (int i = 0; i < k; i++) {
		int max_num, amin, amax, print_num = 0;
		scanf("%d %d %d", &max_num, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		for (int j = 0; j < valid_n; j++) {
			if (valid[j].age >= amin && valid[j].age <= amax) {
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				print_num++;
			}
			if (print_num == max_num)
				break;
		}
		if (print_num == 0)
			printf("None\n");
	}
	return 0;
}