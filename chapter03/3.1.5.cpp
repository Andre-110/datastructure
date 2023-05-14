/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-14 23:15:06
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 00:51:09
 * @FilePath: \wangdao-datastructure\chapter03\3.1.5.cpp
 * @Description:设有两个栈S1,S2都采用顺序栈的方式，并共享一个存储区[0...maxsize-1]
 * 采用栈顶相向，迎面增长的存储方式，设计S1,S2有关入栈和出栈的操作算法
 */
#include <iostream>
using namespace std;
#define Max 50
typedef struct
{
    int data[Max];
    // 两个指针
    int top[2];
} stack1;
stack1 s;
/**
 * @description: 进栈函数
 * @param {int} i 栈的编号
 * @param {int} x 进栈的数
 * @return {int} 返回值为1和-1表示是否成功
 */
int push(int i, int x)
{
    if (i != 0 && i != 1)
    {
        cout << "无栈" << endl;
        return -1;
    }
    if (s.top[1] - s.top[0] == 1)
    {
        cout << "栈满" << endl;
        return -1;
    }
    if (i == 0)
    {
        s.data[++s.top[0]] = x;
    }
    else
    {
        s.data[--s.top[1]] = x;
    }
    return 1;
}
/**
 * @description: 出栈函数
 * @param {int} i 栈的编号
 * @return {int} 出栈的值或-1
 */
int pop(int i)
{
    if (i != 0 && i != -1)
    {
        cout << "无栈" << endl;
    }
    if (i == 0)
    {
        if (s.top[0] == -1)
        {
            cout << "0号栈为空" << endl;
            return -1;
        }
        return s.data[s.top[0]--];
    }
    else
    {
        if (s.top[1] == Max)
        {
            cout << "1号栈栈空" << endl;
            return -1;
        }
        return s.data[s.top[1]++];
    }
}
int main()
{
    // 初始化两个栈指针
    s.top[0] = -1, s.top[1] = Max;
    // 测试给0号栈进栈
    if (push(0, 5) != -1)
        cout << "0号栈进栈成功" << endl;
    int x = pop(0);
    if (x != -1)
        cout << "0号栈出栈成功，出栈元素为:" << x << endl;
    int y = pop(0);
    return 0;
}