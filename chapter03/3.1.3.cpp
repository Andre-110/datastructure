/*
题目
假设以I和O分别表示入栈和出栈操作，判断经过以下序列后的栈是否是合法序列
合法序列：栈的初态和终态是否均为空
*/
#include <iostream>
using namespace std;

bool isOk(char s[])
{
    int num = 0;
    for (int i = 0; i < sizeof(s); i++)
    {
        if (s[i] == 'I')
            num++;
        else
            num--;
        if (num < 0)
            return false;
    }
    if (num != 0)
        return false;
    return true;
}

int main()
{
    char s1[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
    if (isOk(s1))
        cout << "合法" << endl;
    else
        cout << "不合法" << endl;
    return 0;
}