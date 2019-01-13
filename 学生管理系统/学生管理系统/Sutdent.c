#include"Student.h"

int main() {
	pcs *head = (pcs *)malloc(sizeof(pcs));
	head->next = NULL;
	int i = admin_state();
	int a = 0;

	if (i == 2) {
		a = EnterMima();
		if (a != 1) {
			printf("\t\t密码错误，系统退出");
			return 0;
		}
		while (1) {
			switch (menu_select())
			{
			case 1:
				printf("\n\t\t添加学生信息到管理系统\n");
				AddStudent(&head);
				system("pause");
				break;
			case 2:
				printf("\n\t\t在学生管理系统中查找学生\n");
				watch_over(&head);
				system("pause");
				break;
			case 3:
				printf("\n\t\t从学生管理系统中删除该学生\n");
				Delete(&head);
				system("pause");
				break;
			case 4:
				printf("\n\t\t修改在学生管理系统中该学生的信息\n");
				change(&head);
				system("pause");
				break;
			case 5:
				printf("\n\t\t查看全部学生的信息\n");
				Print(&head);
				system("pause");
				break;
			case 6:
				printf("\n\t\t排序\n");
				BobbleSort(&head);
				system("pause");
				break;
			case 7:
				printf("\n\t\t写入文件\n");
				write(&head);
				system("pause");
				break;
			case 8:
				printf("\n\t\t读取文件\n");
				read();
				system("pause");
				break;
			case 9:
				printf("\t\t*此版本为马梦晨所写*\n");
				system("pause");
				break;
			case 0:
				printf("\n\t\t谢谢使用，欢迎下次使用!\n");
				printf("\n\t\t");
				system("pause");
				exit(0);
			}
		}
	}
	else if (i == 1) {
		read();
		system("pause");
	}

	return 0;
}