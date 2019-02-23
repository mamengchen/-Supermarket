#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int DataType;
#define INIT_CAPACITY (3)


typedef struct SeqListD {
	DataType *array;
	DataType capacity;//当前容量，等于静态顺序表
	int size;//同静态顺序表 MAX_SIZE
} SeqListD;


//初始化
void SeqListInit(SeqListD *pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->array = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->array);
	pSeq->size = 0;
}

//销毁
void SeqListDestray(SeqListD *pSeq)
{
	free(pSeq->array);
	pSeq->capacity = 0;
	pSeq->array = NULL;
	pSeq->size = 0;

}

//动态内存的扩容机制
static void ExpandIfRequired(SeqListD *pSeq)
{
	//1判断没有满
	if (pSeq->size < pSeq->capacity)
	{
		return;
	}
	//2分配新的内存
	pSeq->capacity += 3;
	DataType *Newarray = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
	//3检查内存是否合理
	assert(Newarray);
	//4把以前的数据搬移到新的内存里去
	for (int i = 0; i < pSeq->size; i++)
	{
		Newarray[i] = pSeq->array[i];
	}
	//5释放旧的内存
	free(pSeq->array);
	pSeq->array = Newarray;
	printf("增容成功\n");
}


//尾增
void SeqListPushBack(SeqListD *pSeq, DataType data)
{
	//1先检查内存
	assert(pSeq);
	//2执行函数看是否需要动态内存开辟
	ExpandIfRequired(pSeq);
	//3一般情况下插入方法
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//尾删
void SeqListPopBack(SeqListD *pSeq, DataType data)
{
	assert(pSeq);
	
	//特殊情况
	if (pSeq->size < 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	pSeq->size--;
}

//头增
void SeqListPushFront(SeqListD *pSeq, DataType data)
{
	assert(pSeq);
	//不够增容
	ExpandIfRequired(pSeq);
	//头插需要数据后移
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//插入首元素，数组长度加一
	pSeq->array[0] = data;
	pSeq->size++;
}


//头删
void SeqListPopFront(SeqListD *pSeq)
{
	assert(pSeq);
	//1删除光了需要中止防止越界
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	//2头删需要数据前移
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	//3减少数组长度
	pSeq->size--;
}


//中间扎入
void SeqListInset(SeqListD *pSeq, DataType pos, DataType data)
{
	//1判断内存
	assert(pSeq);
	//2检查是否需要增容
	ExpandIfRequired(pSeq);
	//3中间插入从pos之后的数据需要向后移动保存，从后先开始移动
	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//4pos元素赋值，以及数组增加一
	pSeq->array[pos] = data;
	pSeq->size++;
}


//中间删除
void SeqListEarse(SeqListD *pSeq, DataType pos)
{
	//1判断内存
	assert(pSeq);
	//2检查是否删空防止越界访问需要assert中止
	if (pSeq->size <= 0)
	{
		printf("已被删空\n");
		assert(0);
		return;
	}
	//3中间删除需要，pos之后的数据前移，从pos后的第一位数据先前移
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//4数组减一
	pSeq->size--;
}





//打印
void SeqListPrint(SeqListD *pSeq)
{
	//1查看内存是否有元素
	assert(pSeq);
	//2循环打印元素
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}





void Test()
{
	SeqListD seqList;
	SeqListInit(&seqList);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);
	SeqListPushFront(&seqList, 5);
	SeqListInset(&seqList, 4, 8);
	SeqListPrint(&seqList);
	
	SeqListDestray(&seqList);
}







