/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 00:27:35
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 09:43:58
 * @FilePath: \wangdao-datastructure\chapter03\3.2.1.cpp
 * @Description: 若希望循环队列中的元素都能得到利用，需设置一个标志域tag，并以tag的值为0或1
 * 来区分队头指针front和队尾指针rear相同时的队列状态是空还是满，试编写与此结构相应的入队和出队算法
 */
#include <iostream>
using namespace std;
#define Maxsize 10
typedef struct
{
    int data[Maxsize];
    int f, r, tag;
} squeue;
// 每次入队都把tag更新为1
bool enters(squeue &s, int x)
{
    // 判断队满
    if (s.f == s.r && s.tag == 1)
    {
        cout << "队满，入队失败" << endl;
        return false;
    }
    // 入队
    s.data[s.r] = x;
    s.r = (s.r + 1) % Maxsize;
    s.tag = 1;
    return true;
}
// 每次出队把tag更新为0
int outs(squeue &s)
{
    // 判断队空
    if (s.f == s.r && s.tag == 0)
    {
        cout << "队空，出队失败" << endl;
        return 0;
    }
    // 出队
    int x = s.data[s.f];
    s.f = (s.f + 1) % Maxsize;
    s.tag = 0;
    return x;
}
int main()
{
    // 初始化一个循环队列
    squeue s;
    s.f = 0, s.r = 0, s.tag = 0;
    // 入队
    for (int i = 0; i < 10; i++)
    {
        enters(s, i);
    }
    // 再次入队测试队满
    enters(s, 10);
    // 输出队列
    for (int i = 0; i < 10; i++)
    {
        cout << outs(s) << " ";
    }
    // 再次出队测试队空
    outs(s);
    return 0;
}
