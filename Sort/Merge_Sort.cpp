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

// 以顺序表作为存储结构
// ---------- PPT代码 两路归并算法 ------------
void Merge(SqList &L, int i, int m, int n)
{
    //引入辅助数组空间temp，有序序列为r[i..m]和r[m+1..n]
    int b = i;
    int j, k;
    SqList temp;
    for (j = m+1, k=1; i <= m && j<=n; ++k)
    {
        if (L.r[i].key < L.r[j].key)
        {
            temp.r[k] = L.r[i++];
        }
        else 
            temp.r[k] = L.r[j++];
    }
    if (i <= m)
    {
        temp.r[k++] = L.r[i++];
    }
    if (i <= n)
    {
        temp.r[k++] = L.r[i++];
    }
    for (i = b, k = 1; i <= n; )
    {
        L.r[i++] = temp.r[k++];
    }

}

// ------ 两路归并排序 递归算法 -----
void MergeSort(SqList &L, int s, int t)
{
    if (s < t)
    {
        // 采用顺序存储结构，对于由下标s~t界定的一个序列，
        // 前半区间为s ~ (s+t)/2，后半区间为 (s+t)/2+1 ~ t
        int m = (s+t)/2;
        MergeSort(L, s, m);
        MergeSort(L, m+1, t);
        Merge(L, s, m, t);            //合并L.r[s]~L.r[m]与L.r[m+1]~L.r[t]
    }
}