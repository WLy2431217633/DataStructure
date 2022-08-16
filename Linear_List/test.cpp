#include<cstdio>
#include<cstdlib> 
#define ElemType int 
#define Status int 
 
using namespace std;
//链表的结构 （数据域和指针域）
typedef struct LNode{
	ElemType data;		//数据域
	struct LNode *next;		//指针域 
}LNode,*LinkList;
 
//初始化
Status InitList(LinkList &L){
	L = new LNode;
	L->next = NULL;
	return 0; 
} 
 
//创建链表 (逆序) 
void CreatList_RL(LinkList &L,int n){
	//逆位序输入n个元素的值，建立带表头结点的单链表L
	InitList(L);	//初始化链表 
	for(int i=0;i<n;i++){	//循环输入元素的值 (逆序) 
		LinkList p = new LNode;		//新建一个结点 
		scanf("%d",&p->data);	//输入元素值 
		p->next = L->next; 		//将当前结点的指针域设置为头结点的指针域
		L->next = p;		//将元素插到表头 
	}
	printf("新建链表成功\n"); 
} 
 
//创建链表 (正序) 
void CreatList_PL(LinkList &L,int n){
	//逆位序输入n个元素的值，建立带表头结点的单链表L
	InitList(L);	//初始化链表 
	LinkList pre = L;	//新建前驱结点并赋值为头结点 
	for(int i=0;i<n;i++){	//循环输入元素的值 (正序) 
		LinkList p = new LNode;		//新建一个当前结点 
		scanf("%d",&p->data);	//输入元素值 
		p->next = NULL;		//新建结点的指针域为空 
		pre->next = p;	//前驱结点的指针域为当前新建的结点的地址（将链表连接起来） 
		pre = p; 	//把pre设为p，作为下一个结点的前驱结点 
	}
	printf("新建链表成功\n"); 
} 
 
//遍历链表
void ListTraverse_L(LinkList L){
	printf("开始遍历链表:\n");
	LinkList p = L->next;	//新建结点p用于枚举元素（指向第一个结点） 
	while(p != NULL){		//当元素存在 
		printf("%d ",p->data);		//获取数据域并打印 
		p = p->next;		//结点后移 
	}
	printf("\n");
} 
 
//获取链表长度
void ListLength_L(LinkList L){
	int count=0; 
	LinkList p = L->next;
	while(p != NULL){
		count++;
		p = p->next; 
	} 
	printf("链表长度为%d\n",count);
}
 
//获取第i个元素的指针域
Status GetElem_L(LinkList L,int i,ElemType e){
	LinkList p = L->next;	//初始化，p用于指向第一个结点
	int j = 1;		//计数器
	while(p && j<i){	//順指针向后查询，直到p指向第i个元素或者p为空 
		p = p->next;
		j++; 
	} 
	if(!p||j>i){
		printf("元素不存在\n");
		return 0; 
	}
	e = p->data; 
	printf("第%d个元素值为%d\n",i,e);
	return 0;
} 
 
//查找L中第一个等于e的元素位序
Status LocateElem_L(LinkList L,ElemType e){
	LinkList p = L->next;	//初始化，p用于指向第一个结点
	int j = 1;		//用于标记位序 
	int flag = 0;		//用于标记是否查找到 
	while(p != NULL){
		if(p->data == e) {
			flag = 1;
			break;
		}
		p = p->next;
		j++;
	} 
	if(flag){
		printf("元素%d的位序为%d\n",e,j);
	}else{
		printf("没有找到该元素\n");	
	}
	return 0;
} 
 
//查找前驱	cur_e不能是第一个元素 
Status PriorElem_L(LinkList L,ElemType cur_e,ElemType pre_e){
	printf("查找%d的前驱\n",cur_e);
	LinkList p = L->next;		//初始化，p用于指向第一个结点
	if(p->data == cur_e){
		printf("第一个元素没有前驱结点\n"); 
		return 0;
	}
	while(p && p->data != cur_e){
		pre_e = p->data;
		p = p->next;
	} 
	printf("%d的前驱是%d\n",cur_e,pre_e);
	return 0;
}
 
