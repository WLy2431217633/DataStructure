#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;

// ------ 王道 代码 队列的顺序存储结构
#define Maxsize 50
typedef struct SqQueue
{
    ElemType data[Maxsize];     // 存放队列元素
    int front, rear;            // 队头指针和队尾指针
};
