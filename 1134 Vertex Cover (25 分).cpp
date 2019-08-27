#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct edge {
	int v, u;
	edge(int v, int u) :v(v), u(u) {}
};
vector<edge> edges;

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		edges.push_back(edge(v1, v2));
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		bool flg = true;
		set<int> vertex;
		int num, v;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> v;
			vertex.insert(v);
		}
		for (auto it = edges.begin(); it != edges.end(); it++) {
			auto it1 = vertex.find((*it).u);
			auto it2 = vertex.find((*it).v);
			if (it1 == vertex.end() && it2 == vertex.end()) {
				flg = false;
				break;
			}
		}
		if (flg)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}