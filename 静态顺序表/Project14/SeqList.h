#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int DataType;
#define MAX_SIZE (100)

typedef struct SeqList {
	int i ;
	DataType array[MAX_SIZE];
	int size;//1保存 顺序表里已经存了的数据个数  2当前可用下标
} SeqList;

//初始化
void SeqListInit(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//销毁
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//尾插
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了");
		assert(0);
		return;
	}

	//一般情况	
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//尾删
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq);


	//特殊情况
	if (pSeq->size < 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}

	//通常情况

	pSeq->size--;
}

//头插
void SeqListPushFront(SeqList *pSeq,DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}

	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[0] = data;
	pSeq->size++;
}

//头删
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
}

//从中间随便加入
void SeqListInset(SeqList *pSeq, DataType pos, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);
		return;
	}

	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];

	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

//从中间随便删除
void SeqListErase(SeqList *pSeq, DataType pos)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->size--;
}

//打印
void SeqListPrint(SeqList *pSeq)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}


//查找
//找到第一个遇到的数的下标，没找到返回-1
int SeqListFind(SeqList *pSeq, DataType data)
{
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data == pSeq->array[i])
		{
			return i;
		}
	}
	return -1;
}

//第二种删除
//删除遇到的第一个数据;
void SeqLinRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1)
	{
		printf("没找到\n");
		return;
	}
	SeqListErase(pSeq, pos);
}
//删除全部相同的数据
void SeqListAllRemove(SeqList *pSeq, DataType data)
{
	//int pos;
	//while ((pos = SeqListFind(pSeq, data)) != -1)
	//{
	//	SeqListErase(pSeq, pos);
	//	
	//}//1方法时间不是最优，

	//DataType *newArrag = (DataType *)malloc(sizeof(DataType)*pSeq->size);
	//int i, j;
	//for (i = 0, j = 0; i < pSeq->size; i++)
	//{
	//	if (data != pSeq->array[i])
	//	{
	//		newArrag[j] = pSeq->array[i];
	//		j++;
	//	}
	//}
	//for (i = 0; i < j; i++)
	//{
	//	pSeq->array[i] = newArrag[i];
	//}
	//pSeq->size = j;
	//free(newArrag);
	////第二种方法浪费了空间节省了时间。



	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
		
	}
	pSeq->size = j;





}

void test()
{
	SeqList seqList;
	SeqListInit(&seqList);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 27);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 3);
	SeqListPrint(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);

	//SeqListPrint(&seqList);


	//SeqListPushFront(&seqList, 10);
	//SeqListPushFront(&seqList, 20);
	//SeqListPushFront(&seqList, 30);
	//SeqListPushFront(&seqList, 40);

	//SeqListPrint(&seqList);
	//SeqListPopFront(&seqList);

	//SeqListPrint(&seqList);
	//SeqListInset(&seqList, 4, 100);
	//SeqListPrint(&seqList);
	/*SeqListAllRemove(&seqList, 3);

	SeqListPrint(&seqList);*/
}

