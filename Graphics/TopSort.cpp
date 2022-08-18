#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
typedef int VertexType;

// --------- PPT代码 数组表示法的类型定义 ---------
#define MaxVnum 50
typedef double AdjMatrix[MaxVnum][MaxVnum];
typedef struct Graph
{
    int vexnum, arcnum;         // 图当前结点的顶点数，弧数
    AdjMatrix arcs;
};

Graph G;


// ------- PPT代码 邻接表的类型定义 ----------
typedef struct ArcNode
{
    int adjvex;                        // 该弧所指向的顶点的位置
    double weight;                     // 权重
    struct ArcNode *nextarc;           // 指向第一条依附该顶点的弧的指针
};

// ------- PPT代码 头结点/顶点 --------
typedef struct VNode
{
    VertexType data;                   // 顶点信息
    ArcNode *firstarc;                 // 指向第一条衣服该顶点的弧的指针
}VNode, AdjList[MaxVnum];

// --------- 王道代码 邻接表表示法的类型定义 ---------
// ------- PPT代码 邻接表结点 --------
typedef struct AGraph
{
    int vexnum, arcnum;                // 图的顶点数和弧数
    AdjList vertices;                  // 邻接表
};
AGraph G;

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



// ---------- PPT代码 + 王道 拓扑排序算法 ----------
bool TopologicalSort(AGraph G)
{
    int i = 0;
    SqStack S;
    ArcNode *p;
    InitStack(S);                      // 初始化栈，存储入度为0的顶点
    int Indegree[G.vexnum]={0};        // 临时存储各顶点的入度
    for(i = 0; i < G.vexnum; i++)  // 扫描邻接表，计算各顶点的入度
        for(p = G.vertices[i].firstarc; p; p=p->nextarc)
            Indegree[p->adjvex]++;
    for (i = 0; i < G.vexnum; i++)
        if (Indegree[i]==0)
            Push(S,i);                 // 将所有入度为0的顶点进栈
    int count = 0;                     // 计数，记录当前已经输出的顶点数
    while (!isEmptyStack(S))           // 栈不空，则存在入度为0的顶点
    {
        Pop(S, i);                     // 栈顶元素出栈
        i = count++;
        cout << i << endl;             // 输出顶点i
        for (p = G.vertices[i].firstarc;  p; p=p->nextarc)
        {
            int v = p->adjvex;
            if (!(--Indegree[v]))
                Push(S, v);            // 入度为0，则入栈
        }
    }
    if (count < G.vexnum)              // 有向图中有回路
        return false;                  // 拓扑排序失败
    else
        return true;                   // 拓扑排序成功
   
}


// ------ 王道代码  栈 判空 ------
bool isEmptyStack(SqStack S)
{
    if (S.top == S.base)   // 栈空
        return true;
    else
        return false; 
}