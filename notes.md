# NOTES
## 1010 Radix (25 分)

给出一个字符串，找出特定的进制使该字符串能等于一个给定的值（goal）。
- 进制的下界：
    - 对123a来说，最小的可能进制是11，因为有a。所以进制的下界是字符串中最大字符所代表的数字+1。
- 进制的上界：
    - 只有一位时，等于下界。
        - 例如11 b 1 10，下界是12，而goal是11.
    - 多位时，等于goal。
    - 所以是max(下界，goal)
- 寻找合适的进制时要使用二分查找。
```c++
while (low <= high) {
	long long mid = (low + high) / 2;
	long long convert_result = convert(n2, mid);
	if (convert_result == goal) {
		cout << mid << endl;
		flag = false;
		break;
	}
	// 一定要判断convert_result < 0，溢出说明当前进制太大
	else if (convert_result < 0 || convert_result > goal) {
		high = mid - 1;
	}
	else {
		low = mid + 1;
	}
}
```

## 1034 Head of a Gang (30 分)
考察图的DFS
```c++
void dfs(int index, int &head, int &total_weight, int &p_num) {
	visited[index] = true;
	p_num++;
	if (weight[index] > weight[head]) {
		head = index;
	}
	for (int i = 0; i < total_p; i++) {
		if (graph[i][index] != 0) {
			total_weight += graph[i][index];
			/*消除已经走过的边*/
			graph[i][index] = graph[index][i] = 0;
			if (visited[i] == false)
				dfs(i, head, total_weight, p_num);
		}
	}
}
```
**图的DFS模板:**
```c++
DFS(U){
	vis[u]=true;
	for(从u出发能到达的顶点v){
		if vis[v]==false
			DFS[v]
	}
}
DFSTrave(G){
	for(G的所有顶点u){
		if vis[u]==false
			DFS(u);
	}
}
```
本题还有一个坑，通话记录不超过1000条，说明共有不超过2000个人，所以MAX=2000。
## 1076 Forwards on Weibo (30 分)
图的BFS
```c++
BFS(u){
	queue q;
	q.push(u);
	inq[u]=true;
	while(q.empty()==false){
		f=q.front();
		q.pop();
		for(从f出发可能到达的顶点v){
			if (inq[v]==false){
				q.push(v);
				inq[v]=true;
			}
		}
	}
}
```