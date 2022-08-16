#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define success 1            // 返回成功
#define FALSE 0              // 返回假
#define MAXSIZE 100          // 最大值
typedef int ElemType;
typedef int Status;

// ------ PPT代码 循环队列结构体 ------
typedef struct 
{
    ElemType *base;               // 初始化的动态分配存储空间
    int front;                    // 头指针，若队列不空，指向队头元素
    int rear;                     // 尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;

// // ------ 王道 代码 队列的顺序存储结构
// #define Maxsize 50
// typedef struct SqQueue
// {
//     ElemType data[Maxsize];     // 存放队列元素
//     int front, rear;            // 队头指针和队尾指针
// };

// ------- PPT代码 初始化循环队列 ------
Status InitQueue(SqQueue &Q)  // 构造一个空队列
{
    //Q.base = new ElemType[MAXSIZE];
    Q.base=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));
    if (!Q.base)
    {
        return OVERFLOW;
    }
    Q.front = Q.rear = 0;   // 队头元素指示Q.front=0 ,队尾元素指示Q.rear=0
    return success;   
}

// // ------ 王道代码 初始化循环队列 -------
// void InitQueue(SqQueue Q)
// {
//     Q.rear = Q.front = 0;  // 初始化 队首、队尾指针
// }

// ------ PPT代码 循环队列入队 ----------
Status EnQueue(SqQueue &Q, ElemType e)
{
    //将元素e插入队列Q的队尾
    if ((Q.rear + 1)%MAXSIZE == Q.front)
    {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXSIZE;
    return OK;
}

// // ------ 王道代码 循环队列入队 -------
// bool EnQueue(SqQueue &Q, ElemType x)
// {
//     if ((Q.rear + 1)%Maxsize == Q.front)   // 堆满
//     {
//         return false;
//     }
//     Q.data[Q.rear] = x;
//     Q.rear = (Q.rear+1)%Maxsize;    // 队尾指针+1取模
//     return true;
    
// }

// ------ PPT代码 循环队列出队 ----------
Status DeQueue(SqQueue &Q, ElemType &e)
{
    //删除队列Q的队头元素并用e带回
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXSIZE;
    return OK;
    
}

// // ------ 王道代码 循环队列出队 ----------
// bool DeQueue(SqQueue &Q, ElemType &x)
// {
//     //删除队列Q的队头元素并用x带回
//     if (Q.front == Q.rear)     
//     {
//         return false;                // 队空报错
//     }
//     x = Q.base[Q.front];
//     Q.front = (Q.front+1) % MAXSIZE;   // 队头指针+1取模
//     return OK;
    
// }

// ------- 严蔚敏 教材 求循环队列长度 ------
int QueueLength(SqQueue Q)
{
    // 返回Q的元素个数，即队列长度
    return (Q.rear-Q.front + MAXSIZE)%MAXSIZE;   // 空出一个闲置单元
}

// ------ 王道代码  循环队列 判空 ------
bool isEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)   // 队空
    {
        return true;
    }
    else
        return false;
    
}