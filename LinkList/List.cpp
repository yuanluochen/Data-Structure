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

LNode *LocateList_L(LinkList &L, ElemType e)
{
    LNode *p = nullptr;
    p = L->next;
    
    while(p && p->elem != e)
        p = p->next;

    return p;
}

int LocateElem_L(LinkList &L, ElemType e)
{
    LNode *p = nullptr;
    p = L->next;
    int j = 0;
    while(p && p->elem != e)
    {
        p = p->next;
        ++j;
    }
    if (p)
        return j;
    else    
        return 0;
}

Status GetElem_L(LinkList &L, int i, ElemType e)
{
    int j = 0;
    LNode *p = nullptr;
    p = L->next;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
        return ERROR;
    
    e = p->elem;
    return OK;

}

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
    LNode *p = L;
    int j = 0;

    while(p && j < i - 1) 
    {
        p = p->next;
    }

    if (!p || j > i - 1)
        return ERROR;

    LNode *s = new LNode;

    s->elem = e;

    s->next = p->next;
    p->next = s; 
    
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType e)
{
    LNode *p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
    }

    if (!p || j > i - 1)
        return ERROR;

    LNode *q = p->next;
    p->next = p->next->next;
    e = q->elem;
    delete q;
    
}

int main()
{
    LinkList L;
    InitList_L(L);

    std::cout << LinkLength_L(L) << std::endl;

    CLearList_L(L);
    DestoryList_L(L);

}