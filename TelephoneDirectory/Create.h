#pragma once
#include "StructDefine.h"

static void upDateFoneInd(struct contact* c, int oldInd, int newInd);

//��������� � �������� ������� � �������
void addContactAndFones(struct contactList* cL, struct foneList* fL, struct contact c, struct fone f[4]);

//int setName(struct contact* c, char name[30]);

//������� ��������� ����� ��������� � ���������
struct contactList createRandomDataSet();

//������� ������� �� ���������� �������
static struct contact createRandomContact();






