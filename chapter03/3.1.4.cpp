/*
问题
设单链表的表头指针为L,节点结构由data和next两个域构成，其中data为字符型
试设计算法判断该链表的全部n个字符是否中心对称
*/
#include <iostream>
using namespace std;
// 定义结构体
typedef struct lnode
{
    char data;
    struct lnode *next;
} lnode, *linklist;
// typedef struct lnode lnode     定义结构体的别名
// typedef struct lnode *linklist 定义指向结构体的指针的别名
char s1[] = {'a', 'b', 'b', 'b', 'a'};
int n = sizeof(s1);
// 尾插法建立单链表，参数为指向链表的指针，即头指针L
// 强调单链表时，使用linklist
// 强调结点时，使用lnode *
void buildlist(linklist &L)
{
    // 将malloc新建的结点的地址赋给头指针，即让头指针指向头结点
    L = (linklist)malloc(sizeof(lnode));
    // 定义一个空闲指针和一个表尾指针
    lnode *s, *r = L;
    for (int i = 0; i < n; i++)
    {
        // 将空闲指针指向新建立的结点
        s = (lnode *)malloc(sizeof(lnode));
        // 设置数据域
        s->data = s1[i];
        r->next = s;
        // 尾指针后移
        r = r->next;
    }
    // 结尾指向null
    r->next = NULL;
}
bool isOk(linklist L, int n)
{
    // 用数组定义一个栈
    char str[n / 2];
    // 将p指向头结点的下一个结点
    lnode *p = L->next;
    int i = 0;
    for (i = 0; i < n / 2; i++)
    {
        str[i] = p->data;
        p = p->next;
    }
    // 将索引i后移一位，使其指向栈的第一个元素，即数组的最后一个元素
    i--;
    // 若为奇数个，则将p后移，使其指向链表后半部分的第一个结点
    if (n % 2 != 0)
        p = p->next;
    // 当链表到尾时或链表结点值与字符串索引值不相同时退出循环
    while (p && p->data == str[i])
    {
        i--;
        p = p->next;
    }
    if (i == -1)
        return true;
    else
        return false;
}
int main()
{
    // 1.尾插法建立链表
    linklist L;
    buildlist(L);
    // 2.将链表的前半部分取到栈中并判断栈和链表后半部分
    if (isOk(L, n))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}