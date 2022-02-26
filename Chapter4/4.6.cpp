/*
* 题目名称：Number Sequence
* 题目来源：HDU 1711
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1711
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXM = 10000 + 10;
const int MAXN = 1000000 + 10;

int nextTable[MAXM];
int pattern[MAXM];
int text[MAXN];

void GetNextTable(int m) {                      //创建next表，next列表长度是m+1，即他的索引最大为m
    int j = 0;                                  //next[j]反应的是pattern[0]~pattern[j-1]这一段字符串的最大共有元素长度
    nextTable[j] = -1;                          //仅仅next[0]可以等于-1，其他如果没有都为0，还有pattern[-1]与任何其他元素都匹配
    int t = nextTable[j];                       //next[j]可以在pattern[j]与txt[i]不匹配时，返回新的可以供匹配的pattern索引，而定义方式是用了一个迭代，这样可以更为高效的的定义
    while (j < m) {                             //t的含义是当前最大前缀共有元素下一个元素的索引
        if (t == -1 || pattern[j] == pattern[t]) {  //所以采用如此递归方式
            j++;
            t++;
            nextTable[j] = t;
        } else {
            t = nextTable[t];
        }
    }
    return ;
}

int KMP(int n, int m) {                                             
    GetNextTable(m);
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        if (j == -1 || text[i] == pattern[j]) { //当前字符匹配成功
            i++;
            j++;
        } else {
            j = nextTable[j];                   //当前字符匹配失败
        }
    }
    if (j == m) {                               //模式串匹配成功
        return i - j + 1;
    } else {                                    //模式串匹配失败
        return -1;
    }
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &text[i]);
        }
        for (int j = 0; j < m; ++j) {
            scanf("%d", &pattern[j]);
        }
        printf("%d\n", KMP(n, m));
    }
    return 0;
}
//1.if判断语句中==，不要写成=
//2.KMP算法理解：
//3.while（case--）减号放在后面而不是前面
