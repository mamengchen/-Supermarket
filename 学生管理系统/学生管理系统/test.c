#include<stdlib.h>
#include"Student.h"


int EnterMima() {
	char str[20] = "1234567890";
	char str1[20];
	int i = 3;
	printf("\t\t请输入登陆密码:>");
	scanf("\t\t%s", str1);
	while (i--) {
		if (strcmp(str, str1) == 0) {
			return 1;
		}
	}
	return 0;
}

int read() {
	char str[100];
	char filename[30];
	FILE* fp;
	printf("\t\t读取文件!\n");
	printf("\t\t请输入所写入的文件名:");
	scanf("\t\t%s", filename);
	if ((fp = fopen(filename, "a+")) == NULL) {
		printf("\t\t无法打开文件!\n");
		system("pause");
		return 0;
	}
	while ((fgets(str, 100, fp)) != NULL) {
		printf("\t\t%s", str);
	}
	return 0;
}


int write(pcs **Node) {
	pcs *ppNode = *Node;
	pcs *p = ppNode->next;
	FILE* fp;
	char filename[30];
	if (!p)
	{
		printf("\t\t该通讯录为空!");
		return 0;
	}
	printf("\t\t写入到文件!\n");
	printf("\t\t请输入所写入的文件名:");
	scanf("\t\t%s", filename);
	if ((fp = fopen(filename, "a+")) == NULL) {
		printf("\t\t无法打开文件!\n");
		system("pause");
		return 0;
	}
	fprintf(fp, "******************************学生系统列表******************************\n");
	fprintf(fp, "姓名\t\t性别\t\t学号\t\t成绩\n");
	fprintf(fp, "----------------------------------------------------------------------\n");
	while (p) {
		fprintf(fp, "%-16s%-16s%-16s%-20s\n", p->chat.name, p->chat.sex, p->chat.sno, p->chat.score);
		p = p->next;
		fprintf(fp, "----------------------------------------------------------------------\n");
	}
	fprintf(fp, "\n******************************共%d个学生*******************************\n", langth(ppNode->next));
	fclose(fp);
	printf("\t\t写入成功!\n");
	return 0;
}
int langth(pcs *p) {
	int n = 0;
	while (p) {
		p = p->next;
		n++;
	}
	return n;
}

int _strcmp(const char *str1, const char *str2)
{
	int ret = 0;
	int *p = str1;
	int *q = str2;
	while (*p || *q) {
		if (*p != '\0') {
			p++;
			ret++;
		}
		if (*q != '\0') {
			q++;
			ret--;
		}
	}
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	return 0;
}

int BobbleSort(pcs **Node)
{
	int i, n, m, s;
	char flag = 'y';
	pcs * ppNode = *Node;
	pcs * p = ppNode->next;
	pcs * pre = ppNode;
	pcs * k = NULL;
	pcs * q = NULL;
	if (!p)
	{
		printf("\t\t该通讯录为空!\n");
		return 0;
	}
	n = langth(p);
	while (flag != 'n'&&flag != 'N') {
		system("cls");
		printf("\n\t\t*******请输入您要排序的内容*******\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│       1.学生成绩              │\n");
		printf("\t\t│       2.学生学号              │\n");
		printf("\t\t│       0.退出排序              │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\n\t\t请输入您要按哪项排序:");
		scanf("\t\t%d", &m);
		do {
			s = 0;
			if (m != 1 && m != 2 && m != 0) {
				n = 1;
				printf("\t\t您输入的修改内容不存在,请重新输入:");
				scanf("\t\t%d", &m);
			}
		} while (s);
		if (0 == m) return 0;
		if (1 == m) {
			for (i = 0; i < n - 1; i++) {
				for (p = ppNode->next, pre = ppNode; p->next->next != NULL; pre = p, p = p->next); {
					k = p->next;
					q = k->next;
					if (strcmp(p->chat.score, k->chat.score) < 0)
					{
						pre->next = k;
						k->next = p;
						p->next = q;
						p = k;
					}
				}
			}
			Print(&ppNode);
		}
		if (2 == m) {
			for (i = 0; i < n - 1; i++) {
				for (p = ppNode->next, pre = ppNode; p->next->next != NULL; pre = p, p = p->next); {
					k = p->next;
					q = k->next;
					if (strcmp(p->chat.sno, k->chat.sno) < 0)
					{
						pre->next = k;
						k->next = p;
						p->next = q;
						p = k;
					}
				}
			}
			Print(&ppNode);
		}
		printf("\t\t是否继续排序?(Y/N)");
		scanf("\t\t%c", &flag);
	}
	return 0;
}


