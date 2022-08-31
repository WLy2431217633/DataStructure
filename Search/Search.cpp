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

// --------- PPT代码 二分（折半）查找算法 ---------
int Binary_search(SSTable ST, KeyType key)
{
    // 在有序表中查找元素e，若查找成功，则返回元素在表中的位置
    // 否则返回0
    int low = 1;
    int high = ST.length;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (ST.elem[mid].key == key)
        {
            return mid;                      //查找成功
        }
        else if (key < ST.elem[mid].key)
        {
            high = mid - 1;                  //下一次到前半区查找
        }
        else
            low = mid + 1;                   //下一次到后半区查找 
    }
    return 0;                                //查找失败
}


// ------- PPT代码 二叉树的链式存储 -------
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *Lchild, *Rchild;
}BiTNode, *BiTree;

// --------- PPT代码 二叉排序树查找算法  ---------
BiTree SearchBST(BiTree T, KeyType key)
{
    //在T指向根的二叉排序树中递归地查找关键字等于key的数据元素，
    //若找到，返回指向该结点的指针，否则返回NULL
    if (T == NULL)
        return NULL;
    else if (T->data.key == key)
    {
        return T;
    }
    else if (key < T->data.key)
    {
        return SearchBST(T->Lchild, key);
    }
    else
        return SearchBST(T->Rchild, key);
}//SearchBST

// ---------- PPT代码 二叉排序树的插入算法 ----------
Status InsertBST(BiTree &T, ElemType e)
{
    // 当二叉排序树中不存在关键字等于e.key的数据元素时，
    // 插入元素e并返回true，否则返回false
    BiTNode *p = T;
    BiTNode *father = NULL;
    while (p && p->data.key != e.key)
    {
        if (e.key > p->data.key)
        {
            p = p->Rchild;
        }
        else
            p = p->Lchild;
    }
    if (p)  //键值为e.key的结点已经存在
    {
        return false;
    }
    BiTNode *s = new BiTNode;
    s->data = e;
    s->Lchild = s->Rchild = NULL;
    if (father == NULL)
    {
        T = s;              // 新建结点为根结点
    }
    else if (e.key > father->data.key)
    {
        father->Rchild = s;
    }
    else
        father->Lchild = s;
}