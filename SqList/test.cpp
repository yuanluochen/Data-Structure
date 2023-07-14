#include <iostream>
#include <cstring>

enum Status
{
    TURE = 1,
    FALSE = 0,
    OK = 1,
    ERROR = 0,
    INFEASIBLE = -1,
    OVERFLOW = -2,
};

typedef char ElemType;

#define SQLIST_MAX_SIZE 100

struct SqList
{

    ElemType *elem;
    int length;
};

Status InitList_Sq(SqList &L)
{

    L.elem = new ElemType[SQLIST_MAX_SIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    return OK;
}

void DestoryList_Sq(SqList &L)
{
    if(L.elem)
        delete L.elem;
        L.elem = nullptr;
}

void ClearList_Sq(SqList &L)
{
    L.length = 0; 
}

int GetLength(SqList &L)
{
    return (L.length);
}

int IsEmpty(SqList &L)
{
    if (L.length == 0)
        return 1;
    else
        return 0;
}

Status GetElem(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return ERROR;

    e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)  
    {
        if (L.elem[i] == e)
            return i + 1;

    }
    return 0;
}

Status ListAdd_Sq(SqList &L, ElemType e)
{
    if (L.length == SQLIST_MAX_SIZE)
        return ERROR;
    
    L.elem[L.length] = e;
    L.length++;

    return OK;
}

Status ListInsert_Sq(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length)
        return ERROR;
    
    if (L.length == SQLIST_MAX_SIZE)
        return ERROR;
    
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }

    L.elem[i - 1] = e;
    L.length++;

    return OK;
}

Status ListDelete_Sq(SqList &L, int i)
{
    if (L.length == 0)
        return ERROR;

    if (i < 1 || i > L.length)
        return ERROR;

    for (int j = i - 1 ; j < L.length;j++)
    {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;

    return OK;
}

int  main()
{
    SqList L;
    ElemType e;

    InitList_Sq(L);

    if (ListAdd_Sq(L, 2) != OK)
    {   
        std::cout << "ADD ERROR" << std::endl;
    }
    
    if (ListInsert_Sq(L, 1, 2) != OK)
    {
        std::cout << "Insert ERROR" << std::endl;
    }

    ListDelete_Sq(L, 1);

    if (GetElem(L, 1, e) == OK)
    {
        std::cout << (int)e << std::endl;
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }

    DestoryList_Sq(L);
    return 0;
}