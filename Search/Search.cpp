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

// ------- PPT代码 静态查找表的存储结构 -------
// 设元素采用顺序存储
typedef  struct 
{
    KeyType  key;
    OtherInfoType  info;
}ElemType;

typedef struct SSTable
{
    ElemType *elem;                // 数据元素存储空间基址，建表时
    int length;                    // 按实际长度分配，0号单元留空
};

// ------ PPT代码 静态顺序表 顺序查找 ----------
int Sq_search(SSTable ST, KeyType key)
{
    // 在无序表中查找元素key，查找成功时，返回元素在表中的位置
    // 否则返回0 
    int i = ST.length;
    while(i>=0 && ST.elem[i].key != key)
        i--;
    return i;
}

// ------ PPT代码 无序表 顺序查找 （需记忆）----------
// 设置监视哨
int Sq_search(SSTable ST, KeyType key)
{
    // 在无序表中查找元素key，查找成功时，返回元素在表中的位置
    // 否则返回0 
    int i = ST.length;
    ST.elem[0].key = key;     // 监视哨，下标为0的位置存放待查找的元素
    while(ST.elem[i].key != key)   // 不等于监视哨则向前移
        i--;
    return i;
}

// ------ PPT代码 有序表 顺序查找 （需记忆）----------
// 设置监视哨
int Sq_search(SSTable ST, KeyType key)
{
    // 在无序表中查找元素key，查找成功时，返回元素在表中的位置
    // 否则返回0 
    int i = ST.length;
    ST.elem[0].key = key;         // 监视哨，下标为0的位置存放待查找的元素
    while(ST.elem[i].key > key)   // 大于监视哨，则向前移
        i--;
    if (key == ST.elem[i].key)
    {
        return i;
    }
    
    return 0;
}