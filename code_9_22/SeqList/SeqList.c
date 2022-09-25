#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void SeqListCheckCapacity(Dynamic_SL* sl);

//函数传参，形参是实参的拷贝
//形参的改变不会影响实参

void SeqListPrint(Dynamic_SL* ps)
{
    for(int i = 0; i < ps->size;i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListInit(Dynamic_SL* ps)//形参
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

/**
 * 顺序表的几种情况
 * 1.整个顺序表没有空间
 * 2.空间不够 --> 扩容
 * 3.空间足够，直接插入数据即可 
 */

void SeqListPushBack(Dynamic_SL* ps, SLDateType x)
{
    //空间已满，扩容
    SeqListCheckCapacity(ps);
    //空间足够，赋值
    ps->a[ps->size] = x;
    ps->size++;
}

#define ARRAY_BOUND 0

void SeqListPopBack(Dynamic_SL* ps)
{
    #if ARRAY_BOUND //防止数组越界比较温柔的办法
    if(ps->size > 0)
    {
        // ps->a[ps->size - 1] = 0;
        //上面置0意义不大，如果删除的位置本来就为0，那么重复置零只会浪费时间
        ps->size--; //仅让size--就可,size标识了存储多少有效数据，仅改变size就可实现删除顺序表数据的作用
    }
    #else
    //防止数组越界比较粗暴的方法，如果越界，则警告
    assert(ps->size > 0);// 仅在顺序表有数据时，可自减，若无数据，则报错
    //断言如果为真则不执行，如果为假则报错并且中止掉程序
    ps->size--;
    #endif
}

//向顺序表头部插入数据
void SeqListPushFront(Dynamic_SL* ps, SLDateType x)
{
    //检测空间是否已满
    SeqListCheckCapacity(ps);
    //挪动数据
    int end = ps->size - 1;
    while(end >= 0)
    {
        ps->a[end + 1] = ps->a[end];//向后挪动数据
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}

//删除顺序表头部数据
void SeqListPopFront(Dynamic_SL* ps)
{
    assert(ps->size > 0);

    int begin = 1;
    while(begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        begin++;
    }

    ps->size--;//数据总数自减
}

//销毁顺序表 free掉占用的内存
void SeqListDestory(Dynamic_SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}

//检测增容，判断顺序表是否已满，如果已满，则阔容
static void SeqListCheckCapacity(Dynamic_SL* ps)
{
    //空间已满，扩容
    if (ps->size == ps->capacity)
    {
        //如果newcapacity 如果 == 0 则为 4；如果 != 0 则为 ps->capacity * 2
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

        // realloc 扩容，为realloc开辟链表空间
        SLDateType *temp = (SLDateType *)realloc(ps->a, newcapacity * sizeof(SLDateType));
        if (temp == NULL)
        {
            //初始化失败
            printf("realloc fail\n");
            exit(-1); //中止程序的运行 为-1程序运行不正常，为0正常中止
        }
        ps->a = temp; //扩容赋值地址
        ps->capacity = newcapacity;
    }
}

int SeqListFind(Dynamic_SL* ps, SLDateType x)
{
    for(int i = 0; i < ps->size; i++)
    {
        if(ps->a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void SeqListInsert(Dynamic_SL* ps, int pos, SLDateType x)
{
    //检测空间是否已满
    SeqListCheckCapacity(ps);
    //挪动数据
    int end = ps->size -1;
    while(end > pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    //添加数据
    ps->a[pos] = x;
    //数据自增
    ps->size++;
}

void SeqListErase(Dynamic_SL* ps, int pos)
{
    assert(ps->size > 0);
    int begin = pos;
    while(begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        begin++;
    }
    ps->size--;
}
