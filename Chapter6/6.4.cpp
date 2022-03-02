/*
* 题目名称：进制转换2
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiCuKG7E
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

char IntToChar(int x) {                             //数字变成字符
    if (x < 10) {
        return x + '0';
    } else {
        return x - 10 + 'a';
    }
}

int CharToInt(char c) {                             //字符变成数字
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    string str;
    cin >> str;
    long long number = 0;
    for (int i = 0; i < str.size(); ++i) {          //从m进制变成十进制
        number *= m;
        number += CharToInt(str[i]);
    }
    vector<char> answer;
    if (number == 0) {
        answer.push_back('0');
    } else {
        while (number != 0) {                       //从十进制变成n进制
            answer.push_back(IntToChar(number % n));
            number /= n;
        }
    }
    for (int i = answer.size() - 1; i >= 0; --i) {  //逆序输出
        printf("%c", answer[i]);
    }
    printf("\n");
    return 0;
}
//本题考察点与上题不同，没有特殊强调很长的位数，则可以将计算得到的整数用long long去表示，但是输入得到的字符串不可以，因为那可能超过10进制
//实现思路：先将输入转换成10进制，之后将其再转换为其他进制（中途有字符和整形之间的互相转化）
//注意输出应该是顺序还是逆序
//注意本题中自己定义的函数问题，不可以用两个if，这样会导致报错，要用一个if {}else{}这样可以确保无论什么条件下都有输出
