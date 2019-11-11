#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode {//二叉树结点
    char data;                      //数据
    struct BiTNode *lchild,*rchild; //左右孩子指针
} BiTNode,*BiTree;
int nn=0;
int CreateBiTree(BiTree *T) {//按先序序列创建二叉树
    char data;
    scanf("%c",&data);//按先序次序输入二叉树中结点的值（一个字符），‘#’表示空树
    if (data == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode)); nn++;
        (*T)->data = data;         //生成根结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
    return 0;
}
void Visit(BiTree T) {//输出
    if (T->data != '#') {
        printf("%c",T->data);
    }
}
void PreOrder(BiTree T) {//先序遍历
    if (T != NULL) {
        Visit(T);               //访问根节点
        PreOrder(T->lchild);    //访问左子结点
        PreOrder(T->rchild);    //访问右子结点
    }
}
void InOrder(BiTree T) {//中序遍历
    if (T != NULL) {
        InOrder(T->lchild);     //访问左子结点
        Visit(T);               //访问根节点
        InOrder(T->rchild);     //访问右子结点
    }
}
void PostOrder(BiTree T) {//后序遍历
    if (T != NULL) {
        PostOrder(T->lchild);   //访问左子结点
        PostOrder(T->rchild);   //访问右子结点
        Visit(T);               //访问根节点
    }
}


int main() {
    BiTree T;
 
    
    CreateBiTree(&T);
 
    PreOrder  (T);printf("\n");
    
    InOrder   (T);printf("\n");
   
    PostOrder (T);
    
    return 0;
}
