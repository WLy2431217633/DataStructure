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

// ----- PPT代码 直接插入排序算法 从后往前比较 --------
void InsertSort(SqList &L)
{
    for (int i = 2; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i-1].key)              // i与i-1比
        {
            L.r[0] = L.r[i];                        // 小的成哨兵
            L.r[i] = L.r[i-1];                      // 大的往前移
            int j = i - 2;
            for (j; L.r[0].key < L.r[j].key; j--)   // 哨兵与i-2比较
            {
                L.r[j+1] = L.r[j];                  // 后移
            }
            L.r[j+1] = L.r[0];                      // 插入
        }
        
    }
    
}

// ------- PPT 代码 折半插入排序 ---------
void Binary_Insert_Sort(SqList &L)
{
    for (int i = 2; i <= L.length; i++)
    {
        L.r[0] = L.r[i];        // L.r[i]暂存到L.r[0]

        // 二分寻找插入位置
        int low = 1;
        int high = i-1;         // 下标从0~i-1
        while (low <= high)     // 确定插入位置
        {
            int mid = (low+high)/2;
            if (L.r[0].key > L.r[mid].key)
            {
                low = mid + 1;   // 插入位置在高半区中
            }
            else
                high = mid - 1;  // 插入位置在低半区
        }
        
        for (int j = i-1; j >= high+1; j--)        // high+1为插入位置
        {
            L.r[j+1] = L.r[j];                     // 后移元素，留出插空位置
        }
        L.r[high+1] = L.r[0];                       // 将元素插入
    }
}

// -------- PPT 代码 希尔排序 --------
void Shell_Insert_Sort(SqList &L, int dk)           // dk增量
{
    for (int i = dk; i <= L.length; i++)
    {
        if (L.r[i].key < L.r[i-dk].key)            // 各一个增量位置比较
        {
            L.r[0] = L.r[i];                       // L.r[i]暂存入L.r[0]
            int j = i - dk;
            for (j; j > 0 && L.r[0].key < L.r[j].key; j-=dk)
            {
                L.r[j+dk] = L.r[j];                // 寻找插入位置时记录后移
            }
            L.r[j+dk] = L.r[0];                    // 插入
        } 
    }
}

// ------ PPT 代码 按增量序列dlta[0..t-1]进行希尔排序 -----------
void Shell_Sort(SqList &L,int dlta[], int t)  
{
    for (int k = 0; k < t; k++)
    {
        Shell_Insert_Sort(L, dlta[k]);              //一趟增量为dlta[k]的希尔排序
    }
} //ShellSort
