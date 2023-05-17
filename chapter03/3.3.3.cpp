/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 11:30:52
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 12:10:12
 * @FilePath: \wangdao-datastructure\chapter03\3.3.3.cpp
 * @Description: 利用一个栈实现递归函数的非递归计算
 */
#include <iostream>
using namespace std;
#define Max 10
// 定义一个结构体数组，保存n和对应的Pn(x)值
struct stack1
{
    int n;
    double pnx;
} st[Max];
double ans(int n, double x)
{
    int top = -1;
    int i;
    // 定义首项和第二项
    double fv1 = 1, fv2 = 2 * x;
    // 递推项从后往前压入栈中，值为i
    for (int i = n; i >= 2; i--)
    {
        st[++top].n = i;
    }
    while (top >= 0)
    {
        // 递推项从前往后出栈，每个n对应的值为
        st[top].pnx = 2 * x * fv2 - 2 * (st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].pnx;
        top--;
    }
    if (n == 0)
        return fv1;
    return fv2;
}
int main()
{
    double ans1 = ans(3, 1.9);
    cout << ans1 << endl;
    return 0;
}
