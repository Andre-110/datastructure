/*
 * @Author: Andre-110 2889932594@qq.com
 * @Date: 2023-05-15 13:31:56
 * @LastEditors: Andre-110 2889932594@qq.com
 * @LastEditTime: 2023-05-15 14:23:44
 * @FilePath: \wangdao-datastructure\chapter03\3.3.4.cpp
 * @Description: 某汽车轮渡口，每次10辆车过江，分为客车类和货车类，规则如下
 * 同类车先到先上船，客车优先于货车上船，且每上4辆客车，才允许上一辆货车
 * 若等待客车不足4辆，则以货车代替。若无货车等待，则允许客车都上船
 * 思路：
 */
#include<iostream>
using namespace std;
#define Maxsize 10
typedef struct{
    int data[Maxsize];
    int f,r,tag;
}queue;
bool isempty(queue s){
    if(s.r==s.f&&s.tag==0) return true;
    return false;
}
bool isfull(queue s){
    if(s.f==s.r&&s.tag==1) return true;
    return false;
}
bool enterqueue(queue s,int x){
    //判断队列是否满
    if(isfull(s)) return false;
    //从队尾插入
    s.data[s.r]=x;
    s.r=(s.r+1)&Maxsize;
    s.tag=1;
    return true;
}
int outqueue(queue s){
    //判断队列是否空
    if(isempty(s)) return false;
    //从队头弹出
    int x = s.data[s.f];
    s.f=(s.f+1)%Maxsize;
    s.tag=0;
    return true;
}
void sort(){
    //q表示最终队列，q1表示客车队列,q2表示货车队列
    queue q,q1,q2;
    //设置队列初始值
    q.f=q.r=q.tag=0;
    q1.f=q1.r=q1.tag=0;
    q2.f=q2.r=q2.tag=0;
    //给队列赋初值
    for(int i=0;i<Maxsize;i++){
        enterqueue(q1,1);
        enterqueue(q2,1);
    }
    //定义两个计数变量，分别轮次内客车上车数量和总上车数量
    int i=0,j=0;
    //定义变量，存放出队的值
    int x;
    while(j<10){
        //如果轮次内客车登车数量小于4且客车队列不为空，则客车出队并登车
        if(!isempty(q1)&&i<4){
            x = outqueue(q1);
            enterqueue(q,x);
            //计数变量需要改变
            i++;
            j++;
        }
        //如果轮次内客车上车数量等于4且此时货车队列不为空，则货车登车一次
        else if(i==4&&!isempty(q2)){
            x = outqueue(q2);
            enterqueue(q,x);
        }
        //其他情况
        //
        else
    }
}
int main(){
    sort();
    return 0;
}

