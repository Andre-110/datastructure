/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 20:07:34
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 21:27:20
 * @FilePath: \wangdao-datastructure\chapter05\5.3.4.cpp
 * @Description: 给出二叉树的自下而上，自右到左的层次遍历算法
 * 思路：将出队列的进栈
 */
#include <iostream>
using namespace std;

#define Max 10
typedef struct treenode
{
    char data;
    struct treenode *lchild, *rchild;
} treenode, *tree;

typedef struct stack
{
    struct treenode *data[Max];
    int top;
} stack;

typedef struct queue
{
    struct treenode *data[Max];
    int f, r, tag;
} queue;
bool enterqueue(queue &s, treenode *p)
{
    // 判断队是否满
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满" << endl;
        return false;
    }
    s.data[s.r] = p;
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}
int outqueue(queue &s, treenode *&x)
{
    // 判断队是否空
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空" << endl;
        return 0;
    }
    x = s.data[s.f];
    s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}
bool isempty(stack s)
{
    if (s.top == -1)
        return true;
    return false;
}
bool isfull(stack s)
{
    if (s.top == Max - 1)
        return true;
    return false;
}
bool enterstack(stack &s, treenode *p)
{
    // 判满
    if (isfull(s))
    {
        cout << "栈满" << endl;
        return false;
    }
    s.data[++s.top] = p;
    return true;
}
// 指向结点的指针的引用
int outstack(stack &s, treenode *&p)
{
    // 判空
    if (isempty(s))
    {
        cout << "栈空" << endl;
        return 0;
    }
    p = s.data[s.top--];
    return 1;
}
// 前序构造二叉树
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
        t->lchild = NULL;
        t->rchild = NULL;
        buildtree(t->lchild);
        buildtree(t->rchild);
    }
}
void solve(tree t)
{
    stack s;
    s.top = -1;
    queue q;
    q.f = q.r = q.tag = 0;
    // 接收出栈元素
    treenode *p;
    if (t)
    {
        // t为根节点
        enterqueue(q, t);
        // 当队列不为空时
        while (!(q.f == q.r && q.tag == 0))
        {
            outqueue(q, p);
            // 进栈
            enterstack(s, p);
            // 将左右孩子进队列
            if (p->lchild)
                enterqueue(q, p->lchild);
            if (p->rchild)
                enterqueue(q, p->rchild);
        }
        // 弹至栈空
        while (!isempty(s))
        {
            outstack(s, p);
            // 访问
            cout << p->data << " ";
        }
    }
}
int main()
{
    tree t;
    buildtree(t);
    solve(t);
    return 0;
}
