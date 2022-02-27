/*
* 题目名称：约瑟夫问题No.2
* 题目来源：bailian 3254
* 题目链接：http://bailian.openjudge.cn/practice/3254
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int n, p, m;
    while (scanf("%d%d%d", &n, &p, &m)) {
        if (n == 0 && p == 0 && m == 0) {
            break;
        }
        queue<int> children;
        for (int i = 1; i <= n; ++i) {      //依此加入队列
            children.push(i);
        }
        for (int i = 1; i < p; ++i) {       //使编号p的小孩在队首
            children.push(children.front());
            children.pop();
        }
        while (!children.empty()) {
            for (int i = 1; i < m; ++i) {   //m - 1小孩依此重新入队
                children.push(children.front());
                children.pop();
            }
            if (children.size() == 1) {     //最后一个小孩的输出不同
                printf("%d\n", children.front());
            } else {
                printf("%d,", children.front());
            }
            children.pop();
        }
    }
    return 0;
}
//1.像本题一样的圈式循环报数选择队列
//2.通过本题中代码段可以了解到如何通过循环更改队列的首位，还有队列的.front(),.pop()等语法
//3.像本题一样最后一个输出不写‘，’可以通过判断语句，当长度为一是将‘,’转换成‘\n’.
