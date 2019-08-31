#include <iostream>
#include <queue>

using namespace std;

#define MAXN 20
#define MAXK 1010

struct customer {
	int start, end;
	int served;
	customer() :start(-1), end(-1) {}
}customers[MAXK];
queue<int> windows[MAXN];

void finish(int now, int n) {
	for (int i = 0; i < n; i++) {
		if (windows[i].empty() == false) {
			int front = windows[i].front();
			if (customers[front].end == now)
				windows[i].pop();
		}
	}
}

int in_queue(int now, int n, int m, int custom) {
	int window_index = -1, min_window_size = 0x7fffffff;
	for (int i = 0; i < n; i++) {
		if (windows[i].size() < min_window_size && windows[i].size() != m) {
			min_window_size = windows[i].size();
			window_index = i;
		}
	}
	return window_index;
}

void start(int now, int n) {
	for (int i = 0; i < n; i++) {
		if (windows[i].size() != 0) {
			int front = windows[i].front();
			if (customers[front].start == -1) {
				customers[front].start = now;
				customers[front].end = now + customers[front].served;
			}
		}
	}
}

bool check_still_served(int n) {
	for (int i = 0; i < n; i++) {
		if (windows[i].size() != 0) {
			if (customers[windows[i].front()].start < 9 * 60 && customers[windows[i].front()].start != -1)
				return true;
		}
	}
	return false;
}

void print_res(int k, int index) {
	if (customers[index].start == -1)
		cout << "Sorry" << endl;
	else {
		printf("%02d:%02d\n", customers[index].end / 60 + 8, customers[index].end % 60);
	}
}

int main() {
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++) {
		cin >> customers[i].served;
	}
	int next_customer = 1;
	for (int now = 0; now < 9 * 60 || check_still_served(n); now++) {
		finish(now, n);
		int win = in_queue(now, n, m, next_customer);
		while (win != -1 && next_customer <= k && now < 9 * 60) {
			windows[win].push(next_customer);
			next_customer++;
			win = in_queue(now, n, m, next_customer);
		}
		if (now < 9 * 60)
			start(now, n);
	}
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		print_res(k, x);
	}
	return 0;
}