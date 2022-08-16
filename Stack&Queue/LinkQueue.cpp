#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
//ElemType *p, *q;

// ------ PPT 代码 单链队列的存储结构定义  --------
typedef struct QNode  // 链表结点类型
{
    ElemType data;         // 数据域
    struct QNode *next;    // next指针
}QNode, *QueuePtr;

typedef struct LinkQueue   // 队列类型
{
    QueuePtr front;        // 队头指针
    QueuePtr rear;         // 队尾指针
};

// typedef struct    // 队列类型
// {
//     QueuePtr front;        // 队头指针
//     QueuePtr rear;         // 队尾指针
// }LinkQueue;   // 第二种写法

// // ------ 王道 代码 单链队列的存储结构定义  --------
// typedef struct    // 链式队列结点
// {
//     ElemType data;
//     struct LinkNode *next;
// }LinkNode;

// typedef struct LinkQueue       // 链队列
// {
//     LinkNode *front, *rear;    // 队列的队头和队尾指针
// };


// -------- PPT 代码 链队列初始化  --------
Status InitQueue(LinkQueue &Q)
{
    // 构造一个空队列Q
    Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q.front)      // 构造失败
    {
        return OVERFLOW;
    }
    Q.front->next = NULL;
    return OK;    
}


// // -------- 王道 代码 链队列初始化  --------
// void InitQueue(LinkQueue &Q)
// {
//     // 构造一个空队列Q
//     Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));  // 建立头结点
//     Q.front->next = NULL;   // 初始化为空   
// }

// -------- PPT 代码 入队 ---------
Status EnQueue(LinkQueue &Q, ElemType e)
{
    // 将元素e插入到队列Q中
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));    //为新结点申请空间
    if (!p)                    // 创建结点失败
    {
        return OVERFLOW;
    }
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

// // -------- 王道 代码 入队 ---------
// void EnQueue(LinkQueue &Q, ElemType x)
// {
//     // 将元素x插入到队列Q中
//     LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));    //为新结点申请空间
//     s->data = x;
//     s->next = NULL;
//     Q.rear->next = s;
//     Q.rear = s;
// }


// -------- PPT 代码 出队 ---------
Status DeQueue(LinkQueue &Q, ElemType &e)
{
    // 若队列不空，则队头元素出队列，用e返回其值，返回OK，否则返回ERROR
    if (Q.rear == Q.front)   // 队空
    {
        return ERROR;
    }
    QueuePtr p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)          // 若原队列中只有一个结点，删除后变空队列
    {
        Q.rear = Q.front;
    }
    free(p);        // 切记释放
    return OK;
}

// // -------- 王道 代码 出队 ---------
// bool DeQueue(LinkQueue &Q, ElemType &x)
// {
//     // 若队列不空，则队头元素出队列，用x返回其值，返回OK，否则返回ERROR
//     if (Q.rear == Q.front)   // 队空
//     {
//         return ERROR;
//     }
//     LinkNode *p = Q.front->next;
//     x = p->data;
//     Q.front->next = p->next;
//     if (Q.rear == p)          // 若原队列中只有一个结点，删除后变空队列
//     {
//         Q.rear = Q.front;
//     }
//     free(p);        // 切记释放
//     return true;
// }

// ------ 严蔚敏 教材 代码 销毁链队列 ------
Status DestroyQueue(LinkQueue &Q)
{
    // 销毁队列Q
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return OK;
}

// ------ 王道 代码 循环队列判空 ------
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return true;
    }
    else
        return false;
    
}
