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
```
## 1021 Deepest Root (25 分)
进制转换，注意当radix>10时，如16，取余后有11、12、13等，不能将11、12、13的各位数字分开。
## 1022 Digital Library (30 分)
本题思路很简单，但输入的处理有些坑。
- cin
	- cin>> 可以从键盘读取想要的数据，以空格，tab键，以及换行来作为分隔符
	- 需要注意的是，当从缓冲区中读入数据的时候，如果缓冲区的第一个字符是空格，tab键，以及换行这些**分隔符**的时候，cin>>会将其**忽略**掉并从缓冲区中清除，继续读取下一个字符，如果缓冲区为空，那么cin会继续等待，如果读取成功，字符后面的**分隔符**是**残留**在缓冲区中的，cin>>不做处理。
- getline
	- ```istream& getline (istream& is, string& str, char delim);```
	- ``` istream& getline (istream& is, string& str);```
	- Extracts characters from is and stores them into str **until the delimitation character delim is found (or the newline character, '\n', for (2)).**
	- The extraction also stops if the end of file is reached in is or if some other error occurs during the input operation.
 	- **If the delimiter is found, it is extracted and discarded** (i.e. it is not stored and the next input operation will begin after it).
	- Note that any content in str before the call is replaced by the newly extracted sequence.

**示例：**
```c++
cin >> n;
getchar();
getline(cin, id);
```
cin处理后'\n'残留在缓冲区中，故需要getchar()。否则getline函数读入的是'\n'。
## 1029 Median (25 分)
>  It is guaranteed that all the integers are in the range of **long int**.

**long int** 即 `long`

思路：
- 先将第一个数组全部读入，再逐个读入第二个数组。记第二个数组的当前元素是`tmp`，并事先计算出中位数的位置`med`。用`count`记录已经遍历了多少个数，用`index`记录当前第一个数组的位置。
- 读入`tmp`后，先循环第一个数组，条件是数组的`index`位置值比`tmp`小，同时更新index和count，若```count==med```则`[index]`是中位数。否则跳出循环后，```count++```，若此时```count==med```，则`tmp`是中位数。
- 若将第二个数组全部读完后，还没有将第一个数组遍历完，则中位数在第一个数组中，此时需要接着遍历第一个数组，直到`count==med`，`[index]`是中位数。
## 1038 Recover the Smallest Number (30 分)
**贪心算法**，排序函数设计很巧妙，呜呜呜。
## 1033 To Fill or Not to Fill (25 分)
贪心算法
《算法笔记 上机训练实战指南》**P152**
## 1040 Longest Symmetric String (25 分)
**动态规划**
## 1044 Shopping in Mars (25 分)
**二分法**
upper_bound函数返回在[L,R)内第一个大于x的位置。
```c++
int upper_bound(int left, int right, int x) {
    /*
    return: [left, right], 返回right代表未找到
    */
    while (left < right) {
        int mid = (left + right) / 2;
        if (sum[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left; //或者return right
}
```
## 1045 Favorite Color Stripe (30 分)
**动态规划** 最长公共子序列（LCS）的变形。
## 1047 Student List for Course (25 分)
string容易超时，数据量大时最好使用char[]。
## 1049 Counting Ones (30 分)
直接暴力解会超时，应该找规律。
## 1052 Linked List Sorting (25 分)
链表排序，使用静态链表。
```c++
struct node {
	int key;
	int addr, next;
	bool flag;
	node() : flag (false) {}
}lst[MAX];
```
其中`flag`表示结点在链表中是否出现。
对结点进行排序：
```c++
bool cmp(node a, node b) {
	if (a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}
```

## 1055 The World's Richest (25 分)

> M的范围仅在100以内，因此可以进行预处理，即将每个年龄中财富在前100名全部存储在`valid`数组中，后面查询的操作可以在新数组中进行。
```c++
sort(lst, lst + n, cmp);
for (int i = 0; i < n; i++) {
	if (age[lst[i].age] < 100) {
		age[lst[i].age]++;
		valid[valid_n++] = lst[i];
	}
}
```
## 1056 Mice and Rice (25 分)
**队列应用** 
若本轮共分成`group`个组，则本轮淘汰的老鼠排名为`group + 1`。
## 1057 Stack (30 分)
**分块思想**
将有序序列划分成$\lceil$$\sqrt N$$\rceil$块，每块元素个数不超过$\lfloor$$\sqrt N$$\rfloor$。
定义一个统计数组`block[]`，`block[i]`代表第`i`块中存在的元素个数。
定义一个数组`table[]`，`table[x]`表示整数`x`的当前存在个数。
- 在线插入：
```c++
block[x / BLOCK_NUM]++;
table[x]++;
```
- 在线查找第pos个元素：
```c++
int sum = 0, index = 0;
while (sum + block[index] < pos) {
    sum += block[index++];
}
int num = index * BLOCK_NUM;
while (sum + table[num] < pos) {
    sum += table[num++];
}
return num;
```
## 1063 Set Similarity (25 分)
输出% -->
```c++
printf("%%");
```
## 1064 Complete Binary Search Tree (30 分)
**完全二叉排序树**的中序遍历
## 1065 A+B and C (64bit) (20 分)
用Python直接过，C++要注意`long long`溢出。
``` c++
if (a > 0 && b > 0 && a + b <= 0)
    printf("Case #%d: true\n", i + 1);
else if (a < 0 && b < 0 && a + b >= 0)
    printf("Case #%d: false\n", i + 1);
```
## 1067 Sort with Swap(0, i) (25 分)

`pos[x] = i;`表示`x`在`i`号位置上。

## 1069 The Black Hole of Numbers (20 分)

注意输入6174

## 1072 Gas Station (30 分)

最短路径

## 1074 Reversing Linked List (25 分)

**反转链表** 每k个反转

```c++
int reverse(int head, int n, int k) {
    if (n < k)
        return head;
    int tail = head;
    int tmp, last, next;
    tmp = last = head;
    next = lst[head].next;
    for (int i = 0; i < k - 1; i++) {
        tmp = next;
        next = lst[tmp].next;
        lst[tmp].next = last;
        last = tmp;
    }
    lst[tail].next = reverse(next, n - k, k);
    return tmp;
}
```

## 1078 Hashing (25 分)

平方探测法：`M = (a + step * step) % table_size`，若`step`从`0`到`table_size - 1`都没有找到位置，那么对于`>=table_size`也不可能找到位置。

## 1085 Perfect Sequence (25 分)

和1044一样，upper_bound找到`[left, right)`内第一个大于x的位置。

## 1087 All Roads Lead to Rome (30 分)

Dijkstra + DFS

## 1089 Insert or Merge (25 分)

merge sort

```c++
void merge_sort(int n, int a[]) {
    for (int step = 2; step / 2 < n; step *= 2) {
        for (int i = 0; i < n; i += step) {
            sort(a + i, a+min(i+step,n));
        }
    }
}
```

## 1091 Acute Stroke (30 分)

BFS，三维数组。
`step`控制方向

```c++
int step[3][6] = {
    {0,0,0,1,0,-1},
    {0,0,1,0,-1,0},
    {1,-1,0,0,0,0},
};
```

## 1093 Count PAT's (25 分)

`count += (p[i] * t[i]) % 1000000007;`会溢出，正确写法是：`count = (count + (p[i] * t[i]) % 1000000007) % 1000000007;`

## 1095 Cars on Campus (30 分)

和1016 Phone Bills (25 分)思路相同，先将记录按照ID，时间的顺序排序。

```c++
bool cmp(record a, record b) {
    if (a.id != b.id)
        return a.id < b.id;
    else
        return a.time < b.time;
}
```

## 1098 Insertion or Heap Sort (25 分)

堆排序

```c++
void perc_down(int n, int i) {
    int tmp, child;
    for (tmp = heap[i]; i * 2 + 1 < n; i = child) {
        child = i * 2 + 1;
        if (child != n - 1 && heap[i * 2 + 1] < heap[i * 2 + 2])
            child++;
        if (heap[child] > tmp)
            heap[i] = heap[child];
        else
            break;
    }
    heap[i] = tmp;
}

void heap_sort(int n) {
    bool flg = false;
    for (int i = n / 2; i >= 0; i--)
        perc_down(n, i);
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1 && check(n, heap)) {
            flg = true;
        }
        swap(heap[0], heap[i]);
        perc_down(i, 0);
        if (flg)
            break;
    }
}
```

## 1101 Quick Sort (25 分)

`left_to_right_max[MAX]`记录从左往右当前出现过的最大数。`right_to_left_min[MAX]`记录从右往左当前出现过的最小数。若`left_to_right_max[i] == right_to_left_min[i]`则可以作为pivot。

## 1103 Integer Factorization (30 分)

**DFS** 有选和不选两种选择

## 1104 Sum of Number Segments (20 分)

`double`和`int`相乘是玄学吧

## 1107 Social Clusters (30 分)

**并查集**,题目大意是以hobby为桥梁将用户联系起来。不要忘记初始化数组。

- `father[x]=i`表示`x`号用户的集合父亲是`i`。

- `hobby[h]=x`表示喜欢`h`爱好的一位用户是`x`。

- `root[i]=k`表示以`i`为根的集合有`k`个用户。

计算集合元素个数的过程：

```c++
for (int i = 1; i <= n; i++) {
    root[find_father(i)]++;
}
```

## 1112 Stucked Keyboard (20 分)

string, set, vector的应用。**注意：**

```C++
for (auto it = stu_vec.begin(); it != stu_vec.end(); it++) {
    if (*it == ch) {
        stu_vec.erase(it);
        break;
    }
}
```

此处要即时`break`

```C++
string text = "1234";
auto it = text.begin();
text.erase(it);
cout << (*it) << endl;  //输出2
```

## 1114 Family Property (25 分)

并查集的应用

## 1115 Counting Nodes in a BST (30 分)

**BST**二叉搜索树，看清题目中的定义。用层序遍历或深度优先都可以。

## 1117 Eddington Number (25 分)

排序。

```c++
int n, e = n;
cin >> n;
```

这是一个错误写法。

## 1119 Pre- and Post-order Traversals (30 分)

**树的前序遍历+后序遍历->中序遍历。**
前序遍历数组第一个元素`pre[pre_left]`与后序遍历数组的最后一个元素`post[post_right]`一定是根。后序遍历数组的倒数第二个元素`post[post_right - 1]`一定可以是右儿子，有可能可以是左儿子。在前序遍历数组中找到`index`使`pre[index] == post[post_right - 1]`。若`index - pre_left <= 1`说明`root`下只有一个分支，且该分支可以是左子树也可以是右子树。*注意*，当`pre_left == pre_right`时，`index - pre_left == 1`，但不能依据此判定树非唯一，所以这种情况需要特判。

此外，最后一行需要输出换行符`\n`,否则测试点全部格式错误。

## 1126 Eulerian Path (25 分)

Eulerian Path首先要判断图是否连通

## 1129 Recommendation System (25 分)

`Sets are containers that store unique elements following a specific order.`set内部元素有序（非递减），若内部元素是结构体，则可以使用重载运算符构造想要的排序方式。

```c++
struct item {
    int id;
    int freq;
    item(int id, int freq) : id(id), freq(freq) {}
    bool operator < (const item &a) const {
        if (freq != a.freq)
            return freq > a.freq;
        else
            return id < a.id;
    }
};
```

## 1130 Infix Expression (25 分)

**中缀表达式**， 中序遍历的变型

## 1131 Subway Map (30 分)

图的**DFS**，`int line[MAX][MAX];`记录站点之间是几号线，`vector<int> subway[MAX];`记录站点的邻接站点。

## 1132 Cut Integer (20 分)

注意除数为0的情况

## 1134 Vertex Cover (25 分)

判断图的所有边是否和给定顶点集合内的任一顶点相连通。两种思路：

- 遍历集合内的顶点，判断集合内的顶点是否能够覆盖所有的边。

- 遍历图的所有边，判断是否有边的顶点不在集合内。

1135 Is It A Red-Black Tree (30 分)

红黑树的判定
`tree insert(vector<int>& pre, vector<int>& in, int pre_left, int pre_right, int in_left, int in_right)`当使用`g++`编译器时，若`vector<>`参数不用引用，第一个测试点段错误，`clang++`编译器则答案正确。

## 1139 First Contact (30 分)

A---B---C---D，A与B、C与D一定是同性。
`bool graph[MAX][MAX]`用来记录两个人之间是否存在朋友关系。
`vector<int> same_gender_friends[MAX]`用来记录同性的朋友。
在给定AD后，遍历A、D的所有同性朋友B、C，若BC之间存在朋友关系，则为一组解。

## 1143 Lowest Common Ancestor (30 分)

找 lowest common ancestor (LCA) ，题目给出了树的先序遍历，没有必要重新构造出树结构。

## 1148 Werewolf - Simple Version (20 分)

## 1153 Decode Registration Card of PAT (25 分)
