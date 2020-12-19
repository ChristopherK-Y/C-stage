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

static void initAttribute(contact_t* ct, int* currentPeople, int* capacity) {
	FILE* attribute = fopen("contact_attribute.txt", "r");
	if (attribute == NULL) {
		printf("Read file error at attribute!\n");
		exit(1);
	}
	fscanf(attribute, "%d %d", currentPeople, capacity);
	fclose(attribute);
}

static void initData(contact_t* ct) {
	FILE* data = fopen("contact_data.txt", "r");
	if (data == NULL) {
		printf("Read file error at data!\n");
		exit(1);
	}
	person_t* p = ct->people;
	for (int i = 0; i < ct->currentPeople; i++) {
		fscanf(data, "%s %c %d %s %s", (p + i)->name, &(p + i)->sex, &(p + i)->age, (p + i)->phoneNumber, (p + i)->address);
	}
	fclose(data);
}

static void writeAttribute(contact_t* ct) {
	FILE* attribute = fopen("contact_attribute.txt", "w");
	if (attribute == NULL) {
		printf("Write file error at attribute!\n");
		exit(1);
	}
	fprintf(attribute, "%d %d", ct->currentPeople, ct->capacity);
	fclose(attribute);
}

static void writeData(contact_t* ct) {
	FILE* data = fopen("contact_data.txt", "w");
	if (data == NULL) {
		printf("Write file error at data!\n");
		exit(1);
	}
	person_t* p = ct->people;
	for (int i = 0; i < ct->currentPeople; i++) {
		fprintf(data, "%s %c %d %s %s\n", (p + i)->name, (p + i)->sex, (p + i)->age, (p + i)->phoneNumber, (p + i)->address);
	}
	fclose(data);
}

static int findIndex(contact_t* ct) {//如果找到就返回下标，否则返回-1
	char phoneNumber[SIZE / 4] = { 0 };
	printf("Please enter his phone number# ");
	scanf(" %s", phoneNumber);
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
		return true;
	}
	return false;
}

static bool isFull(contact_t* ct) {
	assert(ct);
	if (ct->capacity == ct->currentPeople) {
		printf("The contact is full!\nExtending...\n");
		return true;
	}
	return false;
}

static bool extend(contact_t** ct) {
	assert(ct);
	contact_t* new = (contact_t*)realloc(*ct, sizeof(contact_t) + sizeof(person_t) * ((*ct)->currentPeople + INC_NUM));
	if (NULL == new) {
		printf("Extend error!\n");
		return false;
	}
	*ct = new;
	(*ct)->capacity += INC_NUM;
	printf("Extend successfull!\n");
	return true;
}

void initContact(contact_t** ct) {
	int capacity = 0;
	int currentPeople = 0;
	initAttribute(*ct, &currentPeople, &capacity);
	(*ct) = (contact_t*)malloc(sizeof(contact_t) + sizeof(person_t) * capacity);
	if (NULL == (*ct)) {
		printf("Create contact error!\n");
		exit(1);//直接退出
	}
	(*ct)->capacity = capacity;
	(*ct)->currentPeople = currentPeople;
	initData(*ct);
	printf("Create successful!\n");
}

void add(contact_t** ct) {//添加人
	if (isExistence(*ct)) {
		printf("This person is existence!\nAdd error!\n");
		return;
	}
	if (!isFull(*ct) || extend(ct)) {
		person_t* new = (*ct)->people + (*ct)->currentPeople;

		printf("Please enter the name# ");
		scanf(" %s", new->name);

		printf("Please enter the sex# ");
		scanf(" %c", &new->sex);

		printf("Please enter the age# ");
		scanf(" %d", &new->age);

		printf("Please enter the phoneNumber# ");
		scanf(" %s", new->phoneNumber);

		printf("Plese enter the address# ");
		scanf(" %s", new->address);

		(*ct)->currentPeople++;
		printf("Add successful!\n");
		return;
	}
	printf("Add error!\n");
}

void del(contact_t* ct) {//删除
	int index = findIndex(ct);
	if (index != -1) {
		ct->people[index] = ct->people[ct->currentPeople - 1];
		ct->currentPeople--;
		printf("Delete successful!\n");
		return;
	}
	printf("Can't find this person,delete failed!\n");
}

void search(contact_t* ct) {//查找
	int index = findIndex(ct);
	if (index != -1) {
		printf("Now: %d/%d\n", ct->currentPeople, ct->capacity);
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
		printf("Can't find this person!\n");
	}
}

void show(contact_t* ct) {//显示现在程序中的所有人的信息
	printf("Now: %d/%d\n", ct->currentPeople, ct->capacity);
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

void format(contact_t* ct) {//格式化，删除所有人
	ct->currentPeople = 0;
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

void writeFile(contact_t* ct) {
	writeAttribute(ct);
	writeData(ct);
}
