#include"Student.h"

int main() {
	pcs *head = (pcs *)malloc(sizeof(pcs));
	head->next = NULL;
	int i = admin_state();
	int a = 0;

	if (i == 2) {
		a = EnterMima();
		if (a != 1) {
			printf("\t\t�������ϵͳ�˳�");
			return 0;
		}
		while (1) {
			switch (menu_select())
			{
			case 1:
				printf("\n\t\t���ѧ����Ϣ������ϵͳ\n");
				AddStudent(&head);
				system("pause");
				break;
			case 2:
				printf("\n\t\t��ѧ������ϵͳ�в���ѧ��\n");
				watch_over(&head);
				system("pause");
				break;
			case 3:
				printf("\n\t\t��ѧ������ϵͳ��ɾ����ѧ��\n");
				Delete(&head);
				system("pause");
				break;
			case 4:
				printf("\n\t\t�޸���ѧ������ϵͳ�и�ѧ������Ϣ\n");
				change(&head);
				system("pause");
				break;
			case 5:
				printf("\n\t\t�鿴ȫ��ѧ������Ϣ\n");
				Print(&head);
				system("pause");
				break;
			case 6:
				printf("\n\t\t����\n");
				BobbleSort(&head);
				system("pause");
				break;
			case 7:
				printf("\n\t\tд���ļ�\n");
				write(&head);
				system("pause");
				break;
			case 8:
				printf("\n\t\t��ȡ�ļ�\n");
				read();
				system("pause");
				break;
			case 9:
				printf("\t\t*�˰汾Ϊ���γ���д*\n");
				system("pause");
				break;
			case 0:
				printf("\n\t\tллʹ�ã���ӭ�´�ʹ��!\n");
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