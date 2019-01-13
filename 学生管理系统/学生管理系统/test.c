#include<stdlib.h>
#include"Student.h"


int EnterMima() {
	char str[20] = "1234567890";
	char str1[20];
	int i = 3;
	printf("\t\t�������½����:>");
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
	printf("\t\t��ȡ�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s", filename);
	if ((fp = fopen(filename, "a+")) == NULL) {
		printf("\t\t�޷����ļ�!\n");
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
		printf("\t\t��ͨѶ¼Ϊ��!");
		return 0;
	}
	printf("\t\tд�뵽�ļ�!\n");
	printf("\t\t��������д����ļ���:");
	scanf("\t\t%s", filename);
	if ((fp = fopen(filename, "a+")) == NULL) {
		printf("\t\t�޷����ļ�!\n");
		system("pause");
		return 0;
	}
	fprintf(fp, "******************************ѧ��ϵͳ�б�******************************\n");
	fprintf(fp, "����\t\t�Ա�\t\tѧ��\t\t�ɼ�\n");
	fprintf(fp, "----------------------------------------------------------------------\n");
	while (p) {
		fprintf(fp, "%-16s%-16s%-16s%-20s\n", p->chat.name, p->chat.sex, p->chat.sno, p->chat.score);
		p = p->next;
		fprintf(fp, "----------------------------------------------------------------------\n");
	}
	fprintf(fp, "\n******************************��%d��ѧ��*******************************\n", langth(ppNode->next));
	fclose(fp);
	printf("\t\tд��ɹ�!\n");
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
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	n = langth(p);
	while (flag != 'n'&&flag != 'N') {
		system("cls");
		printf("\n\t\t*******��������Ҫ���������*******\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��       1.ѧ���ɼ�              ��\n");
		printf("\t\t��       2.ѧ��ѧ��              ��\n");
		printf("\t\t��       0.�˳�����              ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��������Ҫ����������:");
		scanf("\t\t%d", &m);
		do {
			s = 0;
			if (m != 1 && m != 2 && m != 0) {
				n = 1;
				printf("\t\t��������޸����ݲ�����,����������:");
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
		printf("\t\t�Ƿ��������?(Y/N)");
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
		printf("\t\t��ͨѶ¼Ϊ��!\n");
		return 0;
	}
	while (flag != 'n'&&flag != 'N') {
		p = ppNode->next;
		printf("\n\t\t*******��������Ҫ�޸ĵ�����*******\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��       1.ѧ������              ��\n");
		printf("\t\t��       2.ѧ���ɼ�              ��\n");
		printf("\t\t��       3.ѧ���Ա�              ��\n");
		printf("\t\t��       0.�˳��޸�              ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��������Ҫ�޸ĵ�����:");
		scanf("\t\t%d", &m);
		do {
			n = 0;
			if (m != 1 && m != 2 && m != 3 && m != 0) {
				n = 1;
				printf("\t\t��������޸����ݲ�����,����������:");
				scanf("\t\t%d", &m);
			}
		} while (n);
		if (0 == m) return 0;
		printf("\t\t�����������޸���Ϣ��ѧ��ѧ��:");
		scanf("\t\t%s", nm);
		while (p != NULL && strcmp(p->chat.sno, nm) != 0)p = p->next;
		if (!p) {
			printf("\t\t��ѧ��������!\n");
			return 0;
		}
		if (1 == m) {
			printf("\t\t�����������޸�ѧ������:");
			scanf("\t\t%s", p->chat.name);
		}
		if (2 == m) {
			printf("\t\t�����������޸�ѧ���ɼ�:");
			scanf("\t\t%s", p->chat.score);
		}
		if (3 == m) {
			printf("\t\t�����������޸�ѧ���Ա�:");
			scanf("\t\t%s", p->chat.sex);
		}
		printf("\t\t�Ƿ�����޸�?(Y/N)");
		scanf("\t\t%c", &flag);
	}
	return 0;
}



int Print(pcs **Node) {
	pcs * ppNode = *Node;
	pcs * p = ppNode->next;
	if (!p) {
		printf("\t\t��ѧ��ϵͳΪ��!\n");
		return 0;
	}
	printf("\n\t\t******************************ѧ���б�*******************************\n");
	printf("\t\t����\t\t�Ա�\t\tѧ��\t\t�ɼ�\n");
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
	pcs * pre = ppNode->next;  //��¼p����һ�����
	pcs * hpre = ppNode->next; //������¼p�ĺ�һ�����
	if (!p) {
		printf("\t\t��ѧ��ϵͳΪ��!\n");
		return 0;
	}
	while (flag != 'n'&&flag != 'N')
	{
		system("cls");
		printf("\n\t\t*************ɾ����ʽ*************\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��          1.����ɾ��           ��\n");
		printf("\t\t��          2.ȫ��ɾ��           ��\n");
		printf("\t\t��          0.�˳�ɾ��           ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��ѡ��ɾ����ʽ:");
		scanf("\t\t%d", &m);    //ѡ��ɾ����ʽ
		if (1 == m) {
			if (!p) {
				printf("\t\t��ѧ��ϵͳΪ��!\n");
				return 0;
			}
			p = ppNode->next;
			printf("\t\t��������Ҫɾ����ѧ������:");
			scanf("\t\t%s", nm);
			while (p != NULL && strcmp(p->chat.name, nm) != 0)
			{
				pre = p;
				p = p->next;
			}
			if (!p) {
				printf("\t\t��ѧ��������ѧ��ϵͳ!\n");
				printf("\t\t�Ƿ����ɾ��?(Y/N)");
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
			printf("\t\t��ѧ����ɾ��!\n");
			printf("\t\t�Ƿ����ɾ��?(Y/N)");
			scanf("\t\t%c", &flag);
		}
		if (2 == m) {
			ppNode->next = NULL;
			printf("\t\tȫ��ѧ����ɾ��!\n");
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
		printf("\n\t\t*************��ѯ��ʽ*************\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��          1.��������           ��\n");
		printf("\t\t��          2.����ѧ��           ��\n");
		printf("\t\t��          3.���ҳɼ�           ��\n");
		printf("\t\t��          4.���ҷ���           ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\n\t\t��ѡ���ѯ��ʽ:");
		scanf("\t\t%d", &m);	//ѡ���ѯ��ʽ
		do {
			n = 0;
			if (m != 1 && m != 2 && m != 3 && m != 4) {
				n = 1;
				printf("\t\t������Ĳ�ѯ��ʽ������,����������:");
				scanf("\t\t%d", &m);//ѡ���ѯ��ʽ
			}
		} while (n);
		if (!ppNode) {
			printf("\t\t��ѧ������ϵͳΪ��!\n");
			return 0;
		}
		if (1 == m) {
			char nm[15];
			p = ppNode->next;
			printf("\t\t��������Ҫ��ѯ��ѧ��������:");
			scanf("\t\t%s", nm);
			while (p != NULL && strcmp(p->chat.name, nm) != 0)p = p->next;
			if (!p) {
				printf("\t\t��Ҫ��ѯ��ѧ�������ڣ�\n");
				printf("\t\t�Ƿ������ѯ?(Y\N)");
				scanf("\t\t%c", &flag);
				return 0;
			}
			printf("\t\t��---------------------------��\n");
			printf("\t\t ����:%s\n", p->chat.name);
			printf("\t\t �Ա�:%s\n", p->chat.sex);
			printf("\t\t ѧ��:%s\n", p->chat.sno);
			printf("\t\t �ɼ�:%s\n", p->chat.score);
			printf("\t\t��---------------------------��\n");
		}
		if (2 == m) {
			char te[20];
			p = ppNode->next;
			printf("\t\t��������Ҫ��ѯ��ѧ��:");
			scanf("\t\t%s", te);
			while (p != NULL && strcmp(p->chat.sno, te) != 0)p = p->next;
			if (!p) {
				printf("\t\t��Ҫ��ѯ��ѧ��������!\n");
				printf("\t\t�Ƿ������ѯ?(Y/N)");
				scanf("\t\t%c", &flag);
				return 0;
			}
			printf("\t\t��---------------------------��\n");
			printf("\t\t ����:%s\n", p->chat.name);
			printf("\t\t �Ա�:%s\n", p->chat.sex);
			printf("\t\t ѧ��:%s\n", p->chat.sno);
			printf("\t\t �ɼ�:%s\n", p->chat.score);
			printf("\t\t��---------------------------��\n");
		}
		if (3 == m) {
			char sc[10];
			p = ppNode->next;
			printf("\t\t��������Ҫ��ѯ�ĳɼ�:");
			scanf("\t\t%s", sc);
			do {
				while (p != NULL && strcmp(p->chat.score, sc) != 0)p = p->next;
				if (!p) {
					printf("\t\t��Ҫ��ѯ�ĳɼ������ڣ�\n");
					printf("\t\t�Ƿ������ѯ?(Y/N)");
					scanf("\t\t%c", &flag);
					return 0;
				}
				printf("\t\t��---------------------------��\n");
				printf("\t\t ����:%s\n", p->chat.name);
				printf("\t\t �Ա�:%s\n", p->chat.sex);
				printf("\t\t ѧ��:%s\n", p->chat.sno);
				printf("\t\t �ɼ�:%s\n", p->chat.score);
				printf("\t\t��---------------------------��\n");
				p = p->next;
			} while (p != NULL);
		}
		if (4 == m) return 0;
		printf("\t\t�Ƿ������ѯ?(Y/N)");
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
		printf("\n\t\t�����룺\n");
		printf("\t\t������");
		scanf("\t\t%s", ppNode->chat.name);
		printf("\t\t�Ա�");
		scanf("\t\t%s", ppNode->chat.sex);
		printf("\t\tѧ�ţ�");
		scanf("\t\t%s", ppNode->chat.sno);
		printf("\t\t�ɼ���");
		scanf("\t\t%s", ppNode->chat.score);
		printf("\n\t\t�Ƿ������ӣ�(Y/N):>");
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
		printf("\n\t\t�����룺\n");
		printf("\t\t������");
		scanf("\t\t%s", q->chat.name);
		printf("\t\t�Ա�");
		scanf("\t\t%s", q->chat.sex);
		printf("\t\tѧ�ţ�");
		scanf("\t\t%s", q->chat.sno);
		do {
			n = 0;
			while (p->next != NULL)
			{
				if (strcmp(p->chat.sno, ppNode->chat.sno) == 0)
				{
					printf("\t\t��ѧ�����Ѿ���ѧ����,����������:");
					scanf("\t\t%s", ppNode->chat.sno);
					n = 1;
				}
				p = p->next;
			}

		} while (n);
		
		printf("\t\t�ɼ���");
		scanf("\t\t%s", q->chat.score);
		printf("\n\t\t�Ƿ������ӣ�(Y/N):>");
		scanf("\t\t%c", &flag);
	}
	
}



int admin_state() {
	char c;
	do {
		system("cls");
		printf("\n\t\t**********ѧ������ϵͳ***********\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��        1.ѧ����½             ��\n");
		printf("\t\t��        2.��ʦ��½             ��\n");
		printf("\t\t��        0.�˳�                 ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t����ѡ��:>");
		c = getchar();
	} while (c<'0' || c>'2');
	return (c - '0');
}

int menu_select() {
	char c;
	do {
		system("cls");
		printf("\n\t\t**********ѧ������ϵͳ***********\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t��        1.���ѧ��             ��\n");
		printf("\t\t��        2.��ѯѧ��             ��\n");
		printf("\t\t��        3.ɾ��ѧ��             ��\n");
		printf("\t\t��        4.�޸�ѧ����Ϣ         ��\n");
		printf("\t\t��        5.�鿴ȫ��ѧ����Ϣ     ��\n");
		printf("\t\t��        6.����                 ��\n");
		printf("\t\t��        7.д���ļ�             ��\n");
		printf("\t\t��        8.��ȡ�ļ�             ��\n");
		printf("\t\t��        9.                     ��\n");
		printf("\t\t��        0.�˳�                 ��\n");
		printf("\t\t��-------------------------------��\n");
		printf("\t\t����ѡ����Ҫ���еĲ���:>");
		c = getchar();
	} while (c<'0' || c>'9');
	return (c - '0');
}