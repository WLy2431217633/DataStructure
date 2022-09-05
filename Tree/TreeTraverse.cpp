#include <iostream>
#include <algorithm> 
#include<bits/stdc++.h> 
using namespace std;
typedef struct Node
{//定义二叉树结构
    char data;
    struct Node *lchild,*rchild;
}*BiTree,BiTNode; 
void PreTraversel(Node *root) 
{
	stack<BiTNode*>s;
	BiTNode *cur;
//	BiTNode *pre=NULL;
	s.push(root) ;
	while(!s.empty()){
		cur=s.top();
		cout<<cur->data<<" ";  
		s.pop();
//		if((pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
//		{
//			cout<<cur->data<<" ";
//			s.pop();
//			pre=cur;
//		}
			if(cur->rchild!=NULL)
				s.push(cur->rchild);
			if(cur->lchild!=NULL)
				s.push(cur->lchild);
 
	}
}
//非递归中序遍历
void InorderTraversel(BiTNode *root)
{
	BiTNode *cur = root ;
	stack<BiTNode*>s;
//	BiTNode *pre = NULL;
//	s.push(root) ;
	while(!s.empty()||cur != NULL){
		//cur = s.top();
		while(cur)
		{
			s.push(cur);
			cur = cur->lchild;
		}
		if(!s.empty())
		{
			cur = s.top();
			cout<<cur->data<<" ";
			s.pop();
			cur = cur->rchild;
		}
}
}
//非递归后序遍历
void postTraversal(BiTNode *root) {
	stack<BiTNode*>s;
	BiTNode *cur;
	BiTNode *pre=NULL;
	s.push(root) ;
	while(!s.empty()){
		cur=s.top();
		if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
		{
			cout<<cur->data<<" ";
			s.pop();
			pre=cur;
		}
		
		else{
			if(cur->rchild!=NULL)
				s.push(cur->rchild);
			if(cur->lchild!=NULL)
				s.push(cur->lchild);
		}
	}
}
void CreateBiTree(BiTree &T)
{//先序创建二叉树
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void InOrderTraverse(BiTree T)
{//中序遍历
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{//先序遍历
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{//后序遍历
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data;
    }
}
int Depth(BiTree T)
{
	if(T == NULL)
	{
		return 0;
	}
	else return max(Depth(T->rchild),Depth(T->lchild))+1;
} 
int LeafCount(BiTree T)
{
	if(T)
	{
	if(T->lchild == NULL&&T->rchild == NULL)	
	{
		return 1;
	}
	else return LeafCount(T->lchild)+LeafCount(T->rchild);
	}
 
} 
int NodeCount(BiTree T)
{
	if(T == NULL)
	{
		return 0;
	}
	else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
//int Depth(BiTree T)
//{//树的深度
//    if(T==NULL)
//        return 0;
//    else
//    {
//        int m=Depth(T->lchild);
//        int n=Depth(T->rchild);
//        return max(m,n)+1;
//    }
//}
//int NodeCount(BiTree T)
//{//统计二叉树中结点的个数
//    if(T==NULL) return 0;
//    else return NodeCount(T->lchild) + NodeCount(T->rchild)+1;
//}
//
//int LeafCount(BiTree T)
//{//统计二叉树中叶子结点的个数
//if(T)
//{
//	 if(!T->lchild &&!T->rchild){//如果二叉树左子树和右子树皆为空,说明该二叉树根节点为叶子节点,加1.
//        return 1;
//    }else{
//        return LeafCount(T->lchild)+LeafCount(T->rchild);
//    }
//}
   // if(!T) return 0;
   
 
 
 
 
int main()
{
    BiTree T;
    //测试例子AB#CD##E##F#GH###
    cout<<"先序遍历输入(以#结束):";
    CreateBiTree(T);
    PreTraversel(T);
      cout<<endl<<endl;
      InorderTraversel(T);
      cout<<endl<<endl;
    postTraversal(T);
    
    cout<<endl<<endl;
    cout<<"中序遍历输出:";
    InOrderTraverse(T);
    cout<<endl<<"先序遍历输出:";
    PreOrderTraverse(T);
    cout<<endl<<"后序遍历输出:";
    PostOrderTraverse(T);
    cout<<endl<<"树的深度:"<<Depth(T);
    cout<<endl<<"结点的个数:"<<NodeCount(T);
    cout<<endl<<"叶结点的个数:"<<LeafCount(T);
    return 0;
}