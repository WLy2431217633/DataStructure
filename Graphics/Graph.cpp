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

int main()
{
// ----------  以邻接表为存储结构，求有向图中顶点的入度。--------
    AGraph G;
    int Indegree[G.vexnum]={0};        //临时存储各顶点的入度
    for(int i = 0; i < G.vexnum; i++)  //扫描邻接表，计算各顶点的入度
        for(ArcNode *p = G.vertices[i].firstarc; p; p=p->nextarc)
            Indegree[p->adjvex]++;
}


