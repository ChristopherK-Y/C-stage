#include"contact.h"
//ʵ��һ��ͨѶ¼��

//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
//�ṩ������
//1.�����ϵ����Ϣ
//2.ɾ��ָ����ϵ����Ϣ
//3.����ָ����ϵ����Ϣ
//4.�޸�ָ����ϵ����Ϣ
//5.��ʾ������ϵ����Ϣ
//6.���������ϵ��
//7.����������������ϵ��

int main() {
	int quit = 0;
	int select = 0;
	contact_t* ct = NULL;
	initContact(&ct);
	while (!quit) {
		mainMenu();
		scanf("%d", &select);
		switch (select) {
		case 1:
			add(&ct);
			break;
		case 2:
			del(ct);
			break;
		case 3:
			search(ct);
			break;
		case 4:
			modify(ct);
			break;
		case 5:
			show(ct);
			break;
		case 6:
			format(ct);
			break;
		case 7:
			sort(ct);
			break;
		case 0:
			quit = 1;
			break;
		default:
			printf("Enter error,please enter again!\n");
			break;
		}
	}
	printf("Files are being written to disk������\n");
	writeFile(ct);
	printf("Exit The System!\n");
	return 0;
}