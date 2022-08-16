#include <iostream>
#include <stdlib.h>
using namespace std;
const int N = 20;

typedef struct node
{
    // 定义一个双向链表
    int id;
    struct node *next;  // 后继指针
    struct node *pre;   // 前驱指针
} Node, *pNode;

pNode RingConstruct(int n)
{
    int i;
    pNode head, p, q;
    head = (pNode)malloc(sizeof(Node));   // 建立第一个结点
    head->id = 1;                         // 其ID为1
    p = head;
    for(i = 2; i <= n; i++)               // 循环n-1。将剩余的n-1个元素赋值，入队列
    {
        q = (pNode)malloc(sizeof(Node));
        q->id = i;
        p->next = q;
        q->pre = p;
        p = p->next;
    }
    p->next = head;
    head->pre = p;
    return head;
}

// 传入报数的次数序号，返回此报数的上限
int boundMachine(int order)
{
    int boundList[4] = {3, 5, 7, 13};
    return boundList[(order - 1)%4];
}

// 返回当前趟的起始结点，bound参数由boundMachine提供
pNode count(pNode first, int bound)
{
    pNode q;
    q = first;
    for(int i = 2; i <= bound; i++)
    {
        q = q->next;
    }
    return q;
}

// 将 currentNode 从环中删除，并返回被删除结点的下一结点
pNode removeNode(pNode currentNode)
{
    // 当前删除结点的后继是下一趟的起始结点
    pNode first = currentNode->next;
    currentNode->pre->next = currentNode->next;
    first->pre = currentNode->pre;
    cout << currentNode->id << " ";
    free(currentNode);
    return first;
}

int main()
{
    pNode first;       // first 为每趟的起始结
    pNode toRemove;    // toRemove 为要删除结点，通过函数 removeNode 提供下一趟起始地址
    int i;
    first = RingConstruct(N);
    for(int i = 1; i <= N; i++)
    {
        toRemove = count(first, boundMachine(i));
        first = removeNode(toRemove);
    }
    return 0;
}