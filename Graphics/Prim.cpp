#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
#define success 1            // 返回成功
#define MAXSIZE 100          // 最大值
typedef int ElemType;
typedef int Status;
typedef int VertexType;

#define MAX_VERTEX_NUM 100          // 顶点数目最大值

// --------- PPT代码 数组表示法的类型定义 ---------
#define MaxVnum 50
typedef double AdjMatrix[MaxVnum][MaxVnum];
typedef struct Graph
{
    int vexnum, arcnum;               // 图当前结点的顶点数，弧数
    AdjMatrix arcs;                   // 邻接矩阵
    VertexType  vexs[MAX_VERTEX_NUM]; // 顶点向量
};

Graph G;

//辅助数组closedge，以记录从U到V-U具有最小代价的边。
struct 
{
    int adjvex;                     // //adjvex域存储该边依附的在U中的顶点。 顶点i与顶点k邻接,顶点k已经在U集合中,closedge[i].adjvex=k
    double lowcost;                 // lowcost存储该边上的权               // 顶点i加入U集合时, closedge[i].lowcost=0
}closedge[MAX_VERTEX_NUM];



void MiniSpanTree_PRIM(Graph G, VertexType u)
{
    //用普里姆算法从顶点u出发构造G的最小生成树
    for (int j = 0; j < G.vexnum; ++j)         // 辅助数组初始化
    {
        if (j!=u)
        {
            closedge[j] = {u, G.arcs[u][j]};
        }
    }
    closedge[u].lowcost = 0;                         // 初始化，U={u}
    for (int i = 1; i < G.vexnum; ++i)
    {
        int k = minimum(G);                          //求生成树的下一个顶点k   
        cout << closedge[k].adjvex << G.vexs[k];     // 输出生成树的边
        closedge[k].lowcost = 0;                     // 顶点k并入U集合
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (G.arcs[k][j] < closedge[j].lowcost)
            {
                closedge[j] = {k, G.arcs[k][j]};
            }
        }
    }
}

//找到和顶点u相连(closedge的lowcost域>0)同时和顶点u相连的边的
//权值最小的那个顶点，将其顶点位置记作k
int minimum(Graph &G)
{
    int i, j, k, min;
    for (i = 0; i < G.vexnum; i++)
    {
        if (closedge[i].lowcost>0)
        {
            //假设第一个closedge的lowcost域值大于0的顶点权值最小，记住其下标，同时此层循环结束
            min = i;
            break;
        }
    }
    k = min;
    //从之前找到的假定“权值最小”的顶点之后的顶点开始
    for (j = k+1; j < G.vexnum; j++)
    {
        if (closedge[j].lowcost < closedge[min].lowcost && closedge[j].lowcost>0)
        {
            
        }
        //若某个顶点满足到k的权值比“权值最小”的顶点到k的权值还要小，
        //那么这个顶点是权值最小的顶点
        min = j;
    }
    return min;     //返回到k权值最小的顶点的位置
}