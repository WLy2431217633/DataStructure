#include <iostream>
using namespace std;
#include <limits>

int INFINITY = std::numeric_limits<int>::max();
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

// ------- 辅导书 代码 迪杰斯特拉算法 -------
void Dijkstra(Graph G, int v0, int Path[])
{
    int v;
    bool *final = new bool[v];
    int dist[v];
    for (v = 0; v < G.vexnum; v++)
    {
        final[v] = false;                    // 初始化未被访问过的v

        dist[v] = G.arcs[v0][v];             // dist[v]来保存v0到v的权值
        if(dist[v] < INFINITY)
        {
            Path[v] = v0;                    // v可以到达的前驱结点更改为v0
        }
        else
        {
            Path[v] = -1;
        }
    }
    dist[v0] = 0;
    final[v0] = true;                        // 集合S置初值
    for(int i = 0; i < G.vexnum; i++)        // 求其余顶点的最短路径
    {
        int min = INFINITY;
        for (int w = 0; w < G.vexnum; ++w)
        {
            if (final[w] == false)           // 顶点w不在集合S中
            {
                if (dist[w] < min)           // 顶点w离顶点v0更近
                {
                    v = w;
                    min = dist[w];
                } 
                final[v] = true;            // 顶点v0最近的v加入集合S
                for (int w = 0; w < G.vexnum; ++w)   // 更新当前最短路径及距离
                {
                    if (final[w] == false && (min + G.arcs[v][w] < dist[w]))
                    {
                        dist[w] = min + G.arcs[v][w];
                        Path[w] = v;                 // w可以到达的前驱结点更改为v
                    }
                }
            }            
        }
    } 
}