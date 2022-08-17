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
    int adjvex;
    double weight;
    struct ArcNode *nextarc;
};

// ------- PPT代码 头结点/顶点 --------
typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode, AdjList[MaxVnum];

// --------- 王道代码 邻接表表示法的类型定义 ---------
// ------- PPT代码 邻接表结点 --------
typedef struct AGraph
{
    int vexnum, arcnum;                // 图的顶点数和弧数
    AdjList vertices;                  // 邻接表
};
AGraph G;