/*
* 题目名称：查找学生信息
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiCuVIuY
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> student;

int main() {
    int n;
    scanf("%d", &n);
    getchar();                                  //吃掉回车
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        int position = str.find(' ');           //分界点
        string key = str.substr(0, position);   //学号作为关键字
        student[key] = str;                     //信息作为映射值
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        string key;
        cin >> key;
        string answer = student[key];
        if (answer == "") {                     //找不到该学生
            answer = "No Answer!";
        }
        cout << answer << endl;
    }
    return 0;
}
//getchar(吃掉回车)：回车可以作为string的输入终结，但它输入之前如果有残留回车需要用getchar（）去吃掉
//map等价于字典，直接用索引去构建即可
//每道题写完再读一遍题目，检查特殊情况，如本题的No Answer!
//思路：利用字符串分割substr的思想将字符串转换为索引与值，之后判断输出。（输入过程中注意对于回车的处理）
