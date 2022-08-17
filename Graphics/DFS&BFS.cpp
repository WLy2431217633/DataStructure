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


#define MAX_VERTEX_NUM 100          // 顶点数目最大值
bool visited[MAX_VERTEX_NUM];       // 访问标记数组

// ------ PPT+王道代码 DFS深度有限搜索 ------
void DFSTraverse(Graph G)           // 对图G进行深度优先遍历
{
    int v = 0;
    for(v = 0; v < G.vexnum; ++v)
        visited[v] = false;         // 初始化已访问标记数据
    for(v = 0; v < G.vexnum; ++v)   // 从v=0开始遍历
        if (visited[v] == false)
        {
            DFS(G, v);
        }       
}

// -------- PPT+王道代码 从顶点v出发，深度优先遍历图G -------
void DFS(Graph G, int v)
{
    visited[v] = true;
    //FirstNeighbor(G,v)，返回顶点v的第一个邻接点，没有则返回-1 
    // NextNeighbor(G,v,w)，返回以v为根的除了邻接点w外的另一个邻接点 ，没有则返回-1 
    for(int w=FirstNeighbor(G,v); w>0; w=NextNeighbor(G, v, w))
    {
        if (!visited[w])              // w为v的尚未访问的邻接顶点
        {
            DFS(G, w);
        }
        
    }

}


// --------- PPT+王道代码 BFS广度优先遍历算法 ------
void BFSTraverse(Graph G)
{
    for (int v = 0; v < G.vexnum; v++)
        visited[v] = false;                // 访问标记数组初始化
    for (int v = 0; v < G.vexnum; v++)
        if (visited[v] == false)           // 每个连通分量调用一次BFS 
        {
            BFS(G,v);                      // vi未访问过，从vi开始BFS
        }
}

void BFS(Graph G, int v)
{
    visited[v] = true;                   // 对v做已访问的标记
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q,v);                        // 顶点v入队列
    while (!isEmpty(Q))
    {
        DeQueue(Q,v);                    // 顶点v出队列
        for (int w = FirstNeighbor(G,v); w >= 0; w=NextNeighbor(G,v,w))
        { // 检测v所有的邻接点
            if (visited[w] == false)             // w为v的尚未访问的邻接顶点
            {
                visited[w] = true;               // 对w做已访问的标记
                EnQueue(Q, w);                   // 顶点w入队列
            }
        }
         
    }
    
}

int FirstNeighbor(Graph G, int v)
{
	//返回v的第一个邻接点
    for(int i = 0; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i] == 1 && visited[i] == false)
        {
            return 1;                                 // 返回顶点v的第一个邻接点，没有则返回-1 
        }
    }
     return -1;
}

int NextNeighbor(Graph G, int v, int w)
{
	//返回v相对于w的下一个邻接点
    for (int i = w+1; i < G.vexnum; ++i)
    {
        if (G.arcs[v][i] == 1 && visited[i] == false)
        {
            return i;
        }
    }
    return -1;      // 返回以v为根的除了邻接点w外的另一个邻接点 ，没有则返回-1 
    
}



// ------ PPT代码 循环队列结构体 ------
typedef struct 
{
    ElemType *base;               // 初始化的动态分配存储空间
    int front;                    // 头指针，若队列不空，指向队头元素
    int rear;                     // 尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;



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

// ------ PPT代码 循环队列入队 ----------
Status EnQueue(SqQueue &Q, ElemType e)
{
    //将元素e插入队列Q的队尾
    if ((Q.rear + 1) % MAXSIZE == Q.front)
    {
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXSIZE;
    return OK;
}

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