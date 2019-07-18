typedef struct node
{
	int num;
	struct node *next;
}node;


node* creat()
{
	node *head, *p, *s;
	int x, i;

	//!!!!!!!
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	p = head;

	printf("请输入要创建节点个数->");
	scanf("%d", &x);
	for (i = 0; i < x; i++)
	{
		s = (node*)malloc(sizeof(node));
		printf("请输入第%d节点数值", i+1);
		scanf("%d", &s->num);
		p->next = s;
		p = s;
		s->next = NULL;
		
	}
	return head;
}

node* read(node* head)
{
	node *p = head;
	p = p->next;
	while (p)
	{
		printf("%d \n", p->num);
		p = p->next;
	}
}

node* headinsert(node *head)
{
	node *p = head;
	if (p)
	{
		node *s;
		s = (node*)malloc(sizeof(node));
		printf("请输入要头插的数->");
		scanf("%d", &s->num);
		s->next = p->next;
		p->next = s;
	}
	
	return head;
}
node* tailinsert(node *head)
{
	node *p = head;
	while (p->next != NULL)
	//while (p!=NULL)
	{
		p = p->next;
	}
	node *s;
	s = (node*)malloc(sizeof(node));
	printf("请输入要尾插的数->");
	scanf("%d", &s->num);
	//p = s;
	//s->next= p->next;
	//p->next = s;
	p->next=s;
	s->next = NULL;
	
	return head;

}
//node* delete(node *head)

int main()
{
	node* head = NULL;
	head = creat();
	read(head);
	headinsert(head);
	read(head);
	tailinsert(head);
	read(head);
	system("pause");
	return 0;
}
