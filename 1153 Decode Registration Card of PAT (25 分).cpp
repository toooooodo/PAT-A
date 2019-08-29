#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct testee {
	int score;
	string id;
	testee() {}
	testee(string id, int score) :id(id), score(score) {}
};
struct site {
	int n;
	int total_score;
	site() :n(0), total_score(0) {}
}sites[1000];
struct date_site {
	int id;
	int total;
	date_site() :total(0) {}
	date_site(int id, int total) :id(id), total(total) {}
};
struct date {
	vector<date_site> site;
}dates[100000];
vector<testee> a, b, t;
unordered_map<int, int> date_to_idx;

bool cmp_1(testee a, testee b) {
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}

bool cmp_2(date_site a, date_site b) {
	if (a.total != b.total)
		return a.total > b.total;
	else
		return a.id < b.id;
}

void insert_date(int s, int date_idx) {
	int idx = 0;
	while (idx < dates[date_idx].site.size()) {
		if (dates[date_idx].site[idx].id != s)
			idx++;
		else {
			dates[date_idx].site[idx].total++;
			return;
		}
	}
	dates[date_idx].site.push_back(date_site(s, 1));
}

void to_sort() {
	sort(a.begin(), a.end(), cmp_1);
	sort(b.begin(), b.end(), cmp_1);
	sort(t.begin(), t.end(), cmp_1);
	for (auto it = date_to_idx.begin(); it != date_to_idx.end(); it++) {
		sort(dates[it->second].site.begin(), dates[it->second].site.end(), cmp_2);
	}
}

void print(vector<testee> &a) {
	if (a.size() == 0) {
		cout << "NA" << endl;
		return;
	}
	for (int i = 0; i < a.size(); i++)
		cout << a[i].id << " " << a[i].score << endl;
}

int main() {
	int n, m, date_cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string id;
		int score, _date, _site, date_idx;
		cin >> id >> score;
		if (id[0] == 'A')
			a.push_back(testee(id, score));
		else if (id[0] == 'B')
			b.push_back(testee(id, score));
		else
			t.push_back(testee(id, score));
		_site = stoi(id.substr(1, 3));
		_date = stoi(id.substr(4, 6));
		sites[_site].n++;
		sites[_site].total_score += score;
		if (date_to_idx.find(_date) == date_to_idx.end()) {
			date_idx = date_cnt;
			date_to_idx[_date] = date_cnt++;
		}
		else {
			date_idx = date_to_idx[_date];
		}
		insert_date(_site, date_idx);
	}
	to_sort();
	for (int i = 0; i < m; i++) {
		int number;
		cin >> number;
		if (number == 1) {
			char ch;
			cin >> ch;
			printf("Case %d: 1 %c\n", i + 1, ch);
			if (ch == 'A')
				print(a);
			else if (ch == 'B')
				print(b);
			else
				print(t);
		}
		else if (number == 2) {
			int _site;
			cin >> _site;
			printf("Case %d: 2 %03d\n", i + 1, _site);
			if (sites[_site].n == 0)
				cout << "NA" << endl;
			else {
				cout << sites[_site].n << " " << sites[_site].total_score << endl;
			}
		}
		else {
			int _date;
			cin >> _date;
			printf("Case %d: 3 %06d\n", i + 1, _date);
			if (date_to_idx.find(_date) == date_to_idx.end())
				cout << "NA" << endl;
			else {
				int idx = date_to_idx[_date];
				for (int i = 0; i < dates[idx].site.size(); i++) {
					//cout << dates[idx].site[i].id << " " << dates[idx].site[i].total << endl;
					printf("%03d %d\n", dates[idx].site[i].id, dates[idx].site[i].total);
				}
			}
		}
	}
}