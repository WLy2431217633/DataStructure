#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;

// ------- PPT代码 哈夫曼编码树的存储结构 ---------
typedef struct 
{
    char ch;
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode, HuffmanCode, *HuffmanTree;

HuffmanTree HT;
// HT = new HTNode[2*n];

// ------- PPT代码 哈夫曼编码的求解算法 --------
void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n)
{
    // w存放n个字符的权值，构造哈夫曼树HT，并求出n个字符的编码
    if (n<=1)
    {
        return;
    }
    int m = 2*n-1;
    HT = new HTNode[m+1];
    for(int i = 1; i <= n; i++)
    {
        HT[i].weight = w[i-1];
        HT[i].parent = 0;
        HT[i].lchild = HT[i].rchild = 0;
    }
    for(int i;i<=m; ++i)
    {
        HT[i].parent = 0;
        HT[i].lchild = HT[i].rchild = 0;
    }
    //构造哈夫曼树
    for(int i = n+1; i<=m; i++)
    {

        //从HT[1..i-1]中选择parent为0且weight最小的两个结点，
        //其序号为s1和s2
        int s1, s2;
        Select(HT, i-1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

}//HuffmanCoding



// ------ PPT代码 创建哈夫曼编码 ------
void CreateHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n)
{
    //从叶子到根逆向求每个字符的哈夫曼编码
    // HuffmanCode HC = new char*[n+1];    //分配存储n个字符编码的编码表空间    //(char **)malloc((n+1)*sizeof(char*))
    
    char *cd = new char[n];
    cd[n-1] = '\0';
    for(int i=1; i<=n; i++)
    {
        int start = n-1;
        for(int c=i;int f=HT[i].parent; f!=0, c=f, f=HT[f].parent)
        {
            if (HT[f].lchild == c)
            {
                cd[--start] = '0';
            }
            else
                cd[--start] = '1';
            
        }
        // HC[i] = new char[n-start];
        // strcpy(HC[i], &cd[start]);
    }
    // delete cd[];
}//CreateHuffmanCode


void Select(HuffmanTree HT, int len, int &s1, int &s2);  //选择两个无双亲条件下权数最小的下标 

//将二进制编码翻译回信息原文，m是树根的编号
void Decoding(HuffmanTree HT, int m, char *buff)
{
    int p = m;
    while (*buff != '\0' && p != 0)
    {
        if ((*buff)=='0')
        {
            p = HT[p].lchild;    // 进入左分支
        }
        else
            p = HT[p].rchild;    // 进入右分支
        buff++;
        if (!HT[p].lchild && !HT[p].rchild)  // 进入叶子结点
        {
            cout << HT[p].ch;
            p = m;             // 重新从树根出发进行译码
        }
    }
}//Decoding	 
