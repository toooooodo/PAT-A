#include <iostream>
#include <queue>

using namespace std;

#define MAXM 1286
#define MAXN 128
#define MAXL 60

int brain[MAXM][MAXN][MAXL];
bool visited[MAXM][MAXN][MAXL] = { false };
int step[3][6] = {
	{0,0,0,1,0,-1},
	{0,0,1,0,-1,0},
	{1,-1,0,0,0,0},
};
struct pixel {
	int x, y, z;
	pixel() {}
	pixel(int x, int y, int z) :x(x), y(y), z(z) {}
};

bool judge(int x, int y, int z, int m, int n, int l) {
	if (x < 0 || y < 0 || z < 0)
		return false;
	if (x >= m || y >= n || z >= l)
		return false;
	if (brain[x][y][z] == 0)
		return false;
	if (visited[x][y][z] == true)
		return false;
	return true;
}

int bfs(int x, int y, int z, int m, int n, int l, int t) {
	queue<pixel> q;
	pixel now(x, y, z);
	visited[x][y][z] = true;
	q.push(now);
	int count = 1;
	while (q.empty() == false) {
		pixel front = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			pixel next;
			next.x = front.x + step[0][i];
			next.y = front.y + step[1][i];
			next.z = front.z + step[2][i];
			if (judge(next.x, next.y, next.z, m, n, l)) {
				q.push(next);
				visited[next.x][next.y][next.z] = true;
				count++;
			}
		}
	}
	if (count >= t)
		return count;
	else
		return 0;
}

int main() {
	int m, n, l, t;
	cin >> m >> n >> l >> t;
	int res = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++)
				cin >> brain[j][k][i];
		}
	}
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (judge(j, k, i, m, n, l)) {
					res += bfs(j, k, i, m, n, l, t);
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}