int change(pcs **Node) {
	char nm[20];
	char flag = 'y';
	int m, n;
	pcs * ppNode = *Node;
	pcs * p = ppNode->next;
	if (!p) {
		printf("\t\t该通讯录为空!\n");
		return 0;
	}
	while (flag != 'n'&&flag != 'N') {
		p = ppNode->next;
		printf("\n\t\t*******请输入您要修改的内容*******\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│       1.学生姓名              │\n");
		printf("\t\t│       2.学生成绩              │\n");
		printf("\t\t│       3.学生性别              │\n");
		printf("\t\t│       0.退出修改              │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\n\t\t请输入您要修改的内容:");
		scanf("\t\t%d", &m);
		do {
			n = 0;
			if (m != 1 && m != 2 && m != 3 && m != 0) {
				n = 1;
				printf("\t\t您输入的修改内容不存在,请重新输入:");
				scanf("\t\t%d", &m);
			}
		} while (n);
		if (0 == m) return 0;
		printf("\t\t请输入您想修改信息的学生学号:");
		scanf("\t\t%s", nm);
		while (p != NULL && strcmp(p->chat.sno, nm) != 0)p = p->next;
		if (!p) {
			printf("\t\t该学生不存在!\n");
			return 0;
		}
		if (1 == m) {
			printf("\t\t请输入您的修改学生姓名:");
			scanf("\t\t%s", p->chat.name);
		}
		if (2 == m) {
			printf("\t\t请输入您的修改学生成绩:");
			scanf("\t\t%s", p->chat.score);
		}
		if (3 == m) {
			printf("\t\t请输入您的修改学生性别:");
			scanf("\t\t%s", p->chat.sex);
		}
		printf("\t\t是否继续修改?(Y/N)");
		scanf("\t\t%c", &flag);
	}
	return 0;
}



int Print(pcs **Node) {
	pcs * ppNode = *Node;
	pcs * p = ppNode->next;
	if (!p) {
		printf("\t\t该学生系统为空!\n");
		return 0;
	}
	printf("\n\t\t******************************学生列表*******************************\n");
	printf("\t\t姓名\t\t性别\t\t学号\t\t成绩\n");
	printf("\t\t----------------------------------------------------------------------\n");
	while (p) {
		printf("\t\t%-16s%-16s%-16s%-20s\n", p->chat.name, p->chat.sex, p->chat.sno, p->chat.score);
		p = p->next;
		printf("\t\t----------------------------------------------------------------------\n");
	}
	return 0;
}


