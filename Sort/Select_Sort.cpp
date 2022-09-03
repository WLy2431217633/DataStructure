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
typedef int KeyType;
typedef int OtherInfoType;


//------PPT代码 顺序表数据结构定义 -------
#define MAXSIZE 20
typedef int Keytype;             // 定义关键字类型为整型
typedef int InfoType; 

typedef struct RedType           // 记录类型
{
    Keytype key;                 // 关键字类型
    InfoType otherinfo;          // 其他数据项
};

typedef struct SqList             // 顺序表类型
{
    RedType r[MAXSIZE+1];         // r[0] 闲置或作为哨兵
    int length;                   // 顺序表长度
};

// ------ PPT 代码 以顺序表作为存储结构的简单选择排序算法 --------
void Select_Sort(SqList &L)
{
    for (int i = 1; i < L.length; i++)
    {
        for (int k = i+1, j = i ; k <= L.length; k++)
        {
            if (L.r[k].key < L.r[j].key)
            {
                j = k;
            }
            if (j != i)
            {
                L.r[0] = L.r[i];
                L.r[i] = L.r[j];
                L.r[j] = L.r[0];
            }
        }
        
    }
    
}


typedef SqList HeapType;             // 堆采用顺序表存储表示

// ------- PPT代码 堆排序 --------
void HeapSort(HeapType &H)
{
    for (int i = H.length/2; i > 0; --i)
    {
        HeapAdjust(H, i, H.length);
    }
    for (int i = H.length; i > 1; -- i)  
    {  
        RedType tmp = H.r[1];//将堆顶记录和当前未经排序子序列H.r[1..i]中最后一个记录相互交换  
        H.r[1] = H.r[i];  
        H.r[i] = tmp;  
  
        HeapAdjust(H, 1, i -1);//将H.r[1..i-1]重新调整为堆
    }
    
}

//  -------- PPT代码 筛选算法 -------------
void HeapAdjust(HeapType &H, int s, int m)
{
    // H.r[s .. m]中除H.r[s].key外均满足堆的定义
    // 调整H.r[s]的关键字，使H.r[s .. m]成为一个小顶堆
    RedType rc = H.r[s];
    for (int j = 2 * s; j <= m; j *= 2) //沿着值较大的孩子节点向下筛选  
    {  
        if (j < m && H.r[j].key > H.r[j+1].key)  
        {  
            ++ j;                       ////j为key较小的记录的下标 
        }  
        if (rc.key < H.r[j].key)  
        {  
            break;//rc应插入在位置s上  
        }  
        H.r[s] = H.r[j];             //较小的孩子结点值换到父结点位置
        s = j;  
    }  
    H.r[s] = rc;                   //插入  rc应插入的位置在s处
}
