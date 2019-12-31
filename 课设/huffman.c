#define _CRT_SECURE_NO_WARNINGS 1
//  define 替换     typedef 重命名
#include "huffman.h"

int main()
{
	int i, option = 1;
	int w[MAX_TREE_SIZE];
	HuffmanTree HT;
	HuffmanCode HC = NULL;
	printf("----------------------------------------\n");
	printf("********* 哈夫曼编码与译码展示 *********\n");
	printf("----------------------------------------\n");
	printf("正在初始化，请稍候!\n\n");
	for (i = 0; i < 8; i++)
	{
		printf(". ");
		Sleep(220);
	}
	InitTree_HT(&HT);        //初始化树
	system("CLS");
	while (option != 0)
	{
		start_screen();
		scanf("%d", &option);
		system("CLS");
		switch (option)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			CreateHuffmanTree_HT(&HT, w);//建立哈夫曼树

			HuffmanCodeing_HT_2(HT, &HC);//计算哈夫曼编码
			system("pause");
			system("CLS");
			break;
		}
		case 2:
		{
			if (HT == NULL)
			{
				printf("请先建立一棵哈夫曼树\n");
				system("pause");
				system("CLS");
				break;
			}
			else
			{
				ShowHuffmanTree_HT(HT);//展示哈夫曼树
				system("pause");
				system("CLS");
				break;
			}
		}
		case 3:
		{
			if (HT == NULL)
			{
				printf("请先建立一棵哈夫曼树\n");
				system("pause");
				system("CLS");
				break;
			}
			else
			{
				ShowHuffmanCode_HT(HT, HC);//展示哈夫曼编码
				system("pause");
				system("CLS");
				break;
			}
		}
		case 4:
		{
			if (HT == NULL)
			{
				printf("请先建立一棵哈夫曼树\n");
				system("pause");
				system("CLS");
				break;
			}
			else
			{
				SaveHuffmanCodeFile(HC);//对文件进行编码
				system("pause");
				system("CLS");
				break;
			}
		}
		case 5:
		{
			if (HT == NULL)
			{
				printf("请先建立一棵哈夫曼树\n");
				system("pause");
				system("CLS");
				break;
			}
			else
			{
				DecodeHuffmanFile(HT, HC, w);//对文件进行译码
				system("pause");
				system("CLS");
				break;
			}

		}
		}
		system("CLS");
	}
	return 0;
}

void InitTree_HT(HuffmanTree *HT)
{
	*HT = NULL;
}
int start_screen()
{
	printf("----------------------------------------\n");
	printf("********* 哈夫曼编码与译码展示 *********\n");
	printf("----------------------------------------\n");
	printf("|          [1].建立哈夫曼树            |\n");
	printf("|          [2].展示哈夫曼树            |\n");
	printf("|          [3].展示哈夫曼编码          |\n");
	printf("|          [4].文 件 编 码             |\n");
	printf("|          [5].文 件 译 码             |\n");
	printf("|          [0].退 出 系 统             |\n");
	printf("----------------------------------------\n");
	printf(" ==> 请输入序号进行选择                 \n");
	printf("----------------------------------------\n");
	return 0;
}

Status CreateHuffmanTree_HT(HuffmanTree *HT, int w[])
{
	int m, n;
	HuffmanTree p;
	int i;
	int s1, s2;

	CalculateWeight(w);
	n = w[0];
	printf("录入哈夫曼树叶子结点个数→ %d\n", n);

	printf("依次录入各叶子结点的权值为→ ");
	for (i = 1; i <= n; i++)
	{
		printf("%d ", w[i]);
	}
	printf("\n");

	m = 2 * n - 1;		//

	*HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	if (!(*HT))
		exit(OVERFLOW);

	(*HT)[0].weight = n;

	for (i = 1; i <= m; i++)
	{
		if (i <= n)
			(*HT)[i].weight = w[i];
		else
			(*HT)[i].weight = 0;

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0;
	}

	for (i = n + 1; i <= m; i++)
	{
		Select_HT(*HT, i - 1, &s1, &s2);

		(*HT)[s1].parent = (*HT)[s2].parent = i;

		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}


	return OK;
}