//查找后继元素  cur_e不是最后一个元素
Status NextElem_L(LinkList L,ElemType cur_e,ElemType next_e){
	printf("查找%d的后继\n",cur_e);
	LinkList p = L->next;		//初始化，p用于指向第一个结点
	while(p && p->data != cur_e){
		p = p->next;
	} 
	if(p->next == NULL){
		printf("最后一个元素没有后继结点\n"); 
	}else{
		next_e = p->next->data;
		printf("%d的后继是%d\n",cur_e,next_e);
	} 
	return 0;
} 
 
//插入，在链表L中的i位置插入元素e
Status ListInsert_L(LinkList &L,int i,ElemType e){
	LinkList p = L;
	int j = 0;
	while(p && j< i-1){		//寻找i的前一个结点（即i-1个结点） 
		p = p->next;
		j++;
	} 
	if(!p || j>i-1){		//i小于1或者大于表长+1 
		printf("错误，插入位置不正确\n");
		return 0; 
	}
	LinkList s = new LNode;		//生成新结点用于插入 
	s->data = e;		//新结点指针域赋值 
	s->next = p->next;		//插入 
	p->next = s; 
	printf("插入成功\n");
	ListTraverse_L(L); 		//遍历链表 
	return 0;
} 
 
//删除，在L上删除第i个元素并用e返回其值 
Status ListDelete_L(LinkList &L,int i,ElemType e){
	LinkList p = L;
	int j = 0;
	while(p && j< i-1){		//寻找i的前一个结点（即i-1个结点） 
		p = p->next;
		j++;
	} 
	if(!(p->next) || j>i-1){		
		printf("错误，删除位置不正确\n");
		return 0; 
	}
	LinkList q = p->next;	//新建结点，存贮要删除的元素
	p->next = q->next;		//删除，断开与前面的连接 
	e = q->data; 
	delete(q);
	printf("删除的元素为%d\n",e);
	ListTraverse_L(L); 		//遍历链表 
	return 0;  
} 
 
//置空	将顺序表L置为空表 
Status ClearEmpty_L(LinkList &L){
	//将头结点的下一个结点设置文NULL即可 
	if(L->next!=NULL)
		L->next = NULL; 
	printf("置空操作成功\n");
	return 0; 
} 
 
//判断链表是否为空
bool ListEmpty_L(LinkList L){
	if(L->next == NULL){
		printf("链表为空\n");
		return true;
	}else{
		printf("链表不为空\n");
		return false;
	}
}  
 
//销毁链表
Status DestoryList_L(LinkList &L){
	//判断是否为空表 
	LinkList p = L;
	LinkList pre = new LNode; 
	while(p){
		pre = p;
		p = p->next;
		delete(pre);
	} 
	printf("销毁链表成功\n");
	return 0; 
} 
 
 
int main(){
	int n,a,b,c,d,e,f,g,value1,value2,value3,value4;
	LinkList L = new LNode;
	printf("新建一个链表，请输入链表元素个数：");
	scanf("%d",&n);
//	CreatList_RL(L,n);
	CreatList_PL(L,n); 
	ListTraverse_L(L);
	ListLength_L(L);
	printf("请输入需要查找的位序：	");
	scanf("%d",&a);
	GetElem_L(L,a,value1);
	printf("请输入需要查找的元素：");
	scanf("%d",&b);
	LocateElem_L(L,b);
	printf("请输入需要查找的元素(返回其前驱)：");
	scanf("%d",&c);
	PriorElem_L(L,c,value2);
	printf("请输入需要查找的元素(返回其后继)：");
	scanf("%d",&d);
	NextElem_L(L,d,value3);
	printf("请输入需要插入的元素位置和其值：");
	scanf("%d%d",&e,&f);
	ListInsert_L(L,e,f);
	printf("请输入需要删除的元素位置(返回其值)：");
	scanf("%d",&g); 
	ListDelete_L(L,g,value4);
	ListEmpty_L(L); 
	ClearEmpty_L(L);
	ListEmpty_L(L); 
	DestoryList_L(L);
	return 0;
} 