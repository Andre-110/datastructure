/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 17:01:46
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 17:05:33
 * @FilePath: \wangdao-datastructure\chapter05\5.2.5.cpp
 * @Description: 已知一颗二叉树按顺序存储结构进行存储，设计一个算法，求编号为i和j两个
 * 结点的最近的公共祖先结点的值
 */
#include<iostream>
using namespace std;
//数据域和？？？
struct Tree{
    int data[12]={-1,1,2,3,-1,4,-1,5,-1,-1,-6,-1};
};
int Comm(Tree t,int i,int j){
    if(t.data[i]!=-1&&t.data[j]!=-1){
        while(i!=j){
            if(i>j) i/=2;
            else j/=2;
        }
        return t.data[i];
    }
    return -1;
}
int main()
{
    Tree t;
    int ans = Comm(t,7,10);
    cout<<ans<<endl;
    return 0;
}

