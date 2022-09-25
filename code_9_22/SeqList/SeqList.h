//定义顺序表
/*顺序表就是数组，但是在数组的基础上，它还要求数据是从头开始存连续存储，不能跳跃间隔*/
#define SEQLIST 0 //1 静态 //0 动态

#define N 1000
//顺序表添加数据类型
typedef int SLDateType;//更改被重定义的类型可以顺便更改顺序表添加数据类型

#if SEQLIST //静态顺序表

/* 静态顺序表 */
typedef struct Static_SeqList
{
    SLDateType a[N];
    int size;//表示数组中存储了多少有效数据
}Static_SL;

/*
 * 数据结构: 对数据管理实现数据的增删查改
*/

/*接口函数*/
//顺序表初始化
void SeqListInit(Static_SL* ps);
//在顺序表尾部插入数据
void SeqListPushBack(Static_SL* ps, SLDateType x);
//删除顺序表尾部数据
void SeqListPopBack(Static_SL* ps);
//向顺序表头部插入数据
void SeqListPushFront(Static_SL* ps, SLDateType x);
//删除顺序表头部数据
void SeqListPopFront(Static_SL* ps);

//静态特点：如果满了就无法插入 缺点：给多少空间很难确定

#else //动态顺序表

/*动态顺序表*/
typedef struct Dynamic_SeqList
{
    SLDateType* a;//动态开辟的空间
    int size;//表示数组中存储了多少个数据
    int capacity;//数组实际能存数据空间容量是多大
}Dynamic_SL;

/*接口函数*/

//顺序表打印
void SeqListPrint(Dynamic_SL* ps);
//顺序表初始化
void SeqListInit(Dynamic_SL* ps);
//销毁顺序表 free掉动态顺序表占用的内存
void SeqListDestory(Dynamic_SL* ps);


//在顺序表尾部插入数据
void SeqListPushBack(Dynamic_SL* ps, SLDateType x);
//删除顺序表尾部数据
void SeqListPopBack(Dynamic_SL* ps);
//向顺序表头部插入数据
void SeqListPushFront(Dynamic_SL* ps, SLDateType x);
//删除顺序表头部数据
void SeqListPopFront(Dynamic_SL* ps);

//找到了返回x位置下标，没有找到返回-1
int SeqListFind(Dynamic_SL* ps, SLDateType x);
//指定下标位置插入
void SeqListInsert(Dynamic_SL* ps, int pos, SLDateType x);

#endif
