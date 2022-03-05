#pragma once

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

#include "StructDefine.h"

int charToNum(char c)
{
	int b = 0;
	if (c - '0' < 10 && 0 <= c - '0')
	{
		b = c - '0';
		return b;
	}
	else
	{
		return -1;
	}
}

int isSimbolAllowd(char c)
{
	int ic = (int)c;
	if (ic > 64 && ic < 91)
	{
		return 1;
	}

	if (ic > 96 && ic < 123)
	{
		return 1;
	}

	if (ic > 47 && ic < 58)
	{
		return 1;
	}

	if (c == ' ' || c == ':' || c == '+' || c == '-' || c == '=' || c == '?' || c == '\n' || c== separatingChar || c== endOfStringChar)
	{
		return 1;
	}

	return 0;
}

//0 если это неизвестный символ,1-если буква,2-пробел,3-если цифра,4 если +,-,+,=,?,:,5-если \n
//6 - символ конца строки, 7- символ разделитель
int whatIsSimbol(char c)
{
	int ic = (int)c;

	if (ic > 64 && ic < 91 || ic > 96 && ic < 123)
	{
		return 1;
	}

	if (c == ' ')
	{
		return 2;
	}

	if (ic > 47 && ic < 58)
	{
		return 3;
	}

	if (c == ':' || c == '+' || c == '-' || c == '=' || c == '?')
	{
		return 4;
	}

	if (c == '\n')
	{
		return 5;
	}

	if (c == endOfStringChar)
	{
		return 6;
	}

	if (c == separatingChar)
	{
		return 7;
	}

	return 0;
}

void getFoneNumber(ulonglong *fone,char prefC)
{
	int i = 0, j = 0;
	char c = prefC;
	*fone = 0;

	while (c!=separatingChar && c != endOfStringChar)
	{
		if (whatIsSimbol(c)==3)
		{
			if (j < 11)
			{
				*fone += pow(10, 10 - j)* charToNum(c);
				j++;
			}
			else
			{
				printf("Введен слишком длинный номер телефона\n");
				*fone = unsetFoneNum;
				return;
			}
		}

		if (whatIsSimbol(c) != 3)
		{
			printf("Номер телефона может содержать только цифры\n");
			*fone = unsetFoneNum;
			return;
		}
		c = getchar();
	}

	if (j<10)
	{
		printf("введен слишком короткий номер телефона\n");
		*fone = unsetFoneNum;
		return;
	}
}

void getName(char *name)
{
	int i = 0;
	char c;

	name[0] = emptyNameSymbol;

	while ((c=getchar())!=',')
	{
		if ((whatIsSimbol(c)==1 || whatIsSimbol(c) == 3))
		{
			if (i < nameLength)
			{
				name[i] = c;
				i++;
			}
			else
			{
				name[0] = emptyNameSymbol;
				return;
			}
		}
		else
		{
			name[0] = emptyNameSymbol;
			return;
		}
	}

	for (;i<nameLength;i++)
	{
		name[i] = emptyNameSymbol;
	}
}

