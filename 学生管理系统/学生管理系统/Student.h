#pragma once

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>
typedef struct chsystem {
	char name[20];//����
	char sex[6];  //�Ա�
	char sno[20]; //ѧ��
	char score[10];	  //�ɼ�
}student;

typedef struct pcs {
	student chat;
	struct pcs * next;
}pcs;


int admin_state();	//�ж���ѧ���û�����ʦ��
int menu_select();	//����ѡ��
void AddStudent(pcs **Node);	//���ѧ����Ϣ	
int watch_over(pcs **Node);		//��ѯ������Ϣ
int Delete(pcs **Node);		//ɾ��ѧ����Ϣ
int change(pcs **Node);	//�޸�ĳѧ����������Ϣ
int Print(pcs ** Node);	//��ӡȫ��ѧ������Ϣ
int BobbleSort(pcs **Node);	//����
int write(pcs **Node);
int read();
int EnterMima();