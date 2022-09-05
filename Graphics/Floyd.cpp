#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
#define MAX 100
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

// ------- 辅导书 代码 弗诺伊德算法 -------
void Floyd(Graph G, int Path[][MAX])
{
    int v, w;
    int dist[MAX][MAX];
    for (v = 0; v < G.vexnum; v++)      // 初始化
    {
        for (w = 0; w < G.vexnum; w++)
        {
            dist[v][w] = G.arcs[v][w];     // dist[v][w]用来保存v到w的权值
            Path[v][w] = w;                // v可以到达的后继结点更改为w
        }
    }
    for (int u = 0; u < G.vexnum; u++)
    {
        for (v = 0; v < G.vexnum; v++)
        {
            for (w = 0; w < G.vexnum; w++)
            {
                if (dist[v][u] + dist[u][w] < dist[v][w] && v != w)
                {
                    dist[v][w] = dist[v][w] + dist[u][w];     // dist[v][w]来保存v到u，u到w的权值
                    Path[v][w] = Path[v][u];                  // v可以到达的后继结点更改为u
                }
            }
        }
    }
}