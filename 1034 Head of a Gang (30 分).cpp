#include <iostream>
#include <string>
#include <map>
using namespace std;

// no more than 1000 phone call -> no more than 2000 persons
#define MAX 2000
//#define INF 0X3FFFFFFF

map<string, int> name_to_id;
map<int, string> id_to_name;
map<string, int> gang;
int graph[MAX][MAX] = { 0 }, weight[MAX] = { 0 };
int total_p = 0;
bool visited[MAX] = { false };

int get_id(string name) {
	if (name_to_id.find(name) == name_to_id.end()) {
		name_to_id[name] = total_p;
		id_to_name[total_p] = name;
		return total_p++;
	}
	return name_to_id[name];
}

void dfs(int index, int &head, int &total_weight, int &p_num) {
	visited[index] = true;
	p_num++;
	if (weight[index] > weight[head]) {
		head = index;
	}
	for (int i = 0; i < total_p; i++) {
		if (graph[i][index] != 0) {
			total_weight += graph[i][index];
			graph[i][index] = graph[index][i] = 0;
			if (visited[i] == false)
				dfs(i, head, total_weight, p_num);
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string name1, name2;
		int time, id1, id2;
		cin >> name1 >> name2 >> time;
		id1 = get_id(name1);
		id2 = get_id(name2);
		graph[id1][id2] += time;
		graph[id2][id1] += time;
		weight[id1] += time;
		weight[id2] += time;
	}
	for (int i = 0; i < total_p; i++) {
		if (visited[i] == false) {
			int head = i, total_weight = 0, p_num = 0;
			dfs(i, head, total_weight, p_num);
			if (p_num > 2 && total_weight > k) {
				gang[id_to_name[head]] = p_num;
			}
		}
	}
	cout << gang.size() << endl;
	for (map<string, int>::iterator it = gang.begin(); it != gang.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}