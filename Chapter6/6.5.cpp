/*
* 题目名称：最大公约数
* 题目来源：哈尔滨工业大学复试上机题
* 题目链接：http://t.cn/AiCuWLTS
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", GCD(a, b));
    }
    return 0;
}
//本题求最大公约数的函数的迭代算法
//最大公约数算法
//最小公倍数是两个数的乘积除以他们的最大公约数
