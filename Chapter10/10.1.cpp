/*
* 题目名称：二叉树遍历
* 题目来源：清华大学复试上机题
* 题目链接：http://t.cn/AiKuUTlX
* 代码作者：杨泽邦(炉灰)
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    char data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char c): data(c), leftChild(NULL), rightChild(NULL) {}
};

TreeNode* Build(int& position, string str) {
    char current = str[position++];                     //当前字符
    if (current== '#') {                                //返回空树
        return NULL;
    }
    TreeNode* root = new TreeNode(current);             //创建新节点
    root -> leftChild = Build(position, str);           //创建左子树
    root -> rightChild = Build(position, str);          //创建右子树
    return root;
}

void InOrder(TreeNode* root) {                          //中序遍历
    if (root == NULL) {
        return;
    }
    InOrder(root->leftChild);
    printf("%c ", root->data);
    InOrder(root->rightChild);
    return ;
}

int main() {
    string str;
    while (cin >> str) {
        int position = 0;                               //标记字符串处理位置
        TreeNode* root = Build(position, str);
        InOrder(root);
        printf("\n");
    }
    return 0;
}
//new语法（https://www.runoob.com/cplusplus/cpp-dynamic-memory.html）
//函数中定义new等同于static变量，这样就可以从函数中返回在函数中定义的指针（https://www.runoob.com/cplusplus/cpp-return-pointer-from-functions.html）（https://blog.csdn.net/weixin_41232202/article/details/96452228?spm=1001.2101.3001.6650.4&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-4.pc_relevant_default&utm_relevant_index=8）
#include <iostream>
//using namespace std;
//
//int* example1()
//{
//    //可以在new后面直接赋值
//    int* p = new int(3);
//    //也可以单独赋值
//    //*p = 3;
//
//    //如果不想使用指针，可以定义一个变量，在new之前用“*”表示new出来的内容
//    //int q = *new int;
//    //q = 1;
//    //cout << q << endl;
//
//    return p;
//}
//
//int* example2()
//{
//    //当new一个数组时，同样用一个指针接住数组的首地址
//    int* q = new int[3];
//    for (int i = 0; i < 3; i++)
//        q[i] = i;
//
//    return q;
//}
//
//struct student
//{
//    string name;
//    int score;
//};
//
//
//student* example3()
//{
//    //这里是用一个结构体指针接住结构体数组的首地址
//    //对于结构体指针，个人认为目前这种赋值方法比较方便
//    student* stlist = new student[3]{ {"abc", 90}, {"bac", 78}, {"ccd", 93} };
//
//    return stlist;
//}
//
//
//
//int main()
//{
//    int* e1 = example1();
//    cout << "e1: " << *e1 << endl;
//    delete e1;
//    int* e2 = example2();
//    for (int i = 0; i < 3; i++)
//        cout << e2[i] << " ";
//    cout << endl;
//    delete[]e2;
//
//    student* st1 = example3();
//
//    for (int i = 0; i < 3; i++)
//        cout << st1[i].name << " " << st1[i].score << endl;
//
//    delete[]st1;
//
//    return 0;
//}
//以上为示例从函数中返回new定义的指针，并且不用delete
//
//通过前序遍历构建二叉树函数：先构建一个当前字符的节点，之后再递归调用本身构建当前节点的左和右节点，递归的终结是左和右节点都等于NULL
