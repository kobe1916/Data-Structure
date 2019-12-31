#pragma once
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>						
#include <string.h>						
#include <conio.h>
#include <windows.h>

/* 宏定义 */
#define MAX_TREE_SIZE 100			//树的最大结点数
#define NO          0
#define	OK			1
#define	ERROR		0

//#define HUFFMANTREE_H
#define	OVERFLOW	-2
#define	OVERFLOW	-2

//#define HUFFMANTREE_C


/* 哈夫曼树和哈夫曼编码类型定义 */
typedef struct
{
	unsigned int weight;			//权值
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
}HTNode;
typedef HTNode* HuffmanTree;		//动态分配数组存储哈夫曼树
typedef char* HCNode;
typedef HCNode* HuffmanCode;		//动态分配数组存储哈夫曼编码表

typedef int Status;

//函数的声明
void InitTree_HT(HuffmanTree *HT);
Status CreateHuffmanTree_HT(HuffmanTree *HT, int w[]);
Status CalculateWeight(int w[]);
Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2);
Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC);
Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC);
void ShowHuffmanTree_HT(HuffmanTree HT);
void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC);
void SaveHuffmanCodeFile(HuffmanCode HC);
void DecodeHuffmanFile(HuffmanTree HT, HuffmanCode HC, int w[]);
int start_screen();
