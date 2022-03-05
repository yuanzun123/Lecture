/*
* 题目名称：人见人爱A^B
* 题目来源：HDU 2035
* 题目链接：http://acm.hdu.edu.cn/showproblem.php?pid=2035
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>

using namespace std;

int FastExponentiation(int a, int b, int mod) {
    int answer = 1;             //初始化为1
    while (b != 0) {            //不断将b转换为二进制
        if (b % 2 == 1) {       //若当前位为1，累乘a的2^k次幂
            answer *= a;
            answer %= mod;      //求后三位
        }
        b /= 2;
        a *= a;                 //a不断平方
        a %= mod;
    }
    return answer;
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        printf("%d\n", FastExponentiation(a, b, 1000));
    }
    return 0;
}
//一个数的快速幂可以将幂次表示为2进制，之后用题目中的循环以快速计算，减少乘的次数
//如果两个数的乘积只要后三位，可以只用两个数的后三位去乘
