#include <stdint.h>
#pragma once

#define emptyFoneInd 65535
#define emptyContactInd 255
#define unsetFoneNum 0

#define separatingChar ','
#define emptyNameSymbol '-'
#define endOfStringChar ';'

#define nameLength 30
#define contactMaxCount 254
#define foneMaxCount 1024

#define uShort unsigned short
#define ulonglong unsigned long long

#define noFunctionalMessage printf_s("\n Diada ti funkcional ne napisl -_- \n");

//�������� ���� �������
struct contact
{
	char contactName[nameLength];
	uShort foneInd[4];
};

//�������� ������ ���������
struct contactList
{
	uint8_t contactCount;
	struct contact* contacts;
};

//�������� ���� ����� ��������
struct fone
{
	ulonglong fone;
	uint8_t contactInd;
};

//�������� ������ ���������
struct foneList
{
	uShort foneCount;
	struct fone* fones;
};