Status CalculateWeight(int w[])
{
	char filename[20];
	FILE *fp1;
	char ch;
	int i;
	w[0] = 26;
	for (i = 1; i <= 26; i++)
	{
		w[i] = 0;
	}
	printf("请输入构建哈夫曼树的文件名：");
	scanf("%s", filename);
	if ((fp1 = fopen(filename, "r")) == NULL)
	{
		printf("File open error!\n");
		system("pause");
		exit(0);
	}
	while (!feof(fp1))    //将文件中的字符存入26个字母在数组中的对应位置
	{
		ch = fgetc(fp1);
		if (ch >= 97 && ch <= 122)
		{
			w[ch - 96] = w[ch - 96] + 1;     //出现一次权值加一    权值--次数
		}
		if (ch >= 65 && ch <= 90)
		{
			w[ch - 64] = w[ch - 64] + 1;
		}
	}
	return OK;
}

Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2)
{
	HuffmanTree p;
	int i, count;
	int m, n, tmp;

	if (end < 2)
		return ERROR;

	for (i = 1, count = 1; i <= end; i++)
	{
		if (HT[i].parent == 0)
		{
			if (count == 1)
				m = i;
			if (count == 2)
				n = i;
			count++;
		}

		if (count > 2)
			break;
	}

	if (HT[m].weight > HT[n].weight)
	{
		tmp = n;
		n = m;
		m = tmp;
	}

	i = (m > n ? m : n) + 1;
	while (i <= end)
	{
		if (HT[i].parent == 0)
		{
			if (HT[i].weight < HT[m].weight)
			{
				n = m;
				m = i;
			}
			else
			{
				if (HT[i].weight >= HT[m].weight && HT[i].weight < HT[n].weight)
					n = i;
			}
		}

		i++;
	}

	*order_1 = HT[m].weight <= HT[n].weight ? m : n;
	*order_2 = HT[m].weight > HT[n].weight ? m : n;

	return OK;
}

Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC)
{
	char* code;
	int n, i;
	int start, c, f;

	n = HT[0].weight;

	*HC = (HuffmanCode)malloc((n + 1) * sizeof(HCNode));
	if (!(*HC))
		exit(OVERFLOW);

	code = (char*)malloc(n * sizeof(char));
	if (!code)
		exit(OVERFLOW);

	code[n - 1] = '\0';

	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
		{
			if (HT[f].lchild == c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}

		(*HC)[i] = (char*)malloc((n - start) * sizeof(char));

		strcpy((*HC)[i], &code[start]);
	}

	free(code);
}

Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC)
{
	int m, n, i;
	int cdlen;
	int p, mark[MAX_TREE_SIZE];
	char* code;

	n = HT[0].weight;
	m = 2 * n - 1;

	*HC = (HuffmanCode)malloc((n + 1) * sizeof(HCNode));
	if (!(*HC))
		exit(OVERFLOW);

	code = (char*)malloc(n * sizeof(char));
	if (!code)
		exit(OVERFLOW);

	for (i = 1; i <= n; i++)
		code[i] = '\0';

	for (i = 1; i <= m; i++)
		mark[i] = 0;

	p = m;
	cdlen = 0;

	while (p)
	{
		if (mark[p] == 0)
		{
			mark[p] = 1;
			if (HT[p].lchild != 0)
			{
				p = HT[p].lchild;
				code[cdlen] = '0';
				cdlen++;
			}
			else
			{
				if (HT[p].rchild == 0)
				{
					(*HC)[p] = (char*)malloc((cdlen + 1) * sizeof(char));
					strcpy((*HC)[p], code);
				}
			}
		}
		else
		{
			if (mark[p] == 1)
			{
				mark[p] = 2;
				if (HT[p].rchild != 0)
				{
					p = HT[p].rchild;
					code[cdlen] = '1';
					cdlen++;
				}
			}
			else	//mark[p]==2
			{
				p = HT[p].parent;
				cdlen--;
				code[cdlen] = '\0';
			}
		}
	}



}

