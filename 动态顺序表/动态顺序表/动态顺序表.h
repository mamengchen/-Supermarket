#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int DataType;
#define INIT_CAPACITY (3)


typedef struct SeqListD {
	DataType *array;
	DataType capacity;//��ǰ���������ھ�̬˳���
	int size;//ͬ��̬˳��� MAX_SIZE
} SeqListD;


//��ʼ��
void SeqListInit(SeqListD *pSeq)
{
	pSeq->capacity = INIT_CAPACITY;
	pSeq->array = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
	assert(pSeq->array);
	pSeq->size = 0;
}

//����
void SeqListDestray(SeqListD *pSeq)
{
	free(pSeq->array);
	pSeq->capacity = 0;
	pSeq->array = NULL;
	pSeq->size = 0;

}

//��̬�ڴ�����ݻ���
static void ExpandIfRequired(SeqListD *pSeq)
{
	//1�ж�û����
	if (pSeq->size < pSeq->capacity)
	{
		return;
	}
	//2�����µ��ڴ�
	pSeq->capacity += 3;
	DataType *Newarray = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
	//3����ڴ��Ƿ����
	assert(Newarray);
	//4����ǰ�����ݰ��Ƶ��µ��ڴ���ȥ
	for (int i = 0; i < pSeq->size; i++)
	{
		Newarray[i] = pSeq->array[i];
	}
	//5�ͷžɵ��ڴ�
	free(pSeq->array);
	pSeq->array = Newarray;
	printf("���ݳɹ�\n");
}


//β��
void SeqListPushBack(SeqListD *pSeq, DataType data)
{
	//1�ȼ���ڴ�
	assert(pSeq);
	//2ִ�к������Ƿ���Ҫ��̬�ڴ濪��
	ExpandIfRequired(pSeq);
	//3һ������²��뷽��
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//βɾ
void SeqListPopBack(SeqListD *pSeq, DataType data)
{
	assert(pSeq);
	
	//�������
	if (pSeq->size < 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	pSeq->size--;
}

//ͷ��
void SeqListPushFront(SeqListD *pSeq, DataType data)
{
	assert(pSeq);
	//��������
	ExpandIfRequired(pSeq);
	//ͷ����Ҫ���ݺ���
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//������Ԫ�أ����鳤�ȼ�һ
	pSeq->array[0] = data;
	pSeq->size++;
}


//ͷɾ
void SeqListPopFront(SeqListD *pSeq)
{
	assert(pSeq);
	//1ɾ��������Ҫ��ֹ��ֹԽ��
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	//2ͷɾ��Ҫ����ǰ��
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	//3�������鳤��
	pSeq->size--;
}


//�м�����
void SeqListInset(SeqListD *pSeq, DataType pos, DataType data)
{
	//1�ж��ڴ�
	assert(pSeq);
	//2����Ƿ���Ҫ����
	ExpandIfRequired(pSeq);
	//3�м�����pos֮���������Ҫ����ƶ����棬�Ӻ��ȿ�ʼ�ƶ�
	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//4posԪ�ظ�ֵ���Լ���������һ
	pSeq->array[pos] = data;
	pSeq->size++;
}


//�м�ɾ��
void SeqListEarse(SeqListD *pSeq, DataType pos)
{
	//1�ж��ڴ�
	assert(pSeq);
	//2����Ƿ�ɾ�շ�ֹԽ�������Ҫassert��ֹ
	if (pSeq->size <= 0)
	{
		printf("�ѱ�ɾ��\n");
		assert(0);
		return;
	}
	//3�м�ɾ����Ҫ��pos֮�������ǰ�ƣ���pos��ĵ�һλ������ǰ��
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	//4�����һ
	pSeq->size--;
}





//��ӡ
void SeqListPrint(SeqListD *pSeq)
{
	//1�鿴�ڴ��Ƿ���Ԫ��
	assert(pSeq);
	//2ѭ����ӡԪ��
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







