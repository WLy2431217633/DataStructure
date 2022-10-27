#include <iostream>
using namespace std;

#define OVERFLOW -2          // 溢出
#define OK 1                 // 返回真
#define ERROR 0              // 返回假
#define TRUE 1               // 返回真
#define FALSE 0              // 返回假
typedef int ElemType;
typedef int Status;

// 使用数组存储串
#define MaxStrLength 256
// typedef char sstirng[MaxStrLength];
// sstirng s;                 // 可容纳255个字符

typedef struct
{
    char ch[MaxStrLength];
    int length;
}Sstring, SqString;

// ------ 严蔚敏 教材代码 串的堆分配存储表示 ------
 typedef struct 
 {
    char *ch;        // 若是非空串，则按串长分配存储区，否则ch为NULL
    int length;      // 串长
 }HString;



// // 求子串 SubString(&Sub,S,pos,len)
// Status SubString(Sstring &Sub, Sstring S, int pos, int len)
// {
//     // 求串S从第pos个字符起长度为len的子串Sub
//     if(pos<1 || pos>S.length || len<0 || len>S.length-pos+1) 
//         return  ERROR;
//     Sub.ch[0…len-1] = S.ch[pos-1…pos+len-1];
//     Sub.length = len;
// }

// 朴素的串匹配算法 i = 1, j = 1时
int Index(SqString S, SqString P)
{
    // 返回子串P在主串S中的位置
    int i = 1, j = 1;     // i和j也可能从0开始，依赖于存储设计
    while (i <= S.length && j<= P.length)
    {
        if (S.ch[i] == P.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i-j+2;   // (i-(j-1))+1 
    /*(j-1)可以理解为：模式串已经和主串匹配的字符个数。
        程序的目标：使得当前指针i的位置想要回溯到开始时i的位置的下一位。
        先来说说（j-1）的逻辑：
        已知：当前指针i的位置；
        已知：匹配移动了多少个字符；
            可求：指针i移动前的起始位置        
            比如说起始位置是1，已经匹配成功了3个字符，那现在指针i是不是指向了4，1+3=4，对吧？

            那现在知道位置是4了，也知道匹配成功3个了，那是不是能反过去求起始位置1了？ 所以i-(j-1)干的就是这么个事！

        4.  最后加一是怎么一回事呢？想想我们的目标是啥，是不是要到下一位去，那可不得加1嘛。*/
            j = 1;
        }
        if (j>P.length)
        {
            return (i-P.length);  // 匹配成功
            return -1;            // 匹配失败
        }
        
    }
    
}

// 朴素的串匹配算法 i = 0, j = 0时
int Index(SqString S, SqString P)
{
    // 返回子串P在主串S中的位置
    int i = 0, j = 0;     // i和j从0开始，依赖于存储设计
    while (i < S.length && j< P.length)
    {
        if (S.ch[i] == P.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i-j+1;   
            j = 0;
        }
        if (j==P.length)
        {
            return (i-P.length);  // 匹配成功
            return -1;            // 匹配失败
        }
        
    }
    
}

// 朴素的串匹配算法 i = 0, j = 0时
int Index(SqString S, SqString P, int pos)
{
    //返回模式串P在主串S中从第pos个字符开始的位置
    //要求P非空，1≤ pos ≤Strlength(S)
    int i = pos, j = 0;     // i和j从0开始，依赖于存储设计
    while (i < S.length && j< P.length)
    {
        if (S.ch[i] == P.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i-j+1;   
            j = 0;
        }
        if (j>=P.length)
        {
            return (i-P.length);  // 匹配成功
        }
        return -1;            // 匹配失败
        
    }
    
}

// KMP算法
int Index_KMP(Sstring S, Sstring P, int pos)
{
    // 返回子串T在主串S中从第pos个字符开始的位置
    // 要求T非空，1≤pos ≤Strlength(S)
    int i = pos, j = 1;
    while (i<=S.length && j<=P.length)
    {
        if (j==1 || S.ch[i] == P.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {   //下面相当于 j = next[j]
            i = i-j+2;      // 朴素模式匹配
            j = 1;
        }
    }
    if (j > P.length)
    {
        return (i-P.length);
    }
    return 0;  
}

// ------- 严蔚敏 教材 KMP算法 ---- 似乎数组边界判断有问题 
int Index_KMP_PPT(Sstring S, Sstring T, int pos, int next[])
{
    // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法。
    // 其中，T非空，1<=pos<=StrLength(S)
    int i = pos;
    int j = 1;
    while (i<=S.ch[0] && j<=T.ch[0])
    {
        if (j==0 || S.ch[i] == T.ch[j])   // 继续比较后继字符
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j>T.ch[0])
    {
        return i-T.ch[0];
    }
    else
        return 0;    
}

// KMP模式匹配算法---求next[j]的算法：
int Get_Index(Sstring P, int next[])
{
    // 求模式串P的next函数值并存入数组next
    int i = 1;
    next[1] = 0;
    int j = 0;
    while (i <= P.length)
    {
        if (j==0 || P.ch[i]==P.ch[j])
        {
            ++i;                     // 继续比较后继字符
            ++j;
            next[i] = j;            
        }
        else
            j = next[j];            // 模式串向右移动
        
    }
    
} // GetIndex

// KMP模式匹配算法---求next[j]的改进算法： nextval算法
void Get_nextval(Sstring P, int nextval[])
{
    // 求模式串P的next函数值并存入数组nextval
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    while (i <= P.length)
    {
        if (j==0 || P.ch[i]==P.ch[j])
        {
            ++i;
            ++j;
            if (P.ch[i]!=P.ch[j])
            {
                nextval[i] = j; 
            }
            else
                j = nextval[j];
        }
    }
} // Get_nextval
