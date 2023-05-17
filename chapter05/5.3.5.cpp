/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 21:27:25
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 21:58:00
 * @FilePath: \wangdao-datastructure\chapter05\5.3.5.cpp
 * @Description: 使用非递归计算二叉树的高度
 */
#include <iostream>
using namespace std;
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

void buildtree(tree &t)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (treenode *)malloc(sizeof(treenode));
        t->data = ch;
        // 先定义，再赋值
        t->lchild = NULL;
        t->rchild = NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
int depth(tree t)
{
    if (!t)
        return 0;
    // 线性存储队列
    treenode *q[10];
    // 保证头指针指向元素前一位，尾指针指向元素所在位
    int f = -1, r = -1;
    int L = 0, ans = 0;
    // 根节点入队
    q[++r] = t;
    treenode *p;
    // 队列不为空
    while (f < r)
    {
        p = q[++f];
        if (p->lchild)
            q[++r] = p->lchild;
        if (p->rchild)
            q[++r] = p->rchild;
        // 如果出的是改层最后一个
        if (f == L)
        {
            // 更新高度，更新L
            ans++;
            L = r;
        }
    }
    return ans;
}
int main()
{
    tree t;
    buildtree(t);
    cout << "树的高度为:" << depth(t) << endl;
    return 0;
}
