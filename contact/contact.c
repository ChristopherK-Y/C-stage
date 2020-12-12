#include"contact.h"

void mainMenu() {//主菜单显示
	printf("#########################################\n");
	printf("##               Contant               ##\n");
	printf("#########################################\n");
	printf("##     1.Add                 2.Del     ##\n");
	printf("##     3.Sea                 4.Mod     ##\n");
	printf("##     5.Sho                 6.For     ##\n");
	printf("##     7.Sor                           ##\n");
	printf("##                           0:Quit    ##\n");
	printf("#########################################\n");

	printf("Plese enter your select# ");

}

static int findIndex(contact_t* ct) {//如果找到就返回下标，否则返回-1
	char phoneNumber[SIZE / 4] = { 0 };
	printf("Please enter his phone number# ");
	scanf("%s", phoneNumber); getchar();
	for (int i = 0; i < ct->currentPeople; i++) {
		if (strcmp(ct->people[i].phoneNumber, phoneNumber) == 0) {
			return i;
		}
	}
	return -1;
}

static bool isExistence(contact_t* ct) {//该人是否存在（根据手机号）
	int index = findIndex(ct);
	if (index != -1) {
		return false;
	}
	return true;
}

void add(contact_t* ct) {//添加人
	ct->currentPeople++;//人数+1

	if (ct->currentPeople >= TOTAIL) {//人数已满
		ct->currentPeople--;
		printf("The number of people is full,add filed!\n");
		return;
	}
	else if (isExistence(ct)) {
		printf("Please enter the name# ");
		scanf("%s", ct->people[ct->currentPeople - 1].name);
		getchar();

		printf("Please enter the sex(f/m)# ");
		scanf("%c", &(ct->people[ct->currentPeople - 1].sex));
		getchar();

		printf("Please enter the age# ");
		scanf("%d", &(ct->people[ct->currentPeople - 1].age));
		getchar();

		printf("Please enter the phoneNumber# ");
		scanf("%s", ct->people[ct->currentPeople - 1].phoneNumber);
		getchar();

		printf("Please enter the address# ");
		scanf("%s", ct->people[ct->currentPeople - 1].address);
		getchar();
	}
	else {
		printf("This person is Existence,add filed!\n");
		return;
	}
}

void del(contact_t* ct) {//删除
	int index = findIndex(ct);
	if (index != -1) {
		ct->currentPeople--;
		strcpy(ct->people[index].name, ct->people[ct->currentPeople - 1].name);
		ct->people[index].sex = ct->people[ct->currentPeople - 1].sex;
		ct->people[index].age = ct->people[ct->currentPeople - 1].age;
		strcpy(ct->people[index].phoneNumber, ct->people[ct->currentPeople - 1].phoneNumber);
		strcpy(ct->people[index].address, ct->people[ct->currentPeople - 1].address);
		printf("Delete successful!\n");
		return;
	}
	printf("Can't find this person,delete failed!\n");
}

void search(contact_t* ct) {//查找
	int index = findIndex(ct);
	if (index != -1) {
		printf("Name                Sex    Age    PhoneNumber                address                                \n");
		printf("%-20s", ct->people[index].name);
		printf("%-7c", ct->people[index].sex);
		printf("%-7d", ct->people[index].age);
		printf("%-27s", ct->people[index].phoneNumber);
		printf("%-39s\n", ct->people[index].address);
		return;
	}
	printf("Can't find this person!\n");
}

void modify(contact_t* ct) {//修改
	int index = findIndex(ct);
	if (index != -1) {
		printf("Please enter the name# ");
		scanf("%s", ct->people[index].name);
		getchar();

		printf("Please enter the sex(f/m)# ");
		scanf("%c", &(ct->people[index].sex));
		getchar();

		printf("Please enter the age# ");
		scanf("%d", &(ct->people[index].age));
		getchar();

		printf("Please enter the phoneNumber# ");
		scanf("%s", ct->people[index].phoneNumber);
		getchar();

		printf("Please enter the address# ");
		scanf("%s", ct->people[index].address);
		getchar();

		printf("Modify successful!\n");
	}
	else {
		printf("Can't find this person!");
	}
}

void show(contact_t* ct) {//显示现在程序中的所有人的信息
	printf("Name                Sex    Age    PhoneNumber                address                                \n");
	for (int i = 0; i < ct->currentPeople; i++) {
		printf("%-20s", ct->people[i].name);
		printf("%-7c", ct->people[i].sex);
		printf("%-7d", ct->people[i].age);
		printf("%-27s", ct->people[i].phoneNumber);
		printf("%-39s\n", ct->people[i].address);
	}
	printf("\n\n");
}

void format(contact_t* ct, size_t size) {//格式化，删除所有人
	memset(ct, 0, size);
	printf("Format successful!\n");
}

static int compare(const void* xp, const void* yp) {
	person_t* x = (person_t*)xp;
	person_t* y = (person_t*)yp;
	return strcmp(x->name, y->name);
}

void sort(contact_t* ct) {//排序
	qsort(ct->people, ct->currentPeople, sizeof(person_t), compare);
	printf("Sort successful!\n");
}