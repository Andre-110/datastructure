/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 11:16:27
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 11:30:21
 * @FilePath: \wangdao-datastructure\chapter03\3.3.2.cpp
 * @Description: 车厢调度，火车调度站的入口处有n节硬座和软座车厢（分别用H和S表示）等待调度
 * 编写算法，输出对这n节车厢进行调度的操作序列（即入栈或出栈操作）序列，使所有软座车厢都能被
 * 调度到硬座车厢之前
 */
#include <iostream>
using namespace std;
#define Maxsize 10
typedef struct
{
    char data[Maxsize + 1];
    int top;
} stack;
bool enterstack(stack &s, char ch)
{
    // 判断栈是否满
    if (s.top == Maxsize - 1)
        return false;
    s.data[++s.top] = ch;
    return true;
}
bool isempty(stack &s)
{
    if (s.top == -1)
        return true;
    return false;
}
char outstack(stack &s)
{
    // 判断栈是否为空
    if (isempty(s))
        return false;
    char x = s.data[s.top--];
    return x;
}
void sort(char str[])
{
    stack s;
    s.top = -1;
    int length = sizeof(str);
    char ans[length + 1];
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'H')
            enterstack(s, str[i]);
        else
            ans[j++] = str[i];
    }
    // 出栈，直至栈空
    while (!isempty(s))
    {
        ans[j++] = outstack(s);
    }
    for (int i = 0; i < length; i++)
    {
        cout << ans[i];
        cout << endl;
    }
}
int main()
{
    //?
    char str[] = "HsHsHHHSHS";
    cout << str << endl;
    sort(str);
    return 0;
}
