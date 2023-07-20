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

typedef struct DulNode
{
    ElemType date;
    DulNode *prior;
    DulNode *next;

} *DulLinkList;

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

    return OK;
}

void CreateList_H(LinkList &L, int n)
{
    L = new LNode;
    L->next = nullptr;
    for (int i = n; i > 0; i--)
    {
        LNode *p = new LNode;
        std::cin >> p->elem;
        p->next = L->next;
        L->next = p;
    }
}

void CreateList_R(LinkList &L, int n)
{
    L = new LNode;
    L->next = nullptr;
    LNode *r = L;
    for (int i = 0; i < n; i++)
    {
        LNode *p = new LNode;
        p->next = nullptr;
        std::cin >> p->elem;
        r->next = p;
        r = p;
    }
}

LinkList Connect(LNode *Ta, LNode *Tb)
{
    LNode *p = Ta->next;
    Ta->next = Tb->next->next;
    delete Tb->next;
    Tb->next = p;
    return Tb;
}


DulNode *GetElemP_Dul(DulLinkList &L, int i)
{
    DulNode *p = new DulNode;
    p = L->next;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
    }
    
    if (!p || j > i)
    {
        return nullptr;
    }

    return p;

}

Status ListInsert_Dul(DulLinkList &L, int i, ElemType e)
{
    DulNode *p = nullptr;
    if (!(p = GetElemP_Dul(L, i))) 
        return ERROR;
    
    DulNode *s = new DulNode;
    s->date = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;

    return OK;
    
}

Status ListDelete_Dul(DulLinkList &L, int i)
{
    DulNode *p = nullptr;
    if (!(p = GetElemP_Dul(L, i)))
        return ERROR;
    
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    p = nullptr;
    return OK;

}
int main()
{
    LinkList L;
    InitList_L(L);

    std::cout << LinkLength_L(L) << std::endl;

    CLearList_L(L);
    DestoryList_L(L);

}