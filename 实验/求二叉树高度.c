#include <stdio.h>
#include <stdlib.h>
typedef struct BiTNode {//二叉树结点
	char data;                      //数据
	struct BiTNode *lchild, *rchild; //左右孩子指针
} BiTNode, *BiTree;
int nn = 0;
int CreateBiTree(BiTree *T) {//按先序序列创建二叉树
	char data;
	scanf("%c", &data);//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
	if (data == '#') {
		*T = NULL;
	}
	else {
		*T = (BiTree)malloc(sizeof(BiTNode)); nn++;
		(*T)->data = data;         //生成根结点
		CreateBiTree(&(*T)->lchild);//构造左子树
		CreateBiTree(&(*T)->rchild);//构造右子树
	}
	return 0;
}
int PostTreeDepth(BiTree T)
{
	int hl, hr, h;
	BiTree root = T;
	if (root == NULL) return 0;
	else
	{
		hl = PostTreeDepth(root->lchild);
		hr = PostTreeDepth(root->rchild);
		h = (hl > hr ? hl: hr)+1;
		return h;

	}
}
int main() {

	BiTree T;

	CreateBiTree(&T);
	
	printf("%d\n",(PostTreeDepth(T)-1));

	system("pause");
	return 0;
}
