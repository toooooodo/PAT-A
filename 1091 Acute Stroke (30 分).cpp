#include <iostream>
#include <queue>

using namespace std;

#define MAXM 1286
#define MAXN 128
#define MAXL 60

bool matrix[MAXL][MAXM][MAXN] = { false };/*, visited[MAXL][MAXM][MAXN] = { false };*/
int z_[6] = { -1,1,0,0,0,0 };
int y_[6] = { 0,0,1,-1,0,0 };
int x_[6] = { 0,0,0,0,1,-1 };
struct pixel {
	int x, y, z;
	pixel(int x, int y, int z) :x(x), y(y), z(z) {}
	pixel() {}
};

bool judge(int x, int y, int z, int n, int m, int l) {
	if (x < 0 || y < 0 || z < 0)
		return false;
	if (x >= n || y >= m || z >= l)
		return false;
	return matrix[z][y][x];
}

int bfs(int z, int y, int x, int l, int m, int n) {
	int count = 1;
	matrix[z][y][x] = false;
	queue<pixel> q;
	q.push(pixel(x, y, z));
	while (q.empty() == false) {
		pixel front = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			pixel next;
			next.x = front.x + x_[i];
			next.y = front.y + y_[i];
			next.z = front.z + z_[i];
			if (judge(next.x, next.y, next.z, n, m, l)) {
				q.push(next);
				count++;
				matrix[next.z][next.y][next.x] = false;
			}
		}
	}
	return count;
}

int main() {
	int m, n, l, t, stroke = 0;
	cin >> m >> n >> l >> t;
	for (int z = 0; z < l; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++)
				cin >> matrix[z][y][x];
		}
	}
	for (int z = 0; z < l; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				if (matrix[z][y][x] == true) {
					int count = bfs(z, y, x, l, m, n);
					if (count >= t)
						stroke += count;
				}
			}
		}
	}
	cout << stroke << endl;
	return 0;
}