#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*   
	#顺序表#
1.InitList
2.ListLength
3.GetElem
4.Location
5.ListInsert
6.ListDelete
7.LisrEmpty
8.ClearList
9.DestroyList
*/

#define MAXSIZE 20
typedef struct
{
	int elem[MAXSIZE];
	int length;//长度
}SeqList;

SeqList *L;//定义一个线性表

void Init_SeqList(SeqList *L)
{
	L->length = 0;
}

//插入元素
int Insert_SeqList(SeqList *L, int i, int x)
{
	int j;
	if (L->length == MAXSIZE - 1)//表长不能超过内存
	{
		printf("表满！");
		return 0;
	}
	if (i < 1 || i>L->length - 1)//插入元素位置应在表内
	{
		printf("位置错！");
		return 0;
	}
	for (j = L->length; j >= i; j--)
	{
		L->elem[j + 1] = L->elem[j];//将要插入位置后的元素从最后一个开始依次后移
	}
	L->elem[i] = x;//赋值   同时表长加一
	L->length++;
	return 1;
}

//删除表中元素(按位删除)     --覆盖即删除！
int Delete_SeqList(SeqList *L, int i, int *e)
{
	int j;
	//判表空
	//if(L->length)		i<L->length-1?
	if (i > 1 || i < L->length)
	{
		printf("不存在第i个元素！");
		return 0;
	}

	*e = L->elem[i];//用一个变量保存该值
	for (j = i; j <= L->length; j++)
	{
		L->elem[i] = L->elem[i + 1];//从i的位置依次向前覆盖
	}
	L->length--;//表长减一
	return 1;
}

//查找(按值查找）    在表内且值为所查
int Location_SeqList(SeqList *L, int x)
{
	int i = 1;
	while (i <= L->length&&L->elem[i] != x)//
		i++;
	if (i > L->length)
		return 0;
	else
		return i;//即返回x的存储位置
}