int Delete(pcs **Node) {
	char nm[20];
	int m;
	char flag = 'y';
	pcs * ppNode = *Node;
	pcs * p = ppNode->next;
	pcs * pre = ppNode->next;  //记录p的上一个结点
	pcs * hpre = ppNode->next; //用来记录p的后一个结点
	if (!p) {
		printf("\t\t该学生系统为空!\n");
		return 0;
	}
	while (flag != 'n'&&flag != 'N')
	{
		system("cls");
		printf("\n\t\t*************删除方式*************\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│          1.单个删除           │\n");
		printf("\t\t│          2.全部删除           │\n");
		printf("\t\t│          0.退出删除           │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\n\t\t请选择删除方式:");
		scanf("\t\t%d", &m);    //选择删除方式
		if (1 == m) {
			if (!p) {
				printf("\t\t该学生系统为空!\n");
				return 0;
			}
			p = ppNode->next;
			printf("\t\t请输入您要删除的学生姓名:");
			scanf("\t\t%s", nm);
			while (p != NULL && strcmp(p->chat.name, nm) != 0)
			{
				pre = p;
				p = p->next;
			}
			if (!p) {
				printf("\t\t该学生不存在学生系统!\n");
				printf("\t\t是否继续删除?(Y/N)");
				scanf("\t\t%c", &flag);
				return 0;
			}
			hpre = p->next;
			if (p == ppNode->next) {
				ppNode->next = hpre;
			}
			else {
				pre->next = hpre;
			}
			free(p);
			printf("\t\t该学生已删除!\n");
			printf("\t\t是否继续删除?(Y/N)");
			scanf("\t\t%c", &flag);
		}
		if (2 == m) {
			ppNode->next = NULL;
			printf("\t\t全部学生已删除!\n");
			return 0;
		}
		if (0 == m) {
			return 0;
		}
	}
	return 0;
}

int watch_over(pcs **Node) {
	int m, n;
	char flag = 'y';
	pcs * ppNode = *Node;
	pcs * p = ppNode;
	while (flag != 'n'&&flag != 'N')
	{
		system("cls");
		printf("\n\t\t*************查询方式*************\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│          1.查找姓名           │\n");
		printf("\t\t│          2.查找学号           │\n");
		printf("\t\t│          3.查找成绩           │\n");
		printf("\t\t│          4.查找返回           │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\n\t\t请选择查询方式:");
		scanf("\t\t%d", &m);	//选择查询方式
		do {
			n = 0;
			if (m != 1 && m != 2 && m != 3 && m != 4) {
				n = 1;
				printf("\t\t您输入的查询方式不存在,请重新输入:");
				scanf("\t\t%d", &m);//选择查询方式
			}
		} while (n);
		if (!ppNode) {
			printf("\t\t该学生管理系统为空!\n");
			return 0;
		}
		if (1 == m) {
			char nm[15];
			p = ppNode->next;
			printf("\t\t请输入您要查询的学生的姓名:");
			scanf("\t\t%s", nm);
			while (p != NULL && strcmp(p->chat.name, nm) != 0)p = p->next;
			if (!p) {
				printf("\t\t你要查询的学生不存在！\n");
				printf("\t\t是否继续查询?(Y\N)");
				scanf("\t\t%c", &flag);
				return 0;
			}
			printf("\t\t┌---------------------------┐\n");
			printf("\t\t 姓名:%s\n", p->chat.name);
			printf("\t\t 性别:%s\n", p->chat.sex);
			printf("\t\t 学号:%s\n", p->chat.sno);
			printf("\t\t 成绩:%s\n", p->chat.score);
			printf("\t\t└---------------------------┘\n");
		}
		if (2 == m) {
			char te[20];
			p = ppNode->next;
			printf("\t\t请输入您要查询的学号:");
			scanf("\t\t%s", te);
			while (p != NULL && strcmp(p->chat.sno, te) != 0)p = p->next;
			if (!p) {
				printf("\t\t您要查询的学生不存在!\n");
				printf("\t\t是否继续查询?(Y/N)");
				scanf("\t\t%c", &flag);
				return 0;
			}
			printf("\t\t┌---------------------------┐\n");
			printf("\t\t 姓名:%s\n", p->chat.name);
			printf("\t\t 性别:%s\n", p->chat.sex);
			printf("\t\t 学号:%s\n", p->chat.sno);
			printf("\t\t 成绩:%s\n", p->chat.score);
			printf("\t\t└---------------------------┘\n");
		}
		if (3 == m) {
			char sc[10];
			p = ppNode->next;
			printf("\t\t请输入您要查询的成绩:");
			scanf("\t\t%s", sc);
			do {
				while (p != NULL && strcmp(p->chat.score, sc) != 0)p = p->next;
				if (!p) {
					printf("\t\t你要查询的成绩不存在！\n");
					printf("\t\t是否继续查询?(Y/N)");
					scanf("\t\t%c", &flag);
					return 0;
				}
				printf("\t\t┌---------------------------┐\n");
				printf("\t\t 姓名:%s\n", p->chat.name);
				printf("\t\t 性别:%s\n", p->chat.sex);
				printf("\t\t 学号:%s\n", p->chat.sno);
				printf("\t\t 成绩:%s\n", p->chat.score);
				printf("\t\t└---------------------------┘\n");
				p = p->next;
			} while (p != NULL);
		}
		if (4 == m) return 0;
		printf("\t\t是否继续查询?(Y/N)");
		scanf("\t\t%c", &flag);
	}
	return 0;
}

