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
## 1013 Battle Over Cities (25 分)
统计连通分量个数
可使用DFS/BFS
## 1014 Waiting in Line (30 分)
考察队列
**如果一个客户在17:00以及以后还没有开始服务就不再服务输出sorry；如果这个服务已经开始，无论时间多长都要等他服务完毕。**
计时循环体内三个步骤：
- 1）服务完的出队
- 2）待服务的入队
	- 有空窗口
	- 还有人
	- 还没到时间
- 3）初始化队首的start_time和finish_time

计时循环体结束的条件：
- 1）五点之后
- 2）队首有人正在服务

判断是否被服务的条件：
- 1）start_time >= 9 * 60
- 2）start_time == -1
## 1016 Phone Bills (25 分)
排序->筛选出合法的记录->计算费用
计算费用时从00:00:00到dd:hh:mm计算可以避免跨天的问题，比如01:12:00到02:02:00
```c++
double calculate(record a) {
	double total = a.date * 60 * toll[24] + a.min * toll[a.hour];
	for (int i = 0; i < a.hour; i++) {
		total += toll[i] * 60;
	}
	return total / 100;
}
```
## 1017 Queueing at Bank (25 分)
windows数组记录窗口结束服务的时间

**顾客等待时间计算：**
```c++
customers[index].waiting_time = max(windows[min_index] - customers[index].time_stamp, 0);
```
- 顾客到达时间比窗口结束服务时间晚->不需要等待
- 顾客到达时间比窗口结束服务时间早->需要等待

**窗口结束服务时间更新：**
```c++
windows[min_index] = max(windows[min_index], customers[index].time_stamp) + customers[index].processing_time * 60;
```
- 顾客不等待->```customers[index].time_stamp+customers[index].processing_time * 60```
- 顾客等待->```windows[min_index]+customers[index].processing_time * 60```
## 1018 Public Bike Management (30 分)
**Dijkstra+DFS**
```c++
// 有盈余
if (bike[station] - perf >= 0) {
	back += bike[station] - perf;
}
// 有亏损
else {
	int need = perf - bike[station];
	/*
	前面的盈余不足以抵亏损
	亏损增加，盈余置0
	*/
	if (need > back) {
		send += need - back;
		back = 0;
	}
	/*
	前面的盈余足以抵亏损
	亏损不变，盈余减少
	*/
	else {
		back -= need;
	}
}