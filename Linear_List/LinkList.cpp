// 链表相关操作
#include <iostream>
using namespace std;

#define OK 1                 // 返回真
#define ERROR 0              // 返回假


typedef int ElemType;
typedef int Status;


// 线性表的单链表存储结构
typedef struct LNode
{
    ElemType data;       // 数据域
    struct LNode *next;  // 指针域
}LNode, *LinkList;


// 创建链表 头插法
void CreateList_L(LinkList &L, int n);

// 链表插入元素
Status ListInsert_L(LinkList &L, int i, ElemType e);

// 查找第i位的值
Status GetElem_L(LinkList L, int i, ElemType &e);

// 打印链表
void PrintfLinkList_L(LinkList L);

int main()
{
    
    LinkList L;
    int n, pos, e;
    cout << "Input LinkList number: ";
    cin >> n;
    CreateList_L(L, n);
    cout << "LinkList have elem:" << endl;
    PrintfLinkList_L(L);
    cout << "Input Insert pos and num:";
    cin >> pos >> e;
    ListInsert_L(L, pos, e);
    //PrintfLinkList_L(L);

    //cout << "Input GetElem pos: ";
    //cin >> pos;
    //GetElem_L(L,5,e);
    //PrintfLinkList_L(L);

    return 0;
}

// 创建链表 头插法
void CreateList_L(LinkList &L, int n)
{
    int i;
    LNode *p;
    // 逆位序输入n个元素的值，建立带头结点的单链表L
    // L = (LinkList)malloc(sizeof(LNode)); // 分配
    L = new LNode;
    L->next = NULL;    // 先建立一个带头结点的单链表

    cout << "Input LinkList elem :" << endl;
    for(i = n; i > 0; --i)
    {
        p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
        cin >> p->data;                       // 输入元素值
        p->next = L->next;                    // 插入到表头
        L->next = p;
    }
}// CreateList_L




// 链表插入元素
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    LNode *p;
    LNode *s;
    int j;
    // 带头结点的 单链表L 第i个位置之前 插入元素e
    p = L; 
    j = 0;
    while(p && j < i - 1)    // 寻找第i个结点
    {
        p = p->next;         // 头结点的指针依次后移至i-1位置
        ++j;
    }

    if(!p || j > i-1)        // i小于1或者大于表长+1
        return ERROR;
    // s = (LinkList)malloc(sizeof(LNode));  // 生成新的结点
    s = new LNode;                           // C++写法

    // 插入L中
    s->data = e;                       
    s->next = p->next;
    p->next = s;

    return OK;

}// ListInsert_L

// 查找第i位的值
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p;
    int j;
    // L为带头结点的单链表的头指针
    // 当第i个元素存在时，其值赋给e并返回第一个结点，否则返回ERROR
    p = L->next;                          // 初始化，p指向第一个结点，j为计数器
    j = 1;
    while(p && j < i)                     // 顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i) 
        return ERROR;                     // 第i个元素不存在
    e = p->data;                          // 取第i个元素
    return OK;
}// GetElem_L

// 打印链表
void PrintfLinkList_L(LinkList L)
{
    LinkList temp = L;
    int count = 0;  // 计数器
    while(temp->next)
    {
        temp = temp->next;
        cout << temp->data << " ";
        count++;
    }
    cout << endl;
}
