#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define MAX 10000

using namespace std;

struct record {
	string id;
	int time;
	int status; //0->in  1->out
}records[MAX], real_records[MAX];
map<string, int> id_to_time;
vector<string> max_id;

bool cmp(record a, record b) {
	if (a.id != b.id)
		return a.id < b.id;
	else
		return a.time < b.time;
}

bool cmp2(record a, record b) {
	return a.time < b.time;
}

int main() {
	int n, k, real_count = 0;
	int max_time = -1;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string status;
		int h, m, s;
		cin >> records[i].id;
		scanf("%d:%d:%d", &h, &m, &s);
		cin >> status;
		records[i].time = h * 60 * 60 + m * 60 + s;
		records[i].status = status == "in" ? 0 : 1;
	}
	sort(records, records + n, cmp);
	for (int i = 0; i < n - 1; i++) {
		if (records[i].id == records[i + 1].id&&records[i].status == 0 && records[i + 1].status == 1) {

			real_records[real_count].id = records[i].id;
			real_records[real_count].status = 0;
			real_records[real_count++].time = records[i].time;
			real_records[real_count].id = records[i + 1].id;
			real_records[real_count].status = 1;
			real_records[real_count++].time = records[i + 1].time;

			id_to_time[records[i].id] += (records[i + 1].time - records[i].time);
			if (id_to_time[records[i].id] > max_time) {
				max_time = id_to_time[records[i].id];
				max_id.clear();
				max_id.push_back(records[i].id);
			}
			else if (id_to_time[records[i].id] == max_time) {
				max_id.push_back(records[i].id);
			}
			i++;

		}
	}
	sort(max_id.begin(), max_id.end());
	sort(real_records, real_records + real_count, cmp2);
	int j = 0, count = 0;
	for (int i = 0; i < k; i++) {
		int h, m, s, time_stamp;
		scanf("%d:%d:%d", &h, &m, &s);
		time_stamp = h * 60 * 60 + m * 60 + s;
		while (real_records[j].time <= time_stamp && j < real_count) {
			if (real_records[j].status == 0)
				count++;
			else
				count--;
			j++;
		}

		cout << count << endl;
	}
	for (int i = 0; i < max_id.size(); i++)
		cout << max_id[i] << " ";
	printf("%02d:%02d:%02d", max_time / (60 * 60), max_time % 3600 / 60, max_time % 60);
}