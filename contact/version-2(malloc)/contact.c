#include"contact.h"

void mainMenu() {//���˵���ʾ

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

static int findIndex(contact_t* ct) {//����ҵ��ͷ����±꣬���򷵻�-1
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

static bool isExistence(contact_t* ct) {//�����Ƿ���ڣ������ֻ��ţ�
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

void initContact(contact_t** ct,int init_num) {
	(*ct) = (contact_t*)malloc(sizeof(contact_t) + sizeof(person_t) * init_num);
	if (NULL == (*ct)) {
		printf("Create contact error!\n");
		exit(1);//ֱ���˳�
	}
	(*ct)->capacity = init_num;
	(*ct)->currentPeople = 0;
	printf("Create successful!\n");
}

void add(contact_t** ct) {//�����
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

void del(contact_t* ct) {//ɾ��
	int index = findIndex(ct);
	if (index != -1) {
		ct->people[index] = ct->people[ct->currentPeople - 1];
		ct->currentPeople--;
		printf("Delete successful!\n");
		return;
	}
	printf("Can't find this person,delete failed!\n");
}

void search(contact_t* ct) {//����
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

void modify(contact_t* ct) {//�޸�
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

void show(contact_t* ct) {//��ʾ���ڳ����е������˵���Ϣ
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

void format(contact_t* ct) {//��ʽ����ɾ��������
	ct->currentPeople = 0;
	printf("Format successful!\n");
}

static int compare(const void* xp, const void* yp) {
	person_t* x = (person_t*)xp;
	person_t* y = (person_t*)yp;
	return strcmp(x->name, y->name);
}

void sort(contact_t* ct) {//����
	qsort(ct->people, ct->currentPeople, sizeof(person_t), compare);
	printf("Sort successful!\n");
}