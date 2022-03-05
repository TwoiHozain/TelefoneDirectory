#pragma once
#include "StructDefine.h"

//Вывести на экан контакт
void showContact(struct contact c, struct foneList fL);//*

//Показат все контакты
void showAll(struct contactList c, struct foneList fL);//*

//Вывести на экран пользователя с указанным номером телефона
void showContactByFone(struct contactList cL, struct foneList fL, ulonglong fone);//*

//Вывести на экан пользователь с указанным именем
void showContactByName(char name[30]);

//Вернет -1 если нет контакта с таким именем, иначе индекс контакта
int getContactIndByName(char name[30]);

static void printName(char name[nameLength]);

static void printFones(struct contact c, struct foneList fL);

//Проверить наличие контакта с таким именем в списке
//Есть 1,иначе 0
int isContactInList();

//Проверить наличие такого номера телефона в списке
//Есть 1,иначе 0
int isFoneNumberInList();

//Если телефон найден ,вернет его индекс иначе -1
int findeFoneInFl(struct foneList fL,ulonglong fone);

//Вывести список номеров телефонов
void printFonesStruct(struct foneList fL);

//Вывести список контактов
void printContactsStruct(struct contactList cL,struct foneList fL);

