#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	string id;
	string in, out;
};
vector<person> persons;

bool cmp_in(struct person a, struct person b) {
	return a.in < b.in;
}
bool cmp_out(struct person a, struct person b) {
	return a.out > b.out;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		struct person p;
		cin >> p.id >> p.in >> p.out;
		persons.push_back(p);
	}
	sort(persons.begin(), persons.end(), cmp_in);
	cout << persons[0].id << " ";
	sort(persons.begin(), persons.end(), cmp_out);
	cout << persons[0].id << endl;
	return 0;
}

/*
本题也可以将时间转换成总秒数
		int h1, m1, s1, h2, m2, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		int tempIn = h1 * 3600 + m1 * 60 + s1;
		int tempOut = h2 * 3600 + m2 * 60 + s2;
*/