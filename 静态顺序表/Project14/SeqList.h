#pragma once
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

typedef int DataType;
#define MAX_SIZE (100)

typedef struct SeqList {
	int i ;
	DataType array[MAX_SIZE];
	int size;//1���� ˳������Ѿ����˵����ݸ���  2��ǰ�����±�
} SeqList;

//��ʼ��
void SeqListInit(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//����
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq);
	pSeq->size = 0;
}

//β��
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����");
		assert(0);
		return;
	}

	//һ�����	
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//βɾ
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq);


	//�������
	if (pSeq->size < 0)
	{
		printf("����\n");
		assert(0);
		return;
	}

	//ͨ�����

	pSeq->size--;
}

//ͷ��
void SeqListPushFront(SeqList *pSeq,DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
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

//ͷɾ
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
}

//���м�������
void SeqListInset(SeqList *pSeq, DataType pos, DataType data)
{
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
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

//���м����ɾ��
void SeqListErase(SeqList *pSeq, DataType pos)
{
	assert(pSeq);
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->size--;
}

//��ӡ
void SeqListPrint(SeqList *pSeq)
{
	assert(pSeq != NULL);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}


//����
//�ҵ���һ�������������±꣬û�ҵ�����-1
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

//�ڶ���ɾ��
//ɾ�������ĵ�һ������;
void SeqLinRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);
	if (pos == -1)
	{
		printf("û�ҵ�\n");
		return;
	}
	SeqListErase(pSeq, pos);
}
//ɾ��ȫ����ͬ������
void SeqListAllRemove(SeqList *pSeq, DataType data)
{
	//int pos;
	//while ((pos = SeqListFind(pSeq, data)) != -1)
	//{
	//	SeqListErase(pSeq, pos);
	//	
	//}//1����ʱ�䲻�����ţ�

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
	////�ڶ��ַ����˷��˿ռ��ʡ��ʱ�䡣



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

