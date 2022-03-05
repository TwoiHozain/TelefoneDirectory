#pragma once
#include "StructDefine.h"

static void upDateFoneInd(struct contact* c, int oldInd, int newInd);

//Соединить и добавить телефон и контакт
void addContactAndFones(struct contactList* cL, struct foneList* fL, struct contact c, struct fone f[4]);

//int setName(struct contact* c, char name[30]);

//Создать случайный набор контактов и телефонов
struct contactList createRandomDataSet();

//Создать контакт со случайными данными
static struct contact createRandomContact();






