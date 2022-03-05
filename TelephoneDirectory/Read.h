#pragma once
#include "StructDefine.h"

//������� �� ���� �������
void showContact(struct contact c, struct foneList fL);//*

//������� ��� ��������
void showAll(struct contactList c, struct foneList fL);//*

//������� �� ����� ������������ � ��������� ������� ��������
void showContactByFone(struct contactList cL, struct foneList fL, ulonglong fone);//*

//������� �� ���� ������������ � ��������� ������
void showContactByName(char name[30]);

//������ -1 ���� ��� �������� � ����� ������, ����� ������ ��������
int getContactIndByName(char name[30]);

static void printName(char name[nameLength]);

static void printFones(struct contact c, struct foneList fL);

//��������� ������� �������� � ����� ������ � ������
//���� 1,����� 0
int isContactInList();

//��������� ������� ������ ������ �������� � ������
//���� 1,����� 0
int isFoneNumberInList();

//���� ������� ������ ,������ ��� ������ ����� -1
int findeFoneInFl(struct foneList fL,ulonglong fone);

//������� ������ ������� ���������
void printFonesStruct(struct foneList fL);

//������� ������ ���������
void printContactsStruct(struct contactList cL,struct foneList fL);

