#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
typedef int AtomType;

// ---------PPT代码 广义表扩展性链表存储表示---------
typedef enum{ATOM, LIST} ElemTag;       // ATOM==0; 原子， LIST == 1; 子表
typedef struct GLNode
{
    ElemTag tag;                          // 公共部分，用于区分原子结点和表结点
    union{                                // 原子结点和表结点的联合部分
        AtomType atom;                    // 原子结点的值域
        struct{struct GLNode *hp, *tp;}ptr;  // 表结点的表头指针，tp相当于next指向下一个元素结点
    };
}*Glist;              // 广义表类型GList是一种扩展性的先行链表

// ---------PPT代码 广义表扩展性链表另一种结点结构---------
typedef enum{ATOM, LIST} ElemTag;       // ATOM==0; 原子， LIST == 1; 子表
typedef struct GLNode
{
    ElemTag tag;                          // 公共部分，用于区分原子结点和表结点
    union{                                // 原子结点和表结点的联合部分
        AtomType atom;                    // 原子结点的值域
        struct GLNode *hp;                // 表结点的表头指针
    };
     struct GLNode *tp;                    // tp相当于next指向下一个元素结点
}*Glist;              // 广义表类型GList是一种扩展性的先行链表