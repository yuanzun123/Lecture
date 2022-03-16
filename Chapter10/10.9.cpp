/*
* 题目名称：子串计算
* 题目来源：北京大学复试上机题
* 题目链接：http://t.cn/AiCuJtI5
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        map<string, int> number;
        for (int i = 0; i <= str.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string key = str.substr(j, i - j);  //每个子串
                number[key]++;
            }
        }
        map<string, int>::iterator it;              //定义迭代器
        for (it = number.begin(); it != number.end(); ++it) {
            if (1 < it->second) {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}
//C++迭代器：类似于指针，常用形式如本题，不过第几个元素使用first、second代替(https://blog.csdn.net/CSDN_564174144/article/details/76231626)
//思路：使用双重循环配合字典（一般用于存储对应关系后方便查找）计算子串出现的次数，之后使用迭代器（因为map中的key（索引）是有序的，所以符合本题要求进行排序）
