#include <iostream>
#include<stack>           //头文件
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;
typedef int TelemType;
typedef int TElemType;
typedef int PointerTag;

// ------- PPT代码 二叉树的顺序存储 -------
#define MAX_TREE_SIZE 100
typedef TelemType SqBiTree[MAX_TREE_SIZE];
SqBiTree bt;

// ------- PPT代码 二叉树的链式存储 -------
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *Lchild, *Rchild;
}BiTNode, *BiTree;

// ------ PPT代码 先序遍历 --------
void preorder(BiTNode *root) //先序遍历root指向根的二叉树  递归方式
{
    if (root!=NULL)
    {
        cout << root->data;      // 访问根结点
        preorder(root->Lchild);  // 先序遍历根的左子树
        preorder(root->Rchild);  // 先序遍历根的右子树
    } 
}//preorder

// ------ 辅导书代码 非递归先序遍历 --------
void preOrder(BiTNode *root)
{
    stack<BiTNode*> s;
    BiTNode *p;
    s.push(root);
    while (!s.empty())
    {
        p = s.top();
        cout << p->data << " ";
        s.pop();
        if (p->Rchild)
        {
            s.push(p->Rchild);
        }
        if (p->Lchild)
        {
            s.push(p->Lchild);
        }
        
    }
    
}


// ------ PPT代码 中序遍历 --------
void inorder(BiTNode *root) //中序遍历root指向根的二叉树  递归方式
{
    if (root!=NULL)
    {
        inorder(root->Lchild);  // 中序遍历根的左子树
        cout << root->data;      // 访问根结点
        inorder(root->Rchild);  // 中序遍历根的右子树
    } 
}//inorder

// ------ 辅导书代码 非递归中序遍历 --------
void InOrder(BiTree T)
{
    stack<BiTNode*> s;
    BiTNode *p = new BiTNode;
    p = T;                           // 根指针进栈
    BiTNode *q = new BiTNode;
    while (p||!s.empty())
    {
        if (p)
        {
            s.push(p);
            p = p->Lchild;
        }
        else                         // 根指针退栈，访问根结点，遍历右子树
        {
            q = s.top();
            s.pop();
            cout << q->data << " ";
            p = q->Rchild;
        }
    }
}


// ------ PPT代码 后序遍历 --------
void postorder(BiTNode *root) //后序遍历root指向根的二叉树  递归方式
{
    if (root!=NULL)
    {
        postorder(root->Lchild);  // 后序遍历根的左子树
        postorder(root->Rchild);  // 后序遍历根的右子树
        cout << root->data;      // 访问根结点
    } 
}//postorder

// ------ 辅导书代码 非递归后序遍历 --------
void postOrder(BiTNode *root)
{
    stack<BiTNode*>s;
    BiTNode *p;
    BiTNode *pre = NULL;
    s.push(root);
    while (!s.empty())
    {
        p = s.top();
        if ((p->Lchild == NULL && p->Rchild == NULL)|| (pre != NULL && (pre == p->Lchild || pre == p->Rchild)))
        {
            cout << p->data << " ";
            s.pop();
            pre = p;
        }
        else
        {
            if (p->Rchild != NULL)
            {
                s.push(p->Rchild);
            }
            if (p->Lchild != NULL)
            {
                s.push(p->Lchild);
            }
        }
    }
}

// ------- PPT代码 线索二叉树结构体 --------
typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *Lchild, *Rchild;
    PointerTag Ltag, Rtag;
}*BiThrTree, *ThreadTree;

// ------- PPT代码 中序线索二叉树上找指定结点的后继--------
BiThrTree inodernext(BiThrTree p, BiThrTree q)
{
    if (p->Rtag == 1)
    {
        return (p->Rchild);
    }
    else
    {
        q=p->Rchild;
        while (q->Ltag==0)
        {
            q=q->Lchild;
            return q;
        } 
    }   
}

// ------- PPT代码 通过中序遍历对二叉树线索化的递归算法 -------
void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p!=NULL)
    {
        InThread(p->Lchild, pre);  // 递归，线索化左子树
        if (p->Lchild==NULL)       // 左子树为空，建立前驱线索
        {
            p->Lchild=pre;
            p->Ltag=1;
        }
        if (pre!=NULL&&pre->Rchild==NULL)
        {
            pre->Rchild=p;         // 建立前去结点的后继线索
            pre->Rtag=1;   
        }
        pre=p;                      // 标记当前结点成为刚访问过的结点
        InThread(p->Rchild,pre);    // 递归，线索化右子树
    }
    
}

// --------- PPT代码 通过中序遍历建立中序线索二叉树的主过程算法 -------
void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T!=NULL)               // 非空二叉树，线索化
    {
        InThread(T,pre);       // 线索化二叉树
        pre->Rchild=NULL;      // 处理遍历后的最后一个结点
        pre->Rtag=1;
    }
    
}

// -------- 双亲表示类型定义 --------
#define MAX 100
struct node
{
    char data;
    int parent;     // 双亲位置域
};
typedef struct node NODE;
NODE tree[MAX];

// ---------- 孩子兄弟表示法 ---------
struct node
{
    char data;
    struct node *son, *brother;
};



