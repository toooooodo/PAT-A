#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MAX_SITE 1000
#define MAX_DATE 2000000

struct testee {
	string id;
	int score;
	testee(string id, int score) :id(id), score(score) {}
};
vector<testee> b, a, t;
struct site {
	int num;
	int total_score;
	site() :num(0), total_score(0) {}
}sites[MAX_SITE];
struct date_site {
	int id, num;
	date_site() :num(0) {}
	date_site(int id, int num) :id(id), num(num) {}
};
struct date {
	vector<date_site> date_sites;
}dates[MAX_DATE];
unordered_set<int> appear_dates;

bool cmp_testee(testee a, testee b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}

bool cmp_site(date_site a, date_site b) {
	if (a.num != b.num)
		return a.num > b.num;
	else
		return a.id < b.id;
}

void print_1(vector<testee> &v) {
	if (v.size() == 0)
		printf("NA\n");
	else {
		for (int i = 0; i < v.size(); i++)
			printf("%s %d\n", v[i].id.c_str(), v[i].score);
	}

}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string id;
		int score, date;
		cin >> id >> score;
		if (id[0] == 'A')
			a.push_back(testee(id, score));
		else if (id[0] == 'T')
			t.push_back(testee(id, score));
		else
			b.push_back(testee(id, score));
		int _site = stoi(id.substr(1, 3));
		sites[_site].num++;
		sites[_site].total_score += score;
		date = stoi(id.substr(4, 6));
		appear_dates.insert(date);
		bool flg = false;
		for (int j = 0; j < dates[date].date_sites.size(); j++) {
			if (dates[date].date_sites[j].id == _site) {
				dates[date].date_sites[j].num++;
				flg = true;
				break;
			}
		}
		if (flg == false) {
			dates[date].date_sites.push_back(date_site(_site, 1));
		}
	}
	sort(b.begin(), b.end(), cmp_testee);
	sort(a.begin(), a.end(), cmp_testee);
	sort(t.begin(), t.end(), cmp_testee);
	for (auto it = appear_dates.begin(); it != appear_dates.end(); it++)
		sort(dates[*it].date_sites.begin(), dates[*it].date_sites.end(), cmp_site);
	for (int i = 0; i < m; i++) {
		int index;
		cin >> index;
		if (index == 1) {
			string ch;
			cin >> ch;
			printf("Case %d: %d %s\n", i + 1, index, ch.c_str());
			if (ch == "A")
				print_1(a);
			else if (ch == "B")
				print_1(b);
			else
				print_1(t);
		}
		else if (index == 2) {
			int _site;
			cin >> _site;
			printf("Case %d: %d %d\n", i + 1, index, _site);
			if (sites[_site].num == 0)
				printf("NA\n");
			else
				printf("%d %d\n", sites[_site].num, sites[_site].total_score);
		}
		else {
			int date;
			cin >> date;
			printf("Case %d: %d %06d\n", i + 1, index, date);
			if (dates[date].date_sites.size() == 0)
				printf("NA\n");
			else {
				for (int j = 0; j < dates[date].date_sites.size(); j++)
					printf("%d %d\n", dates[date].date_sites[j].id, dates[date].date_sites[j].num);
			}
		}
	}
	return 0;
}