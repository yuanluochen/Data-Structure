#include <iostream>

#define MAXLEN 255
#define CHUNKSIZE 80

struct sString
{
    char ch[MAXLEN + 1];
    int length;
};

struct chunk
{
    char ch[CHUNKSIZE];
    chunk *next;
};

//字符串块链结构
struct LString
{
    //串的头尾指针
    chunk *head;
    chunk *tail;

    //串的当前长度
    int curlen; 
};

//串的模式匹配 location

// Brute-Force 算法
int index_BF(sString &s, sString &t)
{
    int i = 1;
    int j = 1;

    while (i <= s.length && j <= t.length)
    {
        if (s.ch[i] == t.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = (i - j + 1) + 1;
            j = 1;
        }
    }

    if (j > t.length)
        return i - t.length;
    else
        return 0;
}
int main()
{
    return 0;
}