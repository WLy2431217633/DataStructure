#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
ElemType *p, *q;

// -------- PPT代码 结构定义---------
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct 
{
		ElemType *base;  // 栈底指针，栈构造前和销毁后为空
		ElemType *top;   // 栈顶指针，指向栈顶元素的下一位置
        // 另一种定义
		// int top;
		int stacksize;   // 当前分配的栈的存储空间数
}SqStack;

// // ------- 王道代码 顺序栈结构体定义 -----
// #define MaxSize 50           // 定义栈中元素的最大个数
// typedef struct SqStack
// {
//     ElemType data[MaxSize];  // 存放栈中元素
//     int top;                 // 栈顶指针
// };

// ------ 王道代码 链栈存储类型 结构体定义 -----
typedef struct Linknode
{
    ElemType data;         // 数据域
    struct Linknode *next; // 指针域
}*LiStack;



// ------- PPT 代码 顺序栈初始化 ------
Status InitStack(SqStack &S)
{
		// 构造一个空栈
		S.base = (ElemType *)malloc(STACK_INIT_SIZE *sizeof(ElemType));
		if(!S.base)
			exit(OVERFLOW);
		S.top = S.base;
		S.stacksize = STACK_INIT_SIZE;
		return OK;
}// InitStack

// ------- PPT 代码 顺序栈入栈 ------
Status Push(SqStack &S, ElemType e)
{
    // 元素插入栈顶
    if(S.top - S.base >= S.stacksize)  // 栈满,分配新空间
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!S.base)                  // 存储分配失败
            return OVERFLOW;
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    // *S.top++ = e;
    return OK;
}//Push

// ------ 严蔚敏 教材 顺序栈出栈 -------
Status Pop(SqStack &S, ElemType &e)
{
    // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回Ok，否则返回ERROR
    if(S.top == S.base)  // 栈空
        return ERROR;
    e =  *(--S.top);
    return OK;
}//Pop

// ------ 严蔚敏 教材 顺序栈获取栈顶的元素 -------
Status GetTop(SqStack S, ElemType &e)
{
    // 若栈不空，则用e返回元素S的栈顶元素，并返回OK，否则返回ERROR
    if(S.top == S.base) // 栈空
        return ERROR;
    e = *(S.top--);
    return OK;
}// GetTop


// // ------ 王道 代码 栈的初始化 -----
// void InitStack(SqStack &S)
// {
//     S.top = -1;         //初始化栈顶指针
// }

// // ------ 王道 代码 栈 判空 --------
// bool StackEmpty(SqStack S)
// {
//     if (S.top == -1)    // 栈空 
//     {
//         return true;   
//     }
//     else                // 栈非空
//         return false; 
    
// }

// // ------ 王道 代码 入栈 -------
// bool Push(SqStack &S, ElemType x)
// {
//     if (S.top == MaxSize-1)   // 栈满，报错
//     {
//         return false;
//     }
//     S.data[++top] = x;     // 指针先+1，再入栈
//     return true;

//     // if (S.top == MaxSize)   // 栈满，报错  top定义为0时
//     // {
//     //     return false;
//     // }
//     // S.data[top++] = x;     // 指针先入栈，再+1
//     // return true;

// }

// // -------- 王道 代码 出栈 -------
// bool Pop(SqStack &S, ElemType &x)
// {
//     if (S.top == -1)   // 栈空
//     {
//         return false;
//     }
//     x = S.data[S.top--];   // 先出栈，再-1
//     return true;

//     // if (S.top == 0)   // 栈空  top定义为0时
//     // {
//     //     return false;
//     // }
//     // x = S.data[--S.top];   // 先-1，再出栈
//     // return true;
// }

// // -------- 王道 代码 获取栈顶元素 -----
// bool GetTop(SqStack S, ElemType &x)
// {
//     if (S.top == -1)   // 栈空报错
//     {
//         return false;
//     }
//     x = S.data[S.top];  // x记录栈顶元素
//     return true;

//     // if (S.top == 0)   // 栈空报错
//     // {
//     //     return false;
//     // }
//     // x = S.data[S.top--];  // x记录栈顶元素
//     // return true;
    
// }