/*
* 题目名称：FatMouse' Trade
* 题目来源：HDU 1009
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=1009
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000 + 10;

struct JavaBean {
    double weight;
    double cost;
};

JavaBean arr[MAXN];

bool Compare(JavaBean x, JavaBean y) {
    return (x.weight / x.cost) > (y.weight / y.cost);
}

int main() {
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        if (m == -1 && n == -1) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &arr[i].weight, &arr[i].cost);
        }
        sort(arr, arr + n, Compare);            //性价比降序排列
        double answer = 0;
        for (int i = 0; i < n; ++i) {
            if (m >= arr[i].cost) {             //全部买下
                answer += arr[i].weight;
                m -= arr[i].cost;
            } else {                            //只能买部分
                answer += arr[i].weight * (m / arr[i].cost);
                m = 0;
                break;
            }
        }
        printf("%.3f\n", answer);
    }
    return 0;
}
//1.sort中定义的Compare（x，y）函数记住，当它返回值为true时，x就排在y前面
//2.double的输入为%ld,本题中输出%.3f
//本题的策略为贪心性价比，还有注意结构体（一个物品多个属性时常定义结构体）
