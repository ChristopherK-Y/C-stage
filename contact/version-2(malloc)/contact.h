#ifndef _CONTACT_H_
#define _CONTACT_H_

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include<string.h>

#define SIZE 128
#define INC_NUM 50
#pragma warning(disable:4996)

//每个人的信息包括：姓名、性别、年龄、电话、住址
typedef struct person {
	char name[SIZE / 4];
	char sex;
	int age;
	char phoneNumber[SIZE / 4];
	char address[SIZE];
}person_t;

//通讯录可以用来存储1000个人的信息
typedef struct contact {
	int currentPeople;//当前的人数
	int capacity;//容量
	person_t people[0];
}contact_t;

typedef enum { false, true }bool;

void mainMenu();
void initContact(contact_t** ct, int);
void add(contact_t**);
void show(contact_t*);
void del(contact_t*);
void search(contact_t*);
void modify(contact_t*);
void format(contact_t*);
void sort(contact_t*);

#endif
