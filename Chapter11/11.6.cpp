/*
* 题目名称：畅通工程续
* 题目来源：HDU 1874
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1874
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 200 + 10;
const int INF = INT_MAX;                        //无穷设为很大的数

struct Edge {
    int to;                                     //终点
    int length;                                 //长度
    Edge(int t, int l): to(t), length(l) {}
};

struct Point {
    int number;                                 //点的编号
    int distance;                               //源点到该点距离
    Point(int n, int d): number(n), distance(d) {}
    bool operator< (const Point& p) const {
        return distance > p.distance;           //距离小的优先级高
    }
};

vector<Edge> graph[MAXN];                       //邻接表实现的图
int minDistance[MAXN];                          //源点到各点最短距离

void Dijkstra(int start) {
    minDistance[start] = 0;
    priority_queue<Point> myPriorityQueue;
    myPriorityQueue.push(Point(start, minDistance[start]));
    while (!myPriorityQueue.empty()) {
        int u = myPriorityQueue.top().number;   //离源点最近的点
        myPriorityQueue.pop();
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i].to;
            int l = graph[u][i].length;
            if (minDistance[v] > minDistance[u] + l) {
                minDistance[v] = minDistance[u] + l;
                myPriorityQueue.push(Point(v, minDistance[v]));
            }
        }
    }
    return ;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));            //图初始化
        fill(minDistance, minDistance + n, INF);    //距离初始化为无穷
        while (m--) {
            int from, to, length;
            scanf("%d%d%d", &from, &to, &length);
            graph[from].push_back(Edge(to, length));
            graph[to].push_back(Edge(from, length));
        }
        int start, terminal;                        //起点与终点
        scanf("%d%d", &start, &terminal);
        Dijkstra(start);
        if (minDistance[terminal] == INF) {         //终点不可达
            minDistance[terminal] = -1;
        }
        printf("%d\n", minDistance[terminal]);
    }
    return 0;
}
//最小生成树未必是最短路径，最小生成树仅仅为包含所有点的最短路径，而最短路径 是仅仅那两个点的最短路径
//先构建结构体数组（代表每条线段的属性）（它的索引代表起点，to代表终点，length代表长度），之后构建最短路路径数组（代表源点到每个点的最短路径），其中结构体数组使用vector<Edge> graph[MAXN]表示，
//代表构建MAXN个向量，因为每个点都有MAXN条发出的线段；之后对于二者赋值（对每个向量用memset初始化为0（具体原因不清楚，背下来）， 对最短路径数组初始化为正无穷）
//之后输入起点和终点并调用Dijkstra算法（如果终点可达，则输出到达终点的长度）

