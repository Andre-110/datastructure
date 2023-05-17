/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 17:01:46
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 18:40:23
 * @FilePath: \wangdao-datastructure\chapter05\5.2.5.cpp
 * @Description: 已知一颗二叉树按顺序存储结构进行存储，设计一个算法，求编号为i和j两个
 * 结点的最近的公共祖先结点的值
 */
#include <iostream>
using namespace std;
// 顺序存储只需要数据域，不存在的点置为-1即可
struct Tree
{
    // 编号为0的结点不存在，置为-1
    int data[12] = {-1, 1, 2, 3, -1, 4, -1, 5, -1, -1, -6, -1};
};
int Comm(Tree t, int i, int j)
{
    // 前提是对应编号的结点要存在
    if (t.data[i] != -1 && t.data[j] != -1)
    {
        // 除2取整得到祖先结点，直到两者相等
        while (i != j)
        {
            if (i > j)
                i /= 2;
            else
                j /= 2;
        }
        return t.data[i];
    }
    return -1;
}
int main()
{
    Tree t;
    int ans = Comm(t, 7, 10);
    cout << ans << endl;
    return 0;
}
