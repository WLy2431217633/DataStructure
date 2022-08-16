// 链表相关操作
#include <iostream>
using namespace std;

#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define MAXSIZE 1000         // 链表最大长度

typedef int ElemType;
typedef int Status;


// 线性表的单链表存储结构
typedef struct LNode
{
    ElemType data;       // 数据域
    struct LNode *next;  // 指针域
    int cur;             
}LNode, *LinkList, SLinkList[MAXSIZE];


// 创建链表 头插法
void CreateList_L(LinkList &L, int n);

// 链表插入元素
Status ListInsert_L(LinkList &L, int i, ElemType e);

// 查找第i位的值  按位查找
Status GetElem_L(LinkList L, int i, ElemType &e);

// 打印链表
void PrintfLinkList_L(LinkList L);

// 链表删除元素
Status ListDelete_L(LinkList &L, int i, ElemType &e);

// 链表合并
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

// 在静态链表中 查找第1个值为e 的元素  按值查找
int LocateELem_SL(SLinkList S, ElemType e);


int main()
{
    
    LinkList L;
    int n, pos1, pos2, pos3, e1, e2, e3, n1, n2, n3;
    cout << "Input LinkList number: ";
    cin >> n;
    CreateList_L(L, n);
    cout << "LinkList have elem:" << endl;
    PrintfLinkList_L(L);

    //PrintfLinkList_L(L);

    cout << "Input GetElem pos: ";
    cin >> pos1;
    GetElem_L(L,pos1,e1);
    cout << "Delete Elem pos: ";
    cin >> pos2;
    ListDelete_L(L,pos2,e2);
    PrintfLinkList_L(L);

    cout << "Input Insert pos and num:";
    cin >> pos3 >> e3;
    ListInsert_L(L, pos3, e3);
    PrintfLinkList_L(L);

    //SLinkList S;
    cout << "Input LocateELem num: ";
    cin >> n3;
    LocateELem_SL(L, n3);

    LinkList La, Lb, Lc;
    cout << "Input LinkList La number: ";
    cin >> n1;
    CreateList_L(La, n1);
    cout << "Input LinkList Lb number: ";
    cin >> n2;
    CreateList_L(Lb, n2);
    MergeList_L(La, Lb, Lc);
    PrintfLinkList_L(Lc);
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
    j = 1;
    while(p && j < i - 1)    // 寻找第i个结点
    {
        p = p->next;         // 头结点的指针依次后移至i-1位置
        j++;
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

// 查找第i位的值  按位查找
Status GetElem_L(LinkList L, int i, ElemType &e)
{                          
    // L为带头结点的单链表的头指针
    // 当第i个元素存在时，其值赋给e并返回第一个结点，否则返回ERROR
    LinkList p = L->next;                          // 初始化，p指向第一个结点，j为计数器
    int j = 1;
    while(p && j < i)                     // 顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        j++;
    }
    if(!p || j > i) 
    {
        cout << "Elem no exit!" << endl;
        return ERROR;                     // 第i个元素不存在
    }

    e = p->data;                          // 取第i个元素
    cout << "Number: " << i << " is: " << e << endl;
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

// 链表删除元素
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
    LinkList p;
    // 带头结点的单链表L中，删除第i个元素，并由e返回其值
    p = L;
    int j = 0;
    while(p->next && j < i-1)       // 寻找第i个结点，并令p指向其前趋
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i-1)       // 删除位置不合理
        return ERROR;
    LinkList q = new LNode;         // 生成新结点

    // 删除并释放结点
    q = p->next;
    p->next = q->next;     
    e = q->data;
    free(q);
    return OK;


}// ListDelete_L

// 链表合并
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    // 一直单链表La和Lb的元素按值非递减排列
    // 归并La和Lb得到新的链表Lc，Lc的元素也按值非递减排列
    LNode *pa = La->next;
    LNode *pb = Lb->next;     
    LNode *pc;
    Lc = pc = La;             // 用La的头结点作为Lc的头结点
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;   // 插入剩余段
    free(Lb);                  // 释放Lb的头结点
}// MergeList_L


// 在静态链表中 查找第1个值为e 的元素  按值查找
int LocateELem_SL(SLinkList S, ElemType e)
{
    // 若找到，则返回L中的位序，否则返回 0
    int i = S[0].cur;                // i指示表中第一个结点
    while(i && S[i].data != e)
    {
        i = S[i].cur; 
    }       // 表中顺链查找
    cout << "The num is : " << i << endl;
    
    return 0;
} // LocateELem_SL