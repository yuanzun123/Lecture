/*
* 题目名称：Find The Multiple
* 题目来源：POJ 1426
* 题目链接：http://poj.org/problem?id=1426
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

void BFS(int n) {
    queue<long long> myQueue;
    myQueue.push(1);                        //压入初始状态
    while (!myQueue.empty()) {
        long long current = myQueue.front();
        myQueue.pop();
        if (current % n == 0) {             //查找成功
            printf("%lld\n", current);
            return ;
        }
        myQueue.push(current * 10);
        myQueue.push(current * 10 + 1);
    }
    return ;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) {
            break;
        }
        BFS(n);
    }
    return 0;
}
//1.int（10^9）,long long(10^18) int与long long的范围（https://blog.csdn.net/gotowu/article/details/51203920）
//2.本题构建的搜索空间范围以及扩展搜索的反思：从结果（全为0和1）出发构建搜索范围，而不是条件（n的倍数）
