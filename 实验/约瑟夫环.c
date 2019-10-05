//重点：成环后将指针移至最后一个节点，以便于后面使用


//成环，返回尾指针（即成环前的表尾指针，作为之后循环查找的开始）

typedef struct node
{
	int num;
	int mima;
	struct node *next;
} node, *linklist;

linklist tail(int i)
{
	int j = 0;
	linklist L;/*创建头指针*/
	node *p, *r;/*创建用于循环的节点*/
	L = (linklist)malloc(sizeof(node));
	L->next = NULL;
	r = L;
	while (j < i)
	{
		p = (node *)malloc(sizeof(node));
		scanf("%d", &p->mima);
		p->num = j + 1;
		r->next = p;
		r = p;
		j++;
	}
	r->next = L->next;
	free(L);
	return r;/*返回这个循环链表*/
}



linklist bkspace(linklist L, int mima)
{
	int mima1;
	node *a, *b;
	a = L->next;
	b = L;
	if (mima == 1) {
		L->next = a->next;
	}
	else {
		for (int i = 1; i < mima; i++) {
			b = a;
			a = a->next;
		}
		b->next = a->next;
	}
	printf("%d", a->num);
	mima1 = a->mima;
	free(a);
	a = b->next;
	while (a->next != a) {
		if (mima1 != 1) {
			for (int i = 1; i < mima1; i++) {
				b = a;
				a = a->next;
			}
		}
		else
		{

		}
		printf(" %d", a->num);
		mima1 = a->mima;
		b->next = a->next;
		free(a);
		a = b->next;
	}
	printf(" %d", a->num);
}

int main() 
{
	int i, j;
	int mima;
	linklist L;
	node *p;
	scanf("%d %d", &i, &mima);
	L = tail(i);
	bkspace(L, mima);
	system("pause");
	return 0;
}
