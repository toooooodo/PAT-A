#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXK 101
#define INF 0X3FFFFFFF

struct player {
	int arrive_time, start_time, train_time;
	bool vip;
};
struct table {
	int end_time, num;
	bool vip;
}tables[MAXK];
vector<player> players;

int cmp_arrive_time(player a, player b) {
	return a.arrive_time < b.arrive_time;
}

int cmp_start_time(player a, player b) {
	return a.start_time < b.start_time;
}

int next_vip(int vip_idx) {
	vip_idx++;
	while (vip_idx < players.size() && players[vip_idx].vip == false)
		vip_idx++;
	return vip_idx;
}

void allot_table(int p_id, int t_id) {
	if (players[p_id].arrive_time <= tables[t_id].end_time)
		players[p_id].start_time = tables[t_id].end_time;
	else
		players[p_id].start_time = players[p_id].arrive_time;
	tables[t_id].end_time = players[p_id].start_time + players[p_id].train_time;
	tables[t_id].num++;
}

int main() {
	int n, k, m, vip_table;
	cin >> n;
	int start_time = 8 * 60 * 60;
	int end_time = 21 * 60 * 60;
	for (int i = 0; i < n; i++) {
		int h, m, s, train_time, vip;
		struct player new_player;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &train_time, &vip);
		new_player.arrive_time = h * 60 * 60 + m * 60 + s;
		if (new_player.arrive_time >= end_time)
			continue;
		new_player.start_time = end_time;
		new_player.train_time = train_time <= 120 ? train_time * 60 : 7200;
		new_player.vip = vip;
		players.push_back(new_player);
	}
	cin >> k >> m;
	for (int i = 1; i <= k; i++) {
		tables[i].end_time = start_time;
		tables[i].vip = false;
		tables[i].num = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> vip_table;
		tables[vip_table].vip = true;
	}
	sort(players.begin(), players.end(), cmp_arrive_time);
	int index = 0, vip_index = -1;
	vip_index = next_vip(vip_index);
	while (index < players.size()) {
		int table_index = -1, min_end_time = INF;
		for (int i = 1; i <= k; i++) {
			if (tables[i].end_time < min_end_time) {
				min_end_time = tables[i].end_time;
				table_index = i;
			}
		}
		if (min_end_time >= end_time)
			break;
		if (players[index].vip == true && index < vip_index) {
			index++;
			continue;
		}
		if (tables[table_index].vip == true) {
			if (players[index].vip == true) {   //vip table, vip player
				allot_table(index, table_index);
				if (vip_index == index)
					vip_index = next_vip(vip_index);
				index++;
			}
			else {                 //vip table, not vip player
				if (vip_index < players.size() && players[vip_index].arrive_time <= tables[table_index].end_time) {
					allot_table(vip_index, table_index);
					vip_index = next_vip(vip_index);
				}
				else {
					allot_table(index, table_index);
					index++;
				}
			}
		}
		else {
			if (players[index].vip == false) { //not vip table, not vip player
				allot_table(index, table_index);
				index++;
			}
			else { // not vip table, vip player
				int vip_table_index = -1, min_vip_table_endtime = INF;
				for (int i = 1; i <= k; i++) {
					if (tables[i].vip == true && tables[i].end_time < min_vip_table_endtime) {
						min_vip_table_endtime = tables[i].end_time;
						vip_table_index = i;
					}
				}
				if (vip_table_index != -1 && players[index].arrive_time >= tables[vip_table_index].end_time) {
					allot_table(index, vip_table_index);
					if (vip_index == index)
						vip_index = next_vip(vip_index);
					index++;
				}
				else {
					allot_table(index, table_index);
					if (vip_index == index)
						vip_index = next_vip(vip_index);
					index++;
				}
			}
		}
	}
	sort(players.begin(), players.end(), cmp_start_time);
	for (int i = 0; i < players.size() && players[i].start_time < end_time; i++) {
		int t1 = players[i].arrive_time;
		int t2 = players[i].start_time;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		cout << (int)((t2 - t1) / 60.0 + 0.5) << endl;
	}
	for (int i = 1; i <= k; i++) {
		if (i == 1)
			cout << tables[i].num;
		else
			cout << " " << tables[i].num;
	}
	return 0;
}