/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 18:21:10
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 18:58:30
 * @FilePath: \wangdao-datastructure\chapter05\5.3.3.cpp
 * @Description: 编写后序遍历二叉树的非递归算法
 */
#include <iostream>
using namespace std;
// 定义链式存储的二叉树,带标志域
typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild, *rchild;
    int tag;
} TreeNode, *Tree;
// 构造一棵二叉树
// t为头指针，要更改头指针的值，故为引用
void createtree(Tree &t)
{
    // 从键盘读入数据，#代表空结点,前序构造
    char ch;
    ch = getchar();
    if (ch == '#')
        t = NULL;
    else
    {
        t = (TreeNode *)malloc(sizeof(TreeNode));
        t->data = ch;
        t->tag = 0;
        t->lchild = NULL;
        t->rchild = NULL;
        createtree(t->lchild);
        createtree(t->rchild);
    }
}
// 非递归的求后序遍历
void back(Tree t)
{
    // 定义一个存储二叉树结点的数组栈，结点名就是指针
    struct TreeNode *stack[100];
    int top = -1;
    TreeNode *p = t;
    // p指针指向不为空或栈不为空时
    while (p || top != -1)
    {
        if (p)
        {
            stack[++top] = p;
            p = p->lchild;
        }
        else
        {
            p = stack[top];
            // 如果结点存在右孩子且未被访问过，则将右孩子进栈
            if (p->rchild && p->rchild->tag == 0)
            {
                p = p->rchild;
            }
            else
            {
                // 不存在左孩子又不存在右孩子，则将p弹出，对p访问
                p = stack[top--];
                cout << p->data << " ";
                p->tag = 1;
                // p指向的结点被访问后，将p结点置为NULL
                p = NULL;
            }
        }
    }
}
int main()
{
    Tree t;
    createtree(t);
    back(t);
    return 0;
}
