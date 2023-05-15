/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 10:28:36
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 10:28:39
 * @FilePath: \wangdao-datastructure\chapter03\3.2.3.cpp
 * @Description: 利用两个栈S1,S2来模拟一个栈，已知栈的4个运算定义如下
 * Push(S,x);          //将元素s入栈
 * Pop(S,x);           //S出栈并将出栈的值赋给x
 * StackEmpty(S);      //判断栈是否为空
 * StackOverflow(S);   //判断栈是否需为满
 * 如何利用栈的运算来实现该队列的三个运算
 * Enqueue;            //将元素x入队
 * Dequeue;            //出队，并将出队元素存储在x中
 * QueueEmpty;         //判断队列是否为空
 */
#include <iostream>
using namespace std;
#define Maxsize 10
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

int main()
{
    return 0;
}
