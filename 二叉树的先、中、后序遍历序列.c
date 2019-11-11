
#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	char data;//定义二叉链表的结构体
	struct BiTNode *lchild, *rchild;
}Bitree;

Bitree *CreateBtree_DLR(Bitree* root);//以先序遍历二叉树
void PreOrder(Bitree* T);//先序遍历二叉树
void InOrder(Bitree *T);//中序遍历二叉树
void PostOrder(Bitree *T);//后序遍历二叉树


/*================================
函数功能：构建二叉树
=================================*/
Bitree* CreateBtree_DLR(Bitree* root)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '@')
		root = NULL;
	else
	{
		root = (Bitree*)malloc(sizeof(Bitree));
		root->data = ch;
		root->lchild = CreateBtree_DLR(root->lchild);//构造左子树
		root->rchild = CreateBtree_DLR(root->rchild);//构造右子树
	}
	return (root);
}

/*==================================
函数功能：先序遍历递归算法
函数输入：树的根结点
===================================*/
void PreOrder(Bitree *T)
{
	if (T != NULL)
	{
		printf("%c", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

/*==================================
函数功能：中序遍历
===================================*/
void InOrder(Bitree *T)
{
	if (T != NULL)
	{
		InOrder(T->lchild);
		printf("%c", T->data);
		InOrder(T->rchild);
	}
}

/*=================================
函数功能：后序遍历
==================================*/
void PostOrder(Bitree *T)
{
	if (T != NULL)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("%c",T->data);
	}
}

int main()
{
	Bitree *T = NULL;
	printf("输入二叉树的先序遍历结点，建立二叉树。(子树为空时输入@)\n");
	T = CreateBtree_DLR(T);

	printf("\n先序遍历结果：\n");
	PreOrder(T);
	printf("\n中序遍历结果：\n");
	InOrder(T);
	printf("\n后序遍历的结果：\n");
	PostOrder(T);
	return 0;
}

