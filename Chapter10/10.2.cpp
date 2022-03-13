/*
* 题目名称：二叉树遍历
* 题目来源：华中科技大学复试上机题
* 题目链接：http://t.cn/AiKgDfLU
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

TreeNode* Build(string str1, string str2) {
    if (str1.size() == 0) {                             //返回空树
        return NULL;
    }
    char current = str1[0];                             //当前字符
    TreeNode* root = new TreeNode(current);             //创建新节点
    int position = str2.find(current);                  //寻找切分点
    root -> leftChild = Build(str1.substr(1, position), str2.substr(0, position));
    root -> rightChild = Build(str1.substr(position + 1), str2.substr(position + 1));
    return root;
}

void PostOrder(TreeNode* root) {                        //后序遍历
    if (root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%c", root->data);
    return;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        TreeNode* root = Build(str1, str2);
        PostOrder(root);
        printf("\n");
    }
    return 0;
}
//1.substr的用法：https://blog.csdn.net/qq_42185999/article/details/106985376?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164715872616781685375791%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164715872616781685375791&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-106985376.article_score_rank&utm_term=substr%E5%87%BD%E6%95%B0%E7%94%A8%E6%B3%95&spm=1018.2226.3001.4187
//2.str.find(char c)函数：返回str中第一个c字符的索引
//3.由前序和中序构建二叉树的思路：前序第一个为二叉树的根节点，之后可由此构建递推，将一个二叉树划分为两个小的二叉树，构建节点的终结是如果传入长度为0，返回NULL
