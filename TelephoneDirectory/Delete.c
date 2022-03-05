#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "StructDefine.h"
#include "Read.h"

//Удалить номер телефона
int deleteFone(struct contactList *cL,struct foneList *fL,ulonglong fone)
{
	int ind, i=0,j;
	ind = findeFoneInFl(*fL, fone)+1;

	if (ind)
	{
		for (;i<fL->foneCount;i++)
		{
			for (j=0;j<4;j++)
			{
				if (cL->contacts[fL->fones[i].contactInd].foneInd[j]==i)
				{
					cL->contacts[fL->fones[i].contactInd].foneInd[j] -= 1;
				}
			}
			fL->fones[i - 1] = fL->fones[i];
		}
		return 1;
	}
	return -1;
}

//Удалить запись по номеру телефона
int deleteContactByFone()
{
	
}
