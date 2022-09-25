//����˳���
/*˳���������飬����������Ļ����ϣ�����Ҫ�������Ǵ�ͷ��ʼ�������洢��������Ծ���*/
#define SEQLIST 0 //1 ��̬ //0 ��̬

#define N 1000
//˳��������������
typedef int SLDateType;//���ı��ض�������Ϳ���˳�����˳��������������

#if SEQLIST //��̬˳���

/* ��̬˳��� */
typedef struct Static_SeqList
{
    SLDateType a[N];
    int size;//��ʾ�����д洢�˶�����Ч����
}Static_SL;

/*
 * ���ݽṹ: �����ݹ���ʵ�����ݵ���ɾ���
*/

/*�ӿں���*/
//˳����ʼ��
void SeqListInit(Static_SL* ps);
//��˳���β����������
void SeqListPushBack(Static_SL* ps, SLDateType x);
//ɾ��˳���β������
void SeqListPopBack(Static_SL* ps);
//��˳���ͷ����������
void SeqListPushFront(Static_SL* ps, SLDateType x);
//ɾ��˳���ͷ������
void SeqListPopFront(Static_SL* ps);

//��̬�ص㣺������˾��޷����� ȱ�㣺�����ٿռ����ȷ��

#else //��̬˳���

/*��̬˳���*/
typedef struct Dynamic_SeqList
{
    SLDateType* a;//��̬���ٵĿռ�
    int size;//��ʾ�����д洢�˶��ٸ�����
    int capacity;//����ʵ���ܴ����ݿռ������Ƕ��
}Dynamic_SL;

/*�ӿں���*/

//˳����ӡ
void SeqListPrint(Dynamic_SL* ps);
//˳����ʼ��
void SeqListInit(Dynamic_SL* ps);
//����˳��� free����̬˳���ռ�õ��ڴ�
void SeqListDestory(Dynamic_SL* ps);


//��˳���β����������
void SeqListPushBack(Dynamic_SL* ps, SLDateType x);
//ɾ��˳���β������
void SeqListPopBack(Dynamic_SL* ps);
//��˳���ͷ����������
void SeqListPushFront(Dynamic_SL* ps, SLDateType x);
//ɾ��˳���ͷ������
void SeqListPopFront(Dynamic_SL* ps);

//�ҵ��˷���xλ���±꣬û���ҵ�����-1
int SeqListFind(Dynamic_SL* ps, SLDateType x);
//ָ���±�λ�ò���
void SeqListInsert(Dynamic_SL* ps, int pos, SLDateType x);

#endif
