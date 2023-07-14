#include <iostream>

typedef char ElemType;

enum Status
{
    OK = 1,
    ERROR = 0,
};

typedef struct LNode
{
    ElemType elem;
    LNode *next;
} *LinkList;


Status InitList_L(LinkList &L)
{
    L = new LNode;
    L->next = nullptr;
    return OK;
}

int IsEmpty(LinkList &L)
{
    if (L->next)
    {
        //非空
        return 0;
    }
    else
        return 1;
}

Status DestoryList_L(LinkList &L)
{
    LNode *P = nullptr;
    while(L)
    {
        P = L;
        L = L->next;
        delete P;
        P = nullptr;
    }

    return OK;
}

Status CLearList_L(LinkList &L)
{
    LNode *p = nullptr;
    LNode *q = nullptr;

    p = L->next;
    while(p)
    {
        q = p->next;
        delete p;
        p = q; 
    }

    L->next = nullptr;

    return OK;
}

int LinkLength_L(LinkList &L)
{
    LNode *p;
    p = L->next;
    int i = 0;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i; 
}

int main()
{
    LinkList L;
    InitList_L(L);

    std::cout << LinkLength_L(L) << std::endl;

    CLearList_L(L);
    DestoryList_L(L);

}