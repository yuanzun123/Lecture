/*
* 题目名称：Is It A Tree?
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiO7FyDO
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

int father[MAXN];                               //父亲结点
int height[MAXN];                               //结点高度
int inDegree[MAXN];                             //入度
bool visit[MAXN];                               //标记

void Initial() {                                //初始化
    for (int i = 0; i < MAXN; i++) {
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        visit[i] = false;
    }
}

int Find(int x) {                               //查找根结点
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {                      //合并集合
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

bool IsTree() {
    bool flag = true;
    int component = 0;                          //连通分量数目
    int root = 0;                               //根结点数目
    for (int i = 0; i < MAXN; ++i) {
        if (!visit[i]) {
            continue;
        }
        if (father[i] == i) {
            component++;
        }
        if (inDegree[i] == 0) {
            root++;
        } else if (inDegree[i] > 1) {           //入度不满足要求
            flag = false;
        }
    }
    if (component != 1 || root != 1) {          //不符合树定义
        flag = false;
    }
    if(component == 0 && root == 0) {           //空集也是树
        flag = true;
    }
    return flag;
}

int main() {
    int x, y;
    int caseNumber = 0;
    Initial();
    while (scanf("%d%d", &x, &y) != EOF) {
        if (x == -1 && y == -1) {
            break;
        }
        if (x == 0 && y == 0) {
            if (IsTree()) {
                printf("Case %d is a tree.\n", ++caseNumber);
            } else {
                printf("Case %d is not a tree.\n", ++caseNumber);
            }
            Initial();
        } else {
            Union(x, y);
            inDegree[y]++;
            visit[x] = true;
            visit[y] = true;
        }
    }
    return 0;
}
//思路：在没有给定n和m而直接输入时，先输入数字，后通过多个判断去行事（注意一次输入终结不要忘记为下次输入开始初始化），建立并查集后自己构建一个函数判断是否为数
//判断方法：先确定是否为之前输入过的节点，之后判断，判断要符合两点（1.并查集仅仅有一个集合(代表整个图形连通)2.按照题目中定义的方式仅仅有一个根节点（代表整个图形只有一个题目定义的根节点））
//判断过程中还需要注意空节点的可能
//本来并查集不规定箭头方向，但本题需要规定箭头方向，所以可以正规建立一个并查集，之后再在该并查集之上再指定一个集合规定箭头方向
//本题坑点：1.需要都一万个元素判断是否为树，因为输入不一定是1~n，本题是输入过哪个节点代表哪个节点存在2.并查集仅仅有一个集合仅代表连通，根节点的数目还需要根据自己定义的每个节点接受结点的数目判定
//编译过程两个错误：1.没有在一组数据输入完后下一组数据输入前重新进行初始化2.在判断是否为树时没有单独判断空集的情况
