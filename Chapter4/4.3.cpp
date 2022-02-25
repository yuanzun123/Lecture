/*
* 题目名称：简单密码
* 题目来源：北京大学复试上机题
* 题目链接：﻿http://t.cn/Ai8bih2z
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {             //起始行
        if (str == "ENDOFINPUT") {
            break;
        }
        getline(cin, str);                  //密文
        for (int i = 0; i < str.size(); ++i) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
            }
        }
        cout << str << endl;
        getline(cin, str);                  //结束行
        return 0;
    }
}
//1.第17行中字符串要用双引号，而不可用单引号，单个字符可以用单引号
