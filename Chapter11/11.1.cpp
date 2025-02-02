/*
* 题目名称：畅通工程
* 题目来源：浙江大学复试上机题
* 题目链接：http://t.cn/AiOvBHj9
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000 + 10;

int father[MAXN];                               //父亲结点
int height[MAXN];                               //结点高度

void Initial(int n) {                           //初始化
    for (int i = 0; i <= n; i++) {
        father[i] = i;                          //每个结点的父亲为自己
        height[i] = 0;                          //每个结点的高度为零
    }
}

int Find(int x) {                               //查找根结点
    if (x != father[x]) {                       //路径压缩
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x, int y) {                      //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {                               //矮树作为高树的子树
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

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        scanf("%d", &m);
        Initial(n);                             //初始化
        while (m--) {
            int x, y;
            scanf("%d", &x);
            scanf("%d", &y);
            Union(x, y);                        //合并集合
        }
        int answer = -1;
        for (int i = 1; i <= n; i++) {
            if (Find(i) == i) {                 //集合数目
                answer++;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
//树的深度height：树中最长链的长度
//思路：先初始化每个节点的father与其height;之后合并集合（先找到两个集合的根节点，之后矮树作为高树的子树）;最后查找集合总数（也就是查询根结点个数）并将其通过加一或减一转换成题目所需的道路数
//易错：1.由于最终仅仅输入n=0，所以循环语句不可有m，m要在循环语句内部，否则最终进不了循环
//并查集讲解：https://zhuanlan.zhihu.com/p/93647900/
