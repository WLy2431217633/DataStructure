/*
    4.已知一个带头结点的单链表中存储的均为非负整数，每个非负整数均不大于N，头结点指针为head,
    设计一个尽可能高效的算法，讲链表中出现次数最多的元素（不考虑出现次数最多的元素有多个）
    形成一个新的带头结点链表，该链表的头指针仍为head，且新链表中结点复用原来链表的结点，
    并保持原来的位置顺序。结点含data和next

    解题思路
    使用一个数组cnt[N]记录链表中各个数字出现的次数，然后找到cnt[N]中最大的数，
    其下标i即为出现次数最多的元素；再遍历链表，如果等于i则用尾插法插入头指针后面。
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode, *LinkList;

const int N = 65536;
int cnt[N] = {0};
int count_Num = 0;     // 计数

// 尾插法逆序建立带头结点的单链表
void CreateList_R(LinkList &head, int n)
{
    // 建立头结点
    head = (LinkList)malloc(sizeof(LNode));
    head->next = NULL;

    LinkList r = (LinkList)malloc(sizeof(LNode));
    r = head;

    for (int i = 0; i < n; i++)
    {
        LinkList p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
        cin >> p->data;                              // 输入元素值，存入新节点中
        p->next = NULL;
        r->next = p;
        r = p;                                        // 新节点插入到表尾

        cnt[p->data]++; 
    }

    // 找到不同数字输入了多少个
    for (int i = 0; i < N; i++)
    {
        if (cnt[i]!=0)
        {
            count_Num++;
        }
        
    }
    
}

// 找到出现最多的数字
int FindMost_Loc()
{
    int max = 1;
    int loc = 1;
    for (int i = 0; i < N; i++)
    {
        if (cnt[i]!=0 && max <= cnt[i])
        {
            max = cnt[i];
            loc = i;
        }
    }
    cnt[loc] = 0;
    return loc;
    
}

// 按照题目要求新建一个链表
void CreateList_New(LinkList &head, int n)
{
    // 尾插法逆序建立带头结点的单链表
    head->next = NULL;
    LinkList r = new LNode;
    r = head;
    for (int i = 0; i < n; i++)
    {
        LinkList p = new LNode;
        int loc = FindMost_Loc();
        p->data = loc;           // 让最多的数字给新结点
        p->next = NULL;
        r->next = p;
        r = p;                   // 新节点插入到表尾
    }
    
}

int main()
{
    int n; 
    LinkList head;
    cin >> n;
    CreateList_R(head, n);
    CreateList_New(head, count_Num);
    LinkList p = head->next;

    // 遍历新的链表
    while (p)
    {
       cout << p->data << " ";
       p = p->next;
    }
    return 0;
    
}