//删除顺序表中所有值为x的元素
#include <stdio.h>
#define MaxSize 50
typedef struct {
	int data[MaxSize];
	int length;
}SqList; 

void del_x_1(SqList &L,int x) {
	int k = 0; //记录值不等于x的元素个数
	for(int i = 0; i < L.length; i++)    //若L.data[i] = x 则不进入循环直接i++ 
		if(L.data[i] != x){
			L.data[k] = L.data[i];
			k++;             //不等于x的元素个数加1 
		} 
		
	L.length = k;           //顺序表L的长度等于k 
} 
int main() {
	SqList L;
	L.length = 0;
	for(int i = 0; i < 10; i++){
		scanf("%d", &L.data[i]);
		L.length++;
	}
	del_x_1(L,3);
	for(int i = 0; i < L.length; i++){
		printf("%d ", L.data[i]);
	}
	return 0; 
}
