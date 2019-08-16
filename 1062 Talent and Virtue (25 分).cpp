#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct people {
	string id;
	int talent;
	int virtue;
};

vector<people> groups[4];

bool cmp(people a, people b) {
	if (a.talent + a.virtue != b.talent + b.virtue)
		return a.talent + a.virtue > b.talent + b.virtue;
	if (a.virtue != b.virtue)
		return a.virtue > b.virtue;
	return a.id < b.id;
}

int main() {
	int n, l, h, count = 0;
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		people p;
		cin >> p.id >> p.virtue >> p.talent;
		if (p.talent < l || p.virtue < l)
			continue;
		count++;
		if (p.talent >= h && p.virtue >= h) {
			groups[0].push_back(p);
		}
		else if (p.talent < h&&p.virtue >= h) {
			groups[1].push_back(p);
		}
		else if (p.talent < h&&p.virtue < h&&p.talent <= p.virtue) {
			groups[2].push_back(p);
		}
		else {
			groups[3].push_back(p);
		}
	}
	for (int i = 0; i < 4; i++)
		sort(groups[i].begin(), groups[i].end(), cmp);
	cout << count << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < groups[i].size(); j++) {
			cout << groups[i][j].id << " " << groups[i][j].virtue << " " << groups[i][j].talent << endl;
		}
	}
	return 0;
}