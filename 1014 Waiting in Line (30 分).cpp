#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001
#define MAX_WINDOW 20

struct customer {
	int start;
	int finish;
	customer() : start(-1), finish(-1) {}
}customers[MAX];
int processing_time[MAX];
queue<int> windows[MAX_WINDOW];
int n, m, k, q;

int find_shortest_queue() {
	int shortest_window = -1;
	int shortest = m;
	for (int i = 0; i < n; i++) {
		if (windows[i].size() < shortest) {
			shortest = windows[i].size();
			shortest_window = i;
		}

	}
	return shortest_window;
}

void finish(int now) {
	for (int i = 0; i < n; i++) {
		if (windows[i].empty() == false) {
			int front = windows[i].front();
			if (customers[front].finish == now) {
				//cout << "finish front" << front << " " << now << " " << customers[front].start << " " << processing_time[front] << endl;
				windows[i].pop();
			}
		}
	}
}

void start(int now) {
	for (int i = 0; i < n; i++) {
		if (windows[i].empty() == false) {
			int front = windows[i].front();
			if (customers[front].start == -1) {
				customers[front].start = now;
				customers[front].finish = now + processing_time[front];
			}
		}
	}
}

void print(int index) {
	// 开始时间在5点之后，有两种情况。
	if (customers[index].start >= 9 * 60 || customers[index].start == -1) {
		cout << "Sorry" << endl;
	}
	else {
		int finish_time = customers[index].finish;
		int hour, min;
		hour = finish_time / 60 + 8;
		min = finish_time % 60;
		printf("%02d:%02d\n", hour, min);
	}
}

bool check_still(int now) {
	for (int i = 0; i < n; i ++ ) {
		if (windows[i].empty() == false) {
			int front = windows[i].front();
			if (customers[front].start < 9 * 60) {
				return true;
			}
		}
	}
	return false;
}

int main() {

	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++) {
		cin >> processing_time[i];
	}
	int now = 0;
	int out_c = 1; //first customer out the line
	// 已经开始服务的，必须服务完
	for (int now = 0; now <= 9 * 60 || check_still(now); now++) {
		finish(now);     //customers who finish their transactions will leave
		int w = find_shortest_queue();
		while (out_c <= k && w != -1 && now <= 9 * 60) {
			windows[w].push(out_c++);
			w = find_shortest_queue();
		}
		start(now);
	}
	for (int i = 0; i < q; i++) {
		int query;
		cin >> query;
		print(query);
	}

	return 0;
}