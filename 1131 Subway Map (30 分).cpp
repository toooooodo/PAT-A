#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000

vector<int> tmp, final_path;
vector<int> subway[MAX];
bool visited[MAX];
int line[MAX][MAX];

int get_transf() {
	int pre = tmp[0];
	int this_line = line[tmp[0]][tmp[1]];
	int count = 0;
	for (int i = 1; i < tmp.size(); i++) {
		int next = tmp[i];
		if (line[pre][next] != this_line) {
			count++;
			this_line = line[pre][next];
		}
		pre = next;
	}
	return count;
}

void print_line() {
	int pre = final_path[final_path.size() - 1];
	int begin = pre, next;
	int this_line = line[final_path[final_path.size() - 1]][final_path[final_path.size() - 2]];
	for (int i = final_path.size() - 2; i >= 0; i--) {
		int next = final_path[i];
		if (line[pre][next] != this_line) {
			//Take Line#3 from 3011 to 3013.
			printf("Take Line#%d from %04d to %04d.\n", this_line, begin, pre);
			this_line = line[pre][next];
			begin = pre;
		}
		pre = next;
	}
	printf("Take Line#%d from %04d to %04d.\n", this_line, begin, pre);
}

void dfs(int begin, int index, int stations, int &min_station, int &min_transf) {
	tmp.push_back(index);
	visited[index] = true;
	if (begin == index) {
		int transf = get_transf();
		if (stations < min_station) {
			min_station = stations;
			min_transf = transf;
			final_path = tmp;
		}
		else if (stations == min_station && transf < min_transf) {
			min_transf = transf;
			final_path = tmp;
		}
	}
	else {
		for (int i = 0; i < subway[index].size(); i++) {
			if (visited[subway[index][i]] == false) {
				dfs(begin, subway[index][i], stations + 1, min_station, min_transf);
			}
		}
	}

	tmp.pop_back();
	visited[index] = false;
}

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k, pre, next;
		cin >> k >> pre;
		for (int j = 1; j < k; j++) {
			cin >> next;
			subway[pre].push_back(next);
			subway[next].push_back(pre);
			line[pre][next] = line[next][pre] = i;
			pre = next;
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int begin, end, station = MAX, transf = MAX;
		cin >> begin >> end;
		fill(visited, visited + MAX, false);
		dfs(begin, end, 0, station, transf);
		cout << station << endl;
		print_line();
		final_path.clear();
	}
	return 0;
}