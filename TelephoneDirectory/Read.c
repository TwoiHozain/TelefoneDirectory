#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "StructDefine.h"

int findeFoneInFl(struct foneList fL, ulonglong fone)
{
	int low = 0,high=fL.foneCount,mid;

	while (low<=high)
	{
		mid = (high + low) / 2;

		if (fL.fones[mid].fone == fone)
			return mid;

		if (fL.fones[mid].fone > fone)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

static void printName(char name[nameLength])
{
	int i = 0;
	for (;i<nameLength && name[i]!=emptyNameSymbol;i++)
	{
		printf_s("%c", name[i]);
	}
	printf_s("\n");
}

static void printFones(struct contact c, struct foneList fL)
{
	int i = 0;
	for (;i<4;i++)
	{
		if (c.foneInd[i] != emptyFoneInd)
		{
			if (fL.fones[c.foneInd[i]].fone != unsetFoneNum)
			{
				printf_s("  +%lld;\n", fL.fones[c.foneInd[i]].fone);
			}
		}
	}
}

void showContact(struct contact c, struct foneList fL)
{
	printf_s("----------------------------------\n");
	printName(c.contactName);
	printFones(c,fL);
	printf_s("----------------------------------\n");
}

void showAll(struct contactList c,struct foneList fL)
{
	int i = 0;
	for (;i<c.contactCount;i++)
	{
		showContact(c.contacts[i],fL);
	}
}

void printContactsStruct(struct contactList cL,struct foneList fL)
{
	int i = 0, j = 0,k=0;

	if (!cL.contactCount)
	{
		printf("Contact list is empty\n");
	}
	else
	{
		for (; i < cL.contactCount; i++)
		{
			//Печать имени
			printf_s("[%d] ",i);
			for (k=0;k<nameLength && cL.contacts[i].contactName[k]!=emptyNameSymbol;k++)
			{
				printf("%c",cL.contacts[i].contactName[k]);
			}

			printf("\n");
			printFones(cL.contacts[i],fL);

			printf("\n");
		}
	}
}

void printFonesStruct(struct foneList fL)
{
	int i = 0;

	if (!fL.foneCount)
	{
		printf("Fone list is empty\n");
	}
	else
	{
		for (; i < fL.foneCount; i++)
		{
			printf("contInd %d, ", fL.fones[i].contactInd);
			printf("+%lld \n", fL.fones[i].fone);
		}
	}
}

void showContactByFone(struct contactList cL, struct foneList fL,ulonglong fone)
{
	int contInd = findeFoneInFl(fL,fone);

	if (contInd != -1)
	{
		showContact(cL.contacts[contInd],fL);
	}
	else
	{
		printf_s("Contact not found\n");
	}
}

void showContactByName(char name[30])
{
	noFunctionalMessage
}

