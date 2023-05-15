/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 10:01:02
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 10:27:09
 * @FilePath: \wangdao-datastructure\chapter03\3.2.2.cpp
 * @Description: Q是一个队列，S是一个空栈，实现将队列中的元素逆置的算法
 * 思路：先入队再出队进栈，栈满后出栈再入队
 */
#include <iostream>
using namespace std;
#define Maxsize 10
// 采用循环队列
typedef struct
{
    int data[Maxsize];
    int f, r, tag;
} squeue;
typedef struct
{
    int data[Maxsize];
    int top;
} stack;
bool enterqueue(squeue &s, int x)
{
    // 判断队列是否满
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满，进队失败" << endl;
        return false;
    }
    // 队尾出队
    s.tag = 1;
    s.data[s.r] = x;
    s.r = (s.r + 1) % Maxsize;
    return true;
}
int outqueue(squeue &s)
{
    // 判断队列是否空
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空，出队失败" << endl;
        return 0;
    }
    // 队头出队
    s.tag = 0;
    int x = s.data[s.f];
    s.f = (s.f + 1) % Maxsize;
    return x;
}
bool enterstack(stack &s, int x)
{
    // 判断栈是否满
    if (s.top == Maxsize - 1)
    {
        cout << "栈满，进栈失败" << endl;
        return false;
    }
    // 进栈
    s.data[++s.top] = x;
    return true;
}
int outstack(stack &s)
{
    // 判断栈是否空
    if (s.top == -1)
    {
        cout << "栈空，出栈失败" << endl;
        return 0;
    }
    int x = s.data[s.top--];
    return x;
}
int main()
{
    squeue s1;
    s1.f = 0, s1.r = 0, s1.tag = 0;
    stack s2;
    s2.top = -1;
    // 入队
    for (int i = 0; i < Maxsize; i++)
    {
        enterqueue(s1, i);
    }
    // 逆转
    // 将队列每个元素出队再入栈
    for (int i = 0; i < Maxsize; i++)
    {
        int x = outqueue(s1);
        cout << x << " ";
        enterstack(s2, x);
    }
    cout << endl;
    // 将栈每个元素出栈再入队
    for (int i = 0; i < Maxsize; i++)
    {
        int x = outstack(s2);
        enterqueue(s1, x);
    }
    // 输出队列
    for (int i = 0; i < Maxsize; i++)
    {
        int x = outqueue(s1);
        cout << x << " ";
    }
    return 0;
}
