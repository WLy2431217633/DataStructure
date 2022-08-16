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
    int vexnum, arcnum;
    AdjMatrix arcs;
};

Graph G;


// ------- PPT代码 邻接表的类型定义 ----------
typedef struct ArcNode
{
    int adjvex;
    double weight;
    struct ArcNode *nextarc;
};

// ------- PPT代码 头结点 --------
typedef struct 
{
    VertexType data;
    ArcNode *firstarc;
}AdjList[MaxVnum];

// ------- PPT代码 表结点 --------
typedef struct AGraph
{
    int vexnum, arcnum;
    AdjList vertices;
};
AGraph G;