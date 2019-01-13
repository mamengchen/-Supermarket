#pragma once

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#include<assert.h>
typedef struct chsystem {
	char name[20];//姓名
	char sex[6];  //性别
	char sno[20]; //学号
	char score[10];	  //成绩
}student;

typedef struct pcs {
	student chat;
	struct pcs * next;
}pcs;


int admin_state();	//判断是学生用还是老师用
int menu_select();	//功能选择
void AddStudent(pcs **Node);	//添加学生信息	
int watch_over(pcs **Node);		//查询个人信息
int Delete(pcs **Node);		//删除学生信息
int change(pcs **Node);	//修改某学生的所以信息
int Print(pcs ** Node);	//打印全部学生的信息
int BobbleSort(pcs **Node);	//排序
int write(pcs **Node);
int read();
int EnterMima();