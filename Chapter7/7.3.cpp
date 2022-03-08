/*
* 题目名称：Senior's Gun
* 题目来源：HDU 5281
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=5281
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

long long gun[MAXN];
long long monster[MAXN];

bool Compare(long long x, long long y) {
    return x > y;
}

int main() {
    int caseNumber;
    scanf("%d", &caseNumber);
    while (caseNumber--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &gun[i]);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lld", &monster[i]);
        }
        sort(gun, gun + n, Compare);        //枪从大到小排序
        sort(monster, monster + m);         //怪从小到大排序
        long long answer = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= m || gun[i] <= monster[i]) {
                break;
            }
            answer += (gun[i] - monster[i]);
        }
        printf("%lld\n", answer);
    }
    return 0;
}

//1.贪心算法可以达到最优解的条件：无后效性（可以借用强化学习中状态和动作的概念，也即对于当前状态来说，此时所采取的策略和之前的无关）https://blog.csdn.net/qq_30137611/article/details/77655707
//2.本题可以用贪心算法的原因：当前状态：人手中的剩余枪、剩余的动物，此时采用哪只枪打什么动物与之前的策略无关