void ShowHuffmanTree_HT(HuffmanTree HT)
{
	int i;

	printf("┏━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┳━━━━━━┓\n");
	printf("┃*order┃weight┃parent┃lchild┃rchild┃\n");
	//for(i=0; i<=2*HT[0].weight-1; i++)
	for (i = 0; i <= HT[0].weight; i++)
	{
		if (i == 0)
			printf("┃  %2d  ┃ %4d ┃  ×  ┃  ×  ┃  ×  ┃\n", i, HT[i].weight);
		else
			printf("┃  %2d  ┃ %4d ┃  %2d  ┃  %2d  ┃  %2d  ┃\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("┗━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┻━━━━━━┛\n");
}

void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC)
{
	int i;

	printf("┏━━━━━━┳━━━━━━┳━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃*order┃weight┃      哈夫曼编码    ┃\n");
	for (i = 1; i <= HT[0].weight; i++)
		printf("┃  %2d  ┃ %4d ┃──→  %-14s┃\n", i, HT[i].weight, HC[i]);
	printf("┗━━━━━━┻━━━━━━┻━━━━━━━━━━━━━━━━━━━━┛\n");
}

void SaveHuffmanCodeFile(HuffmanCode HC)
{
	int i;
	FILE *fp1, *fp2;
	char ch;
	char filename1[20], filename2[20], str1[15];
	printf("请输入进行哈夫曼编码的文件名：");
	scanf("%s", filename1);
	if ((fp1 = fopen(filename1, "r")) == NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	printf("请输入编码文件保存路径：      ");
	scanf("%s", filename2);
	if ((fp2 = fopen(filename2, "w")) == NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	while (!feof(fp1))
	{
		ch = fgetc(fp1);
		if (ch >= 97 && ch <= 122)
		{
			fputs(HC[ch - 96], fp2);
		}
		else if (ch >= 65 && ch <= 90)
		{
			fputs(HC[ch - 64], fp2);
		}
		else
		{
			if (ch != EOF)
			{
				fputc(ch, fp2);
			}
		}
	}
	if (fclose(fp2))
	{
		printf("Can not close the file!\n");
		exit(0);
	}
	printf("编码完成,编码信息已保存在文件 %s 中！\n", filename2);
}

void DecodeHuffmanFile(HuffmanTree HT, HuffmanCode HC, int w[])
{
	FILE *fp1, *fp2;
	char filename1[20], filename2[20], s[20];
	char ch, letter;
	int temp_weight, i, j, t;
	printf("请输入需要译码的文件名：");
	scanf("%s", filename1);
	if ((fp1 = fopen(filename1, "r")) == NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	printf("请输入译码文件保存路径：");
	scanf("%s", filename2);
	if ((fp2 = fopen(filename2, "w")) == NULL)
	{
		printf("File open error!\n");
		exit(0);
	}
	while (!feof(fp1))
	{
		t = 26 * 2 - 1;
		i = 0;
		while ((HT[t].lchild != 0) && (HT[t].rchild != 0) && (!feof(fp1)))
		{
			ch = fgetc(fp1);
			if (ch == '1')
			{
				t = HT[t].rchild;
				s[i] = '1';
				i++;
			}
			else if (ch == '0')
			{
				t = HT[t].lchild;
				s[i] = '0';
				i++;
			}
			else
				fputc(ch, fp2);
		}
		if ((ch == '1') || (ch == '0'))
		{
			s[i] = '\0';
			temp_weight = HT[t].weight;
			for (j = 1; j <= 26; j++)
			{
				if (w[j] == temp_weight && (strcmp(s, HC[j]) == 0))
				{
					letter = j + 96;
					fputc(letter, fp2);
					break;
				}
			}
		}
	}
	if (fclose(fp2))
	{
		printf("Can not close the file!\n");
		exit(0);
	}
	printf("译码信息成功保存在文件  %s 中！\n", filename2);
}




















/*
节点的度： 节点拥有的子树个数
树的度：最大度
叶子节点：度为0的节点
祖先节点：有通路 该节点之前的所有节点
子孙节点：该节点子树中所有节点
树的深度：节点层次的最大值
*/
