/*数据结构与算法-第三章栈和队列课后习题
*课本第85页3.6
*题目:假设以带头结点的循环链表表示队列,并且只设一个指针指向队尾元素结点(注意:不设头指针),
*     试编写相应的置空队列、判断队列是否为空、入队和出队等算法。
*编译环境:VC 6.0
*/
#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW 0

typedef int qelemType;

typedef struct queue
{
	qelemType data;
	struct queue *next;
}queue,*linkqueue;
typedef struct
{
	linkqueue rear;
	int length;
}sqqueue;

void initQueue(sqqueue &queue)//置空队列
{
	queue.rear=(linkqueue)malloc(sizeof(queue));
	queue.rear->next=queue.rear;
}

int emptyQueue(sqqueue &queue)//判队列是否为空
{
	if(queue.rear->next==queue.rear)
		return OK;
	else
		return 0;
}

int enqueue(sqqueue &queue,qelemType e)
{
	linkqueue p;
	p=(linkqueue)malloc(sizeof(queue));
	if(!p)
		return OVERFLOW;
	p->data=e;
	p->next=queue.rear->next;
	queue.rear->next=p;
	queue.rear=p;
	return OK;
}

int delqueue(sqqueue &queue,qelemType &e)
{
	linkqueue p;
	if(queue.rear->next==queue.rear)
		return ERROR;//若队列为空返回0
	p=queue.rear->next->next;//循环链表队列队尾指针下一结点(也即头结点)的下一结点(即队头指针)
	e=p->data;
	queue.rear->next->next=p->next;
	free(p);
	//delete(p);//free函数与delete函数均可使用
	return OK;
}

int main()
{
	sqqueue queue2;
	qelemType num;
	initQueue(queue2);
	if(emptyQueue(queue2))
		printf("该队列目前为空!\n");
	else
		printf("该队列不为空!\n");
	for(int i=1;i<=10;i++)
		if(enqueue(queue2,i))
			printf("元素%d成功入列!\n",i);
	printf("\n\n");
	for(int j=1;j<=9;j++)
		if(delqueue(queue2,num))
			printf("元素%d成功出列!\n",num);
	if(emptyQueue(queue2))
		printf("该队列目前为空!\n");
	else
		printf("该队列不为空!\n");
	return 0;
}
