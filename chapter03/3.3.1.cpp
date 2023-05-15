/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 10:54:34
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 11:30:04
 * @FilePath: \wangdao-datastructure\chapter03\3.3.1.cpp
 * @Description: 假设一个算术表达式包括圆括号，方括号好花括号3中类型的括号，编写一个算法来
 * 判别表达式中的括号是否配对，以字符'\0'作为算术表达式的结束符
 */
#include <iostream>
using namespace std;
#define Maxsize 10
// 字符类型要多一位存放尾0
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
bool isOk(char *str)
{
    stack s;
    s.top = -1;
    int i = 0;
    char ans;
    while (str[i] != '\0')
    {
        // 1 若是左括号，则进栈
        // 2 若是右括号，栈顶出栈，若出栈结果不等，则退出
        if (str[i] == '(' || str[i] == '{' || str[i] =='[')
            enterstack(s, str[i]);
        else if (str[i] == ')')
        {
            ans = outstack(s);
            if (ans != ')')
                return false;
        }
        else if (str[i] == '}')
        {
            ans = outstack(s);
            if (ans != '}')
                return false;
        }
        else if (str[i] == ']')
        {
            ans = outstack(s);
            if (ans != ']')
                return false;
        }
        // 3 算法结束时，判断栈是否为空
        if (isempty(s))
            return true;
        return false;
    }
}
int main()
{
    //?
    char *str = (char *)"()[](}{}()";
    cout << str << endl;
    if (isOk(str))
        cout << "括号匹配" << endl;
    else
        cout << "括号不匹配" << endl;
    return 0;
}