void AddStudent(pcs **Node) {
	char flag = 'y';
	int n;
	pcs * ppNode = *Node;
	pcs * p = ppNode;
	if (ppNode == NULL) {
		printf("\n\t\t请输入：\n");
		printf("\t\t姓名：");
		scanf("\t\t%s", ppNode->chat.name);
		printf("\t\t性别：");
		scanf("\t\t%s", ppNode->chat.sex);
		printf("\t\t学号：");
		scanf("\t\t%s", ppNode->chat.sno);
		printf("\t\t成绩：");
		scanf("\t\t%s", ppNode->chat.score);
		printf("\n\t\t是否继续添加？(Y/N):>");
		scanf("\t\t%c", &flag);
	}
	else {
		while (ppNode->next) {
			ppNode = ppNode->next;
		}

	}
	while (flag != 'n'&&flag != 'N') {
		pcs  *q = (pcs *)malloc(sizeof(pcs));
		ppNode->next = q;
		ppNode = q;
		ppNode->next = NULL;
		printf("\n\t\t请输入：\n");
		printf("\t\t姓名：");
		scanf("\t\t%s", q->chat.name);
		printf("\t\t性别：");
		scanf("\t\t%s", q->chat.sex);
		printf("\t\t学号：");
		scanf("\t\t%s", q->chat.sno);
		do {
			n = 0;
			while (p->next != NULL)
			{
				if (strcmp(p->chat.sno, ppNode->chat.sno) == 0)
				{
					printf("\t\t该学号上已经有学生了,请重新输入:");
					scanf("\t\t%s", ppNode->chat.sno);
					n = 1;
				}
				p = p->next;
			}

		} while (n);
		
		printf("\t\t成绩：");
		scanf("\t\t%s", q->chat.score);
		printf("\n\t\t是否继续添加？(Y/N):>");
		scanf("\t\t%c", &flag);
	}
	
}



int admin_state() {
	char c;
	do {
		system("cls");
		printf("\n\t\t**********学生管理系统***********\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│        1.学生登陆             │\n");
		printf("\t\t│        2.老师登陆             │\n");
		printf("\t\t│        0.退出                 │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\t\t请你选择:>");
		c = getchar();
	} while (c<'0' || c>'2');
	return (c - '0');
}

int menu_select() {
	char c;
	do {
		system("cls");
		printf("\n\t\t**********学生管理系统***********\n");
		printf("\t\t┌-------------------------------┐\n");
		printf("\t\t│        1.添加学生             │\n");
		printf("\t\t│        2.查询学生             │\n");
		printf("\t\t│        3.删除学生             │\n");
		printf("\t\t│        4.修改学生信息         │\n");
		printf("\t\t│        5.查看全部学生信息     │\n");
		printf("\t\t│        6.排序                 │\n");
		printf("\t\t│        7.写入文件             │\n");
		printf("\t\t│        8.读取文件             │\n");
		printf("\t\t│        9.                     │\n");
		printf("\t\t│        0.退出                 │\n");
		printf("\t\t└-------------------------------┘\n");
		printf("\t\t请你选择你要进行的操作:>");
		c = getchar();
	} while (c<'0' || c>'9');
	return (c - '0');
}