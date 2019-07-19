//链队列
typedef struct node
{
	QueueElementType data;
	struct node *next;

}LinkQueueNode;
typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

LinkQueue *Q;

//初始化
int InitQueue(LinkQueue *Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front != Null)
	{
		Q->rear = Q->front;
		Q->front->next = NUll;
		return(TRUE);
	}
	else return(FLASE);
}

//入队操作
