#include "SeqList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void SeqListCheckCapacity(Dynamic_SL* sl);

//�������Σ��β���ʵ�εĿ���
//�βεĸı䲻��Ӱ��ʵ��

void SeqListPrint(Dynamic_SL* ps)
{
    for(int i = 0; i < ps->size;i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

void SeqListInit(Dynamic_SL* ps)//�β�
{
    ps->a = NULL;
    ps->size = ps->capacity = 0;
}

/**
 * ˳���ļ������
 * 1.����˳���û�пռ�
 * 2.�ռ䲻�� --> ����
 * 3.�ռ��㹻��ֱ�Ӳ������ݼ��� 
 */

void SeqListPushBack(Dynamic_SL* ps, SLDateType x)
{
    //�ռ�����������
    SeqListCheckCapacity(ps);
    //�ռ��㹻����ֵ
    ps->a[ps->size] = x;
    ps->size++;
}

#define ARRAY_BOUND 0

void SeqListPopBack(Dynamic_SL* ps)
{
    #if ARRAY_BOUND //��ֹ����Խ��Ƚ�����İ취
    if(ps->size > 0)
    {
        // ps->a[ps->size - 1] = 0;
        //������0���岻�����ɾ����λ�ñ�����Ϊ0����ô�ظ�����ֻ���˷�ʱ��
        ps->size--; //����size--�Ϳ�,size��ʶ�˴洢������Ч���ݣ����ı�size�Ϳ�ʵ��ɾ��˳������ݵ�����
    }
    #else
    //��ֹ����Խ��Ƚϴֱ��ķ��������Խ�磬�򾯸�
    assert(ps->size > 0);// ����˳���������ʱ�����Լ����������ݣ��򱨴�
    //�������Ϊ����ִ�У����Ϊ���򱨴�����ֹ������
    ps->size--;
    #endif
}

//��˳���ͷ����������
void SeqListPushFront(Dynamic_SL* ps, SLDateType x)
{
    //���ռ��Ƿ�����
    SeqListCheckCapacity(ps);
    //Ų������
    int end = ps->size - 1;
    while(end >= 0)
    {
        ps->a[end + 1] = ps->a[end];//���Ų������
        end--;
    }
    ps->a[0] = x;
    ps->size++;
}

//ɾ��˳���ͷ������
void SeqListPopFront(Dynamic_SL* ps)
{
    assert(ps->size > 0);

    int begin = 1;
    while(begin < ps->size)
    {
        ps->a[begin - 1] = ps->a[begin];
        begin++;
    }

    ps->size--;//���������Լ�
}

//����˳��� free��ռ�õ��ڴ�
void SeqListDestory(Dynamic_SL* ps)
{
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->size = 0;
}

//������ݣ��ж�˳����Ƿ����������������������
static void SeqListCheckCapacity(Dynamic_SL* ps)
{
    //�ռ�����������
    if (ps->size == ps->capacity)
    {
        //���newcapacity ��� == 0 ��Ϊ 4����� != 0 ��Ϊ ps->capacity * 2
        int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;

        // realloc ���ݣ�Ϊrealloc��������ռ�
        SLDateType *temp = (SLDateType *)realloc(ps->a, newcapacity * sizeof(SLDateType));
        if (temp == NULL)
        {
            //��ʼ��ʧ��
            printf("realloc fail\n");
            exit(-1); //��ֹ��������� Ϊ-1�������в�������Ϊ0������ֹ
        }
        ps->a = temp; //���ݸ�ֵ��ַ
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
    //���ռ��Ƿ�����
    SeqListCheckCapacity(ps);
    //Ų������
    int end = ps->size -1;
    while(end > pos)
    {
        ps->a[end + 1] = ps->a[end];
        end--;
    }
    //�������
    ps->a[pos] = x;
    //��������
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
