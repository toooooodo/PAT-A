#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

#define MAX 10000

map<string, set<string> > title_map, author_map, key_map, publisher_map, year_map;

void search(map<string, set<string> > &m, string &q) {
	if (m[q].size() == 0)
		cout << "Not Found" << endl;
	else {
		for (auto it = m[q].begin(); it != m[q].end(); it++)
			cout << *it << endl;
	}
}

int main() {
	int n, m;
	string id, title, author, publisher, year;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, id);
		getline(cin, title);
		getline(cin, author);
		string _key;
		while (cin >> _key) {
			key_map[_key].insert(id);
			char c = getchar();
			if (c == '\n')
				break;
		}
		getline(cin, publisher);
		getline(cin, year);
		title_map[title].insert(id);
		author_map[author].insert(id);
		publisher_map[publisher].insert(id);
		year_map[year].insert(id);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int id;
		string query;
		scanf("%d: ", &id);
		getline(cin, query);
		printf("%d: %s\n", id, query.c_str());
		if (id == 1)
			search(title_map, query);
		else if (id == 2)
			search(author_map, query);
		else if (id == 3)
			search(key_map, query);
		else if (id == 4)
			search(publisher_map, query);
		else
			search(year_map, query);
	}
	return 0;
}