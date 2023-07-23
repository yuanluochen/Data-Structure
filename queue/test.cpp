
#include <iostream>

#define MAXQSIZE 100

typedef char qElemType;
enum status
{
    OK = 1,
    ERROR = 0,
    OVERFLOW = -2,
};

struct sqQueue
{
    qElemType *base;
    int front;
    int rear;
};

typedef struct qNode
{
    qElemType data;
    qNode *next;
} *queuePtr;

struct linkQueue
{
    //队头指针
    queuePtr front;
    //队尾指针
    queuePtr rear;
};



status initQueue(sqQueue &q)
{
    q.base = new qElemType[MAXQSIZE];

    //判断是否分配成功
    if (!q.base)
        exit(OVERFLOW);

    //头尾指针置0
    q.front = q.rear = 0;
    
    return OK;
}


int queueLength(sqQueue &q)
{
    // 返回长度
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}


status enQueue(sqQueue &q, qElemType e)
{
    //判断队满
    if ((q.rear + 1) % MAXQSIZE == q.front)
        return ERROR;

    //添加元素
    q.base[q.rear] = e;
    //尾指针后移
    q.rear = (q.rear + 1) % MAXQSIZE;

    return OK;
}

status deQueue(sqQueue &q, qElemType &e)
{
    //判断队空
    if (q.front = q.rear)
        return ERROR;

    //获取元素
    e = q.base[q.front];
    //头指针后移
    q.front = (q.front + 1) % MAXQSIZE;

    return OK;
}

qElemType getHead(sqQueue &q)
{
    //筛选队列不为空
    // if (q.front != q.rear)
    return q.base[q.front];
}

status initQueue(linkQueue &q)
{
    // 创建头节点
    q.front = q.rear = new qNode;
    //判断是否创建成功
    if (!q.front)
        exit(OVERFLOW);
    //next域置空
    q.front->next = nullptr;
    return OK;


}

status destoryQueue(linkQueue &q)
{

    qNode *p = nullptr;
    while(q.front)
    {
        p = q.front->next;
        delete q.front;
        q.front = p; 
    }

    return OK;
}

status enQueue(linkQueue &q, qElemType e)
{
    qNode *p = new qNode;
    //判断是否开辟成功
    if (!p)
        exit(OVERFLOW);
    //添加数据域
    p->data = e;
    //next指针域置空
    p->next = nullptr;
    //链队链接
    q.rear->next = p;
    //后移
    q.rear = p;

    return OK;
}

status deQueue(linkQueue &q, qElemType &e)
{
    //判断是否队空
    if (q.front == q.rear)
        return ERROR;
    //获取数据
    e = q.front->data;
    //获取next域的数据
    qNode *p = q.front->next;
    //修改next域指针
    q.front->next = p->next;
    
    //判断删除内容就是尾节点，保存尾节点
    if (p == q.rear)
        q.rear = q.front;

    delete p;
    p = nullptr;

    return OK;

}

qElemType getHead(linkQueue &q)
{
    if (q.front == q.rear)
        return ERROR;
    return q.front->next->data;
}


int main()
{

    return 0;
}