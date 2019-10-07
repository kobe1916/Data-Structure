/*数据结构与算法-第三章栈和队列课后习题
*课本第85页3.7
*题目:假设以数组Q[m]存放循环队列中的元素,同时设置一个标志tag,以tag=0和tag=1来区别在队头指针(front)和队尾指针(rear)相等时,
*     队列状态为"空"还是"满"。
*     试编写与此结构相应的插入(enqueue)和删除(dequeue)算法。
*编译环境:VC 6.0
*/
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define overflow -1
#define MAXSIZE 10

typedef int qelemType;
int count=0;

typedef struct
{
	qelemType q[MAXSIZE];
	int tag;
	int head,rear;
}sqqueue;

void initQueue(sqqueue &queue)//队列初始化
{
	queue.head=0;
	queue.rear=0;
	queue.tag=0;
}

int enqueue(sqqueue &queue,qelemType e)
{
	if(count==MAXSIZE)
		queue.tag=1;
	if(queue.tag==1 && queue.head==queue.rear)//即队列已满
		return ERROR;
	else
	{
		queue.q[queue.rear]=e;
		queue.rear=(queue.rear+1)%MAXSIZE;
		count++;
	}
	return OK;
}

int dequeue(sqqueue &queue,qelemType &e)
{
	if(count==0)
		queue.tag=0;
	if(queue.tag==0 && queue.head==queue.rear)
		return ERROR;
	else
	{
		e=queue.q[queue.head];
		queue.head=(queue.head+1)%MAXSIZE;
		count--;
	}
	return OK;
}

int queuelen(sqqueue queue)
{
	return (queue.rear-queue.head+MAXSIZE)%MAXSIZE;
}

int main()
{
	sqqueue queue1;
	initQueue(queue1);
	int num;
	for(int i=12;i>=1;i--)
	{
		printf("ATTENTION---Queue's length=%d,",queuelen(queue1));
		if(enqueue(queue1,i))
			printf("成功插入元素%d!\n",i);
		else
		{
			printf("队列已满!\n");
			break;
		}
	}
	printf("\n\n");
	for(int k=1;k<=14;k++)
	{
		printf("ATTENTION---Queue's length=%d,",queuelen(queue1));
		if(dequeue(queue1,num))
			printf("成功删除元素%d!\n",num);
		else
		{
			printf("队列已空!\n");
			break;
		}
	}
	return 0;
}
