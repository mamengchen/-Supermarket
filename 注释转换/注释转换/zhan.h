#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int ShedDataType;

#define MAX_SIZE (100)

typedef struct ShedList {
	ShedDataType array[MAX_SIZE];
	ShedDataType top;     //ջ��
} ShedList;

//��ʼ��
void ShedListInit(ShedList * pSeq)
{
	pSeq->top = 0;
}
//����
void ShedListDestroy(ShedList * pSeq)
{
	pSeq->top = 0;
}

//β��
void PushShedList(ShedList * pSeq,ShedDataType data)
{
	pSeq->array[pSeq->top++] = data;
}

//βɾ
void PopShedList(ShedList * pSeq)
{
	assert(pSeq != NULL);
	pSeq->top--;
}

//�鿴ջ��������
int FindShedNode(ShedList * pSeq)
{
	return pSeq->array[pSeq->top - 1];
}

//ջ���ж�������
int MachNode(ShedList * pSeq)
{
	return pSeq->top;
}

//����
int NodeFull(ShedList *pSeq)
{
	return pSeq->top > MAX_SIZE;
}

//����
int Nodevoid(ShedList * pSeq)
{
	
	return pSeq->top <= 0;
}

//�ж�ջ���еĺϷ���
void JodgeShedList(ShedList * pSeq, int * arr)
{
	ShedList * cur = pSeq;
	int * str = arr;
	static i = 0;
    for ( i = 1; i < 6; i++)
    {
		PushShedList(cur, i);
		while (FindShedNode(cur) == *str)
		{
				PopShedList(cur);
				str++;
				if (cur->top == 0)
				{
					break;
				}
		}
	}
	if (cur->top == 0)
	{
		printf("�����кϷ���\n");
	}
	else
	{
		printf("�����в��Ϸ�: \n");
	}
}

//�ж������Ƿ�ƥ��
void BracketMatch(const char * pSeq, int size)
{
	ShedList array;
	ShedListInit(&array);
	
	char ch;
	char topNode;
	for (int i = 0; i < size; i++)
	{
		ch = pSeq[i];
		switch (ch)
		{
		case '(':
		case'[':
		case'{':
			PushShedList(&array, (int)ch);
			break;
		case')':
		case']':
		case'}':
			if (Nodevoid(&array))
			{
				printf("�����Ŷ�\n");
				ShedListDestroy(&array);
				return;
			}
            
			topNode = FindShedNode(&array);
			PopShedList(&array);

			if (topNode == '('&& ch != ')')
			{
				printf("��ƥ��\n");
				return;
			}

			if (topNode == '{'&& ch != '}')
			{
				printf("��ƥ��\n");
				return;
			}

			if (topNode == '['&& ch != ']')
			{
				printf("��ƥ��\n");
				return;
			}
			break;
		default:
			break;
		}

	}
	if (!(Nodevoid(&array)))
	{
		printf("�����Ŷ���\n");
		return;
	}
	printf("����ƥ��\n");
}


void Test1()
{
	const char * seqs[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};

	for (int i = 0; i < 4; i++) {
		BracketMatch(seqs[i], strlen(seqs[i]));
	}
}


//�沨�����ʽ����׺���ʽ��Reversed Polish Notation.
typedef enum {
	OPERAND,	// ����������
	OPERATOR	// ����������
}	Type;

typedef enum {
	ADD, SUB, MUL, DIV
}	Operator;

typedef struct {
	Type type;
	int	operand;		// ������
	Operator operator;		// ������
}	Element;

int Math(Operator operator, int a, int b)
{
	switch (operator) {
	case ADD:
		return a + b;
	case SUB:
		return a - b;
	case MUL:
		return a * b;
	case DIV:
		return a / b;
	default:
		// ��Ӧ�ó���
		assert(0);
	}
}

int ReversedPolishNotation(Element * pSeq, int size)
{
	ShedList State;
	ShedListInit(&State);
	int op1, op2;
	int result;
	for (int i = 0; i < size; i++)
	{
		Element e = pSeq[i];
		switch (e.type)
		{
		case OPERAND:
			PushShedList(&State, e.operand);
			break;
		case OPERATOR:
			op2 = FindShedNode(&State); PopShedList(&State);
			op1 = FindShedNode(&State); PopShedList(&state);

			result = Math(e.Operator, op1, op2);
			PushShedList(&State, result);
			break;
		default:
			break;
		}
	}
	assert(MachNode(&State) == 1);
	result = FindShedNode(&State);
	return result;
}


void Test2()
{
	Element expression[] = {
		{
			OPERAND,
			1,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERAND,
			2,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		},
		{
			OPERAND,
			3,
			SUB	// �����ʵû���ã����д
		},
		{
			OPERATOR,
			-1,	// �����ʵû���ã����д
			ADD
		}
	};

	int result = ReversePolishNotion(expression, 5);

	printf("result = %d\n", result);
}


void Test()
{
	int i = 0;
	ShedList array;
	ShedListInit(&array);
/*	PushShedList(&array, 1);
	PushShedList(&array, 2);
	PushShedList(&array, 3);
	PushShedList(&array, 4);
	PushShedList(&array, 5);
	PushShedList(&array, 6);
	i = FindShedNode(&array);
	printf("%d\n", i);
	i = MachNode(&array);
	printf("%d\n", i);*/

	int arr[] = { 5,3,4,1,2 };
	//ShedListInit(&array);
	int arr1[] = { 4,5,3,2,1 };
	JodgeShedList(&array, arr);
	//JodgeShedList(&array, arr1);
}