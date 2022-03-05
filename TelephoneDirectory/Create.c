#pragma once
#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "StructDefine.h"
#include "Read.h"

//int setName(struct contact *c,char name[30])
//{
//
//}

static void upDateFoneInd(struct contact* c, int oldInd, int newInd)
{
	int i = 0,buf=0;
	for (;i<4;i++)
	{
		if (c->foneInd[i]==oldInd)
		{
			c->foneInd[i] = newInd;
		}
	}

	for (i=0;i<3;i++)
	{
		if (c->foneInd[i]>c->foneInd[i+1])
		{
			buf = c->foneInd[i+1];
			c->foneInd[i+1] = c->foneInd[i];
			c->foneInd[i] = buf;
		}
	}
}

void addContactAndFones(struct contactList *cL, struct foneList *fL, struct contact c, struct fone f[4])
{
	int foneInd[4],i=0,j=0,k=0,flag=1;
	int contInd = 0;

	//Добавить контакт в список контактов
	cL->contactCount++;
	cL->contacts = realloc(cL->contacts,sizeof(struct contact)*cL->contactCount);
	cL->contacts[cL->contactCount - 1] = c;

	contInd = cL->contactCount-1;

	for (i=0;i<4;i++)
	{
		cL->contacts[cL->contactCount - 1].foneInd[i] = emptyFoneInd;
	}

	i = 0;
	//Добавить номера телефонов в список номеров телефонов
	for (;i<4;i++)
	{
		flag = 1;
		if (f[i].fone !=0)
		{
			fL->foneCount++;
			fL->fones =realloc(fL->fones,sizeof(struct fone)*(fL->foneCount));
			fL->fones[fL->foneCount - 1].fone = unsetFoneNum;

			j = 0;
			while(j<fL->foneCount && flag)
			{
				if (f[i].fone < fL->fones[j].fone)
				{
					for (k=fL->foneCount-1;k>j;k--)
					{//Где то тут зарыт глич с обновлением индексов
						upDateFoneInd(&cL->contacts[fL->fones[k-1].contactInd],k-1,k);
						fL->fones[k] = fL->fones[k-1];
					}

					fL->fones[j].fone = f[i].fone;
					fL->fones[j].contactInd = contInd;
					cL->contacts[cL->contactCount - 1].foneInd[i] = j;
					flag = 0;
				}

				if (fL->fones[j].fone == unsetFoneNum)
				{
					fL->fones[j].fone = f[i].fone;
					fL->fones[j].contactInd = contInd;
					cL->contacts[cL->contactCount - 1].foneInd[i] = j;
					flag = 0;
				}

				j++;
			}
		}
		else
		{
			cL->contacts[cL->contactCount - 1].foneInd[i] = emptyFoneInd;
		}
	}

	
}

//Создать случайный набор контактов и телефонов
struct contactList createRandomDataSet()
{

}

//Создать контакт со случайными данными
static struct contact createRandomContact()
{

}