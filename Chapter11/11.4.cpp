/*
* 题目名称：还是畅通工程
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiWud0C6
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Edge {
    int from;                           //边的起点
    int to;                             //边的终点
    int length;                         //边的长度
    bool operator< (const Edge& e) const {
        return length < e.length;
    }
};

Edge edge[MAXN * MAXN];                 //边集
int father[MAXN];                       //父亲结点
int height[MAXN];                       //结点高度

void Initial(int n) {                   //初始化
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int x) {                       //查找根结点
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {              //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[y] < height[x]) {
            father[y] = x;
        } else {
            father[y] = x;
            height[x]++;
        }
    }
    return ;
}

int Kruskal(int n, int edgeNumber) {
    Initial(n);
    sort(edge, edge + edgeNumber);      //按权值排序
    int sum = 0;
    for (int i = 0; i < edgeNumber; ++i) {
        Edge current = edge[i];
        if (Find(current.from) != Find(current.to)) {
            Union(current.from, current.to);
            sum += current.length;
        }
    }
    return sum;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        int edgeNumber = n * (n - 1) / 2;
        for (int i = 0; i < edgeNumber; ++i) {
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].length);
        }
        int answer = Kruskal(n, edgeNumber);
        printf("%d\n", answer);
    }
    return 0;
}
//思路：构建结构体并重载小于号（注意重载小于号的语句）为了后续方便排序，之后构建并查集，并按照边的权值递增遍历，如果两个点不属于同一集合，则，怎合并两个集合，并且由于之前对边长的排序
//所以此时长度一定最短，将此最短的边加上，最后如果有最小生成树（并查集仅有一个集合）则求得和为满足条件的结果
