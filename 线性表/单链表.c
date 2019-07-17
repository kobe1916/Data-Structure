//单链表
//链表的头插、尾插、删除、查找
typedef struct node
{
	int num;
	struct node *next;
}node;

node* linklist()
{
	node *p,*head, *s;
	int x, i;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	p = head;
	
	scanf("%d", &x);
	printf("hehe");
	
	//while (x <i)
	for(i=0;i<x;i++)
	{
		s = (node*)malloc(sizeof(node));
		printf("qingshurujiedianzhi");
		scanf("%d", &s->num);
		p->next = s;
		p = s;
		s->next = NULL;
		
	}
	return head;
}

node* read(node *head)
{
	node* p = head->next;
	//while (head)
	while (p)
	{
		printf("%d \n", p->num);
		p = p->next;
	}

}

int main()
{
	node *head = NULL;
	//linklist();
	head = linklist();//接收头结点才行

	read(head);
	system("pause");
	return 0;
}
