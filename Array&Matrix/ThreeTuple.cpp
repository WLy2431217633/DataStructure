#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;

// -------PPT 代码 三元组顺序表------
#define maxsize 10000
typedef int datatype;
typedef struct 
{
    int i, j;
    datatype v;
}triple;  // 三元组

typedef struct
{
    triple data[maxsize];
    int m, n, t;
}tripletable;

// ------- 转置 ---------
void transmatrix(tripletable A, tripletable &AT)
{
    AT.m = A.n;  // 行列互换
    AT.n = A.m;
    AT.t = A.t;  // 对角
    if (AT.t <= 0)
    {
        return;
    }
    for (int p=0; p<A.t; ++p)
    {
        AT.data[p].i = A.data[p].j;  // AT.data[p].i 行号   A.data[p].j  列号
        AT.data[p].j = A.data[p].i;
        AT.data[p].v = A.data[p].v;
    }
    //按照AT.data[p].i进行非递减排序

}

// ------ PPT 代码 三元组顺序表上的转置 -------
void transmatrix(tripletable A, tripletable &AT, int num[], int cpot[])
{
    for(int col = 1; col<=A.n; ++col)
       num[col] = 0;
    for(int p=1; p<=A.t; ++p) // 计算A中每列非零元的个数
        num[A.data[p].j]++;     // 列++
    cpot[1] = 1;
    for(int col = 2; col <= A.n; ++col) // 计算元素位置
        cpot[col]=cpot[col-1]+num[col-1];
    for(int p=1; p<=A.t; ++p) // 转置
    {
        int col = A.data[p].j;
        int q = cpot[col];
        AT.data[q].i = A.data[p].j;
        AT.data[q].j = A.data[p].i;
        AT.data[q].v = A.data[p].v;
        cpot[col]++;
    }
}
