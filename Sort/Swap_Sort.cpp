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

// ------- PPT 代码 冒泡排序 ---------
void Bubble_Sort(SqList &L)
{
    for (int i = 1, change = TRUE; i < L.length && change; ++i)
    {
        change = FALSE;
        for (int j = 1; j < L.length - i + 1; ++j)
        {
            if (L.r[j].key > L.r[j+1].key)
            {
                L.r[0] = L.r[j];
                L.r[j] = L.r[j+1];
                L.r[j+1] = L.r[0];
                change = TRUE;
            }
            
        }
        
    }
    
}


// ------ PPT 代码 快速排序中的一趟划分算法 ---------
int Partition(SqList &L, int low, int high)
{
    // 交换顺序表L中子表L.r[low……high]的记录，使枢轴记录到位，并返回其所在的位置
    // 此时，在它之前的记录均不大（小）于它
    L.r[0] = L.r[low];
    int pivotkey = L.r[0].key;
    while (low < high)
    {
        // 高端的值比枢轴的值要大
        while (low < high && L.r[high].key >= pivotkey)
        {
            high--;               
        }           
        // 高端的值比枢轴的值要小时
        L.r[low] = L.r[high];     // 将比枢轴小的值移到低端

        // 高端的值比枢轴的值要小   
        while (low < high && L.r[high].key <= pivotkey)
        {
            low++;                  
        }
        L.r[high] = L.r[low];      // 将比枢轴大的值移到高端
    }
    L.r[low] = L.r[0];             // 枢轴放回该插入的位置
    return low;                    // 分界点
}

// ------ PPT 代码 对L.r[low]～L.r[high]的元素进行快速排序 ---------
void Quick_Sort(SqList &L, int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partition(L, low, high);   // 一趟划分
        Quick_Sort(L, low, pivotloc-1);
        Quick_Sort(L, pivotloc + 1, high); 
    }
    
}