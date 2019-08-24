#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 500
#define INF 0x3fffffff

int length[MAX][MAX], time_[MAX][MAX];
bool visited[MAX];
int dis_len[MAX], dis_time[MAX];
vector<int> pre_len[MAX], pre_time[MAX];
vector<int> tmp_len, tmp_time, re_len, re_time;

void dijkstra_time(int begin, int n) {
	fill(dis_time, dis_time + MAX, INF);
	fill(visited, visited + MAX, false);
	dis_time[begin] = 0;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_value = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dis_time[j] < min_value) {
				min_value = dis_time[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			break;
		visited[min_index] = true;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false) {
				if (dis_time[min_index] + time_[min_index][j] < dis_time[j]) {
					dis_time[j] = dis_time[min_index] + time_[min_index][j];
					pre_time[j].clear();
					pre_time[j].push_back(min_index);
				}
				else if (dis_time[min_index] + time_[min_index][j] == dis_time[j]) {
					pre_time[j].push_back(min_index);
				}
			}
		}
	}
}

void dfs_time(int index, int begin, int& min_size) {
	tmp_time.push_back(index);
	if (index == begin) {
		if (tmp_time.size() < min_size) {
			re_time = tmp_time;
			min_size = re_time.size();
		}
	}
	else {
		for (int i = 0; i < pre_time[index].size(); i++)
			dfs_time(pre_time[index][i], begin, min_size);
	}
	tmp_time.pop_back();
}

void dijkstra_len(int begin, int n) {
	fill(visited, visited + MAX, false);
	fill(dis_len, dis_len + MAX, INF);
	dis_len[begin] = 0;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_value = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dis_len[j] < min_value) {
				min_value = dis_len[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			break;
		visited[min_index] = true;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false) {
				if (dis_len[min_index] + length[min_index][j] < dis_len[j]) {
					dis_len[j] = dis_len[min_index] + length[min_index][j];
					pre_len[j].clear();
					pre_len[j].push_back(min_index);
				}
				else if (dis_len[min_index] + length[min_index][j] == dis_len[j]) {
					pre_len[j].push_back(min_index);
				}
			}
			
		}
	}
}

void dfs_len(int index, int begin, int &min_time) {
	tmp_len.push_back(index);
	if (index == begin) {
		int this_time = 0;
		for (int i = tmp_len.size() - 1; i > 0; i--) {
			this_time += time_[tmp_len[i]][tmp_len[i - 1]];
		}
		if (this_time < min_time) {
			min_time = this_time;
			re_len = tmp_len;
		}
	}
	else {
		for (int i = 0; i < pre_len[index].size(); i++) {
			dfs_len(pre_len[index][i], begin, min_time);
		}
	}
	tmp_len.pop_back();
}

void print(int end) {
	if (re_len == re_time) {
		// Distance = 3; Time = 4: 3 -> 2 -> 5
		printf("Distance = %d; Time = %d: ", dis_len[end], dis_time[end]);
		for (int i = re_len.size() - 1; i >= 0; i--) {
			if (i == 0)
				cout << re_len[i] << endl;
			else
				cout << re_len[i] << " -> ";
		}
	}
	else {
		// Distance = 6: 3 -> 4 -> 8 -> 5
		// Time = 3: 3 -> 1 -> 5
		printf("Distance = %d: ", dis_len[end]);
		for (int i = re_len.size() - 1; i >= 0; i--) {
			if (i == 0)
				cout << re_len[i] << endl;
			else
				cout  << re_len[i] << " -> ";
		}
		printf("Time = %d: ", dis_time[end]);
		for (int i = re_time.size() - 1; i >= 0; i--) {
			if (i == 0)
				cout << re_time[i] << endl;
			else
				cout  << re_time[i] << " -> ";
		}
	}
}

int main() {
	fill(length[0], length[0] + MAX * MAX, INF);
	fill(time_[0], time_[0] + MAX * MAX, INF);
	int n, m, begin, end;
	int min_time = INF, min_size = INF;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, way, l, t;
		cin >> v1 >> v2 >> way >> l >> t;
		length[v1][v2] = l;
		time_[v1][v2] = t;
		if (way == 0) {
			length[v2][v1] = l;
			time_[v2][v1] = t;
		}
	}
	cin >> begin >> end;
	dijkstra_len(begin, n);
	dfs_len(end, begin, min_time);
	dijkstra_time(begin, n);
	dfs_time(end, begin, min_size);
	print(end);
	return 0;
}