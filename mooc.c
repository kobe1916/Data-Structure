
假设有一个循环链表的长度大于1，且表中既无头结点也无头指针。
已知s为指向链表某个结点的指针，试编写算法在链表中删除指针s所指结点的前驱结点。
#include <stdio.h>
#include <stdlib.h>
typedef struct NODE
{
	int data;
	struct NODE *next;
}List;
void Print(List *head)//打印列表,省略号表示循环
{
	int i, j = 0;
	List *p;
	p = head->next;
	while (j != 5)
	{
		for (i = 0; i < 10; i++)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		j++;
	}
	printf(">>>>>>>>>>>");
}
void Dels(List *s)//删除s的前驱结点
{
	List *p, *q;;
	p = s;
	while (p->next->next != s)
	{
		p = p->next;
	}
	q = p->next;
	p->next = s;
	free(q);
}
main()
{
	int i;
	List *p, *q, *head, *s;
	head = q = (List *)malloc(sizeof(List));
	for (i = 0; i < 10; i++)//创建单循环列表
	{
		p = (List *)malloc(sizeof(List));
		p->data = i;
		q->next = p;
		if (i == 5)s = p;//假设值为5的结点为s结点
		q = p;
	}
	q->next = head->next;
	printf("未删除s前驱结点的循环列表\n");
	Print(head->next);
	Dels(s);
	printf("\n删除s前驱结点后的循环列表\n");
	Print(head->next);
}





/*已知二叉树以二叉链表结构存储，根指针为root，结构类型定义如下。请编写算法求解叶子结点的数目。

typedef struct node

{  char        data;

   struct node   *lchild,*rchild;

}BiNode,*BiTree;*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct BTNode
{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;
 
BTNode *CreateTree()
{
	char s;
	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	s = getchar();
	if(s == '#')
	    return NULL;
	else{
		root->data = s;
		root->lchild = CreateTree();
		root->rchild = CreateTree();
	}
	return root;
}
 
int CntTree(BTNode *root)
{
	if(!root)
	    return 0;
	else{
		if((!root->lchild) && (!root->rchild))
		    return 1;
		else{
			return(CntTree(root->lchild)+CntTree(root->rchild));
		}
	}
}
 
int main()
​{
	BTNode *root;
	root = CreateTree();
	int cnt;
	cnt = CntTree(root);
	printf("%d\n", cnt);
	return 0;
}
