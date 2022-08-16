// 线性顺序表相关操作实现
#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100   // 线性表存储空间的初始分配量
#define LISTINCREMENT 10     // 线性表存储空间的分配增量
#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
ElemType *p, *q;

// 线性表的顺序表的存储结构
typedef struct
{
    ElemType *elem;  // 存储空间基址
    int length;      // 当前长度
    int listsize;    // 当前分配的存储容量（以sizeof（ElemType）为单位）
}SqList;




// 动态分配建表
Status InitList_Sq(SqList &L);

// 顺序表在 第i个位置 插入e
Status ListInsert_Sq(SqList &L, int i, ElemType e);

// 顺序表在  删除 第i个元素
Status ListDelete_Sq(SqList &L, int i, ElemType &e);

// 线性表 合并
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc);

// compare的关系判断 
int compare(ElemType X, ElemType Y);

// 按值查找 返回L中第1个与e满足关系compare()的数据元素的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType) );

int main()
{
    SqList L;
    InitList_Sq(L);
    // 给链表赋值
    for (int i = 0; i <= 5; i++)
    {
        ListInsert_Sq(L, i, i);
    }

    // 显示插入前的值
    cout << "Insert Before:\n";
    for(int i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl; 
    
    // 插入
    cout <<"Please Input Your Insert possition and num:"<< endl;
    int pos, num;
    cin >> pos >> num;
    cout << endl;
    
    if (ListInsert_Sq(L, pos, num))
    {
        cout << "Insert After:\n";
        for(int i = 0; i < L.length; i++)
            cout << L.elem[i] << " ";   // 显示插入后的值
        cout << endl;
    }
    else
    {
        puts("Insert ERROR");
        exit(-1);
    }
    cout << "Please Input Your Delete possition and num:"<< endl;
    cin >> pos;
    ListDelete_Sq(L, pos, num);
    cout << "Delete After:\n";
    for(int i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;

    cout << "-----Merge----" << endl;
    SqList La, Lb, Lc;
    InitList_Sq(La);
    InitList_Sq(Lb);
    InitList_Sq(Lc);


    cout << "La: ";
    ListInsert_Sq(La, 1, 1);
    ListInsert_Sq(La, 2, 5);
    ListInsert_Sq(La, 3, 8);
    ListInsert_Sq(La, 4, 9);
    ListInsert_Sq(La, 5, 11);

    for(int i = 0; i < La.length; i++)
    {
        cout << La.elem[i] << " ";
    }
    cout << endl;

    cout << "Lb: ";
    ListInsert_Sq(Lb, 1, 2);
    ListInsert_Sq(Lb, 2, 4);
    ListInsert_Sq(Lb, 3, 7);
    ListInsert_Sq(Lb, 4, 10);
    ListInsert_Sq(Lb, 5, 12);
    ListInsert_Sq(Lb, 6, 21);
    for(int i = 0; i < Lb.length; i++)
    {
        cout << Lb.elem[i] << " ";
    }
    cout << endl;

    cout << "Lc: ";
    MergeList_Sq(La, Lb, Lc);
    for(int i = 0; i <= Lc.length-1; i++)
    {
        cout << Lc.elem[i] << " ";
    }
    cout << endl;

    //LocateElem_Sq(La, num, compare);
    cout << "Input La one num :";
    cin >> num;
    cout << "Locate = " << LocateElem_Sq(La, num, compare) << endl;

    system("PAUSE");
    return 0;
}



// 动态分配建表
Status InitList_Sq(SqList &L)
{
    // 构造一个空的线性表L
    // L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));//C语言描述
    L.elem = new ElemType[LIST_INIT_SIZE]; // C++描述
    if(!L.elem) exit(OVERFLOW);            // 存储分配失败
    L.length = 0;                          // 空表长度为0
    L.listsize = LIST_INIT_SIZE;           // 初始存储容量
    return OK;
}// InitList_Sq

// 顺序表在 第i个位置 插入e
Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    // 将元素 e 插入在线性表L 的第 i 个元素位置上
    // i 的合法值 i<=i<=ListLength_Sq(L)+1
    if(i<1 || i > L.length+1) return ERROR;       // i值不合法
    if(L.length >= L.listsize)                    // 当前存储空间已满，增加分配
    {
        int *newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);              // 存储分配失败
        else
        {
            L.elem = newbase;                     // 新基址 
            L.listsize += LISTINCREMENT;          // 增加存储容量
        }            
    }
    q = &(L.elem[i-1]);                       // q为插入位置 ， C语言数组下标从0开始
    for(p = &(L.elem[L.length-1]); p >= q; --p)
        *(p+1) = *p;                          // 插入位置及之后的元素后移
    *q = e;                                   // 插入e
    ++L.length;                               // 表长+1
    return OK;      
}// ListInsert_Sq

// 顺序表在  删除 第i个元素
Status ListDelete_Sq(SqList &L, int i, ElemType &e)
{
    // 在顺序表L中 删除 第i个 元素， 并用 e 返回其值
    // i 的合法值 i<=i<=ListLength_Sq(L)
    if((i < 1) || (i > L.length)) return ERROR;  // i值不合法
    p = &(L.elem[i-1]);                          // p为被删除元素的位置
    e = *p;                                      // 被删除元素赋值给 e
    q = L.elem + L.length-1;                     // 表尾元素位置
    for(++p; p <= q; ++p)
        *(p-1) = *p;                             // 被删除元素之后的元素左移
    --L.length;                                  // 表长减1
    return OK;
    
}// ListDelete_Sq

// 线性表 合并
void MergeList_Sq(SqList La, SqList Lb, SqList &Lc)
{
    // 已知顺序线性表 La 和 Lb 的元素 按值非递减排列
    // 归并 La 和 Lb 得到新的顺序线性表Lc， Lc 的元素也按值非递减排列
    ElemType *pa = La.elem; 
    ElemType *pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    ElemType *pc = Lc.elem = new ElemType[LIST_INIT_SIZE];
    if(!Lc.elem) exit(OVERFLOW);                 // 存储分配失败
    ElemType *pa_last = La.elem + La.length-1;
    ElemType *pb_last = Lb.elem + Lb.length-1;
    while(pa <= pa_last && pb <= pb_last)        // 归并
    {
        if(*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++;         // 插入La的剩余元素
    while(pb <= pb_last) *pc++ = *pb++;         // 插入Lb的剩余元素

}// MergeList_Sq

// compare的关系判断 
int compare(ElemType X, ElemType Y) 
{
	if(X == Y) 
		return TRUE; 
	else
        return FALSE; 
}

// 初始条件：若线性表L已存在，compare()是数据元素判定函数
// 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType) )
{
    // 在顺序线性表L中查找第1个值与e满足 compare() 的元素的位序
    // 若找到，则返回其L中的位序，否则返回0
    int i = 1;
    p = L.elem;
    while (i <= L.length && !(*compare)(*p++, e))
    {
        ++i;
    }
    if(i <= L.length)
        return i;
    else
        return 0;
    
}// LocateElem_Sq