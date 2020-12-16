#include"contact.h"
//实现一个通讯录；

//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//1.添加联系人信息
//2.删除指定联系人信息
//3.查找指定联系人信息
//4.修改指定联系人信息
//5.显示所有联系人信息
//6.清空所有联系人
//7.以名字排序所有联系人

int main() {
	int initNum = 0;//自定义人数容量
	int quit = 0;
	int select = 0;
	printf("Please enter initial capacity of your contact# ");
	scanf("%d", &initNum);
	contact_t* ct = NULL;
	initContact(&ct,initNum);
	ct->capacity = initNum;
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
	printf("Exit The System!\n");
	return 0;
}