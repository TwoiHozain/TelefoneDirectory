#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include<stdlib.h>
#include <locale.h>

#include "Read.h"
#include "Create.h"
#include "Delete.h"
#include "Update.h"
#include "EntryDataProcessing.h"
#include "StructDefine.h"

//Вернет 1 ,если разрешен,0- если смвол неразрешен

void printHelpMessage()
{
	printf_s("----------------------HELP------------------------\n");
	printf_s("Допустимые символы -цифры 0-9 и буквы A-Z,a-z\n");
	printf_s("Формат данных:\n");
	printf_s("  Имя не может начинаться с цифры и не может содержать символы +,-,=,?\n\n");
	printf_s("  Максимальная длинная имени 30 символов\n");
	printf_s("  Номер телефона обязательно должен содержать 10 цифр\n");
	printf_s("  Контакт обязательно должен содержать хотя бы один номер телефона\n");
	printf_s("Добавить:\n");
	printf_s("  Используйте символ + для создания нового контакта\n");
	printf_s("  Введите +Имя,номер телефона1,номер телефона2,номер телефона3,номер телефона4;\n");
	printf_s("  Вводить 4 номера телефона не обязательно,1 достаточно.\n");
	printf_s("Найти:\n");
	printf_s("  Введите : что бы увидеть весь список контактов\n");
	printf_s("  Введите :номер телефона; что бы найти контакт по номеру телефона\n");
	printf_s("  Количество вводимых номеров телефонов не ограничено\n");
	printf_s("  Номера телефонов нужно воодить ,разделяя их ','\n");
	printf_s("Изменить:\n");
	printf_s("  Нету пока :(\n");
	printf_s("Удалить:\n");
	printf_s("  Нету пока :(\n");
	printf_s("--------------------------------------------------\n");
}

void setName(struct contact* c, const char n[30], int nameL)
{
	int i = 0;

	for (; i < nameL; i++)
	{
		c->contactName[i] = n[i];
	}

	for (; i < 30; i++)
	{
		c->contactName[i] = emptyNameSymbol;
	}
}

void setTmpContact(struct contact *tC)
{
	int i = 0;

	for (; i < 4; i++)
	{
		tC->foneInd[i] = emptyFoneInd;
	}

	tC->contactName[0] = '0';
}

void setTmpFone(struct fone *fT)
{
	int i = 0;
	for (;i<4;i++)
	{
		fT[i].fone = unsetFoneNum;
		fT[i].contactInd = emptyContactInd;
	}
}

void setDataString(char *ds)
{
	int i = 0;
	for (;i<34;i++)
	{
		ds[i] = emptyNameSymbol;
	}
}

void main()
{
	struct contact c1, c2, c3;
	struct fone f1[4], f2[4], f3[4];
	struct foneList fL;
	struct contactList cL;

	struct contact tmpContact;
	struct fone tmpFones[4];

	ulonglong f = 0;
	int c, i, nLength = 0, j = 0, flag = 0;

	char entryDataString[34] = {'0'};

	setlocale(LC_CTYPE, "");

	fL.fones = malloc(sizeof(struct fone));
	cL.contacts = malloc(sizeof(struct contact));

	fL.foneCount = 0;
	cL.contactCount = 0;

	f1[0].fone = 11111111111;
	f1[1].fone = 55555555111;
	f1[2].fone = 99999999999;
	f1[3].fone = 0;

	f2[0].fone = 22222222222;
	f2[1].fone = 77777777777;
	f2[2].fone = 0;
	f2[3].fone = 0;

	f3[0].fone = 33333333331;
	f3[1].fone = 0;
	f3[2].fone = 0;
	f3[3].fone = 0;

	setName(&c1, "Biba", 4);
	setName(&c2, "Boba", 4);
	setName(&c3, "Buba", 4);

	addContactAndFones(&cL, &fL, c1, f1);
	addContactAndFones(&cL, &fL, c2, f2);
	addContactAndFones(&cL, &fL, c3, f3);

	//printContactsStruct(cL,fL);
	//printFonesStruct(fL);

	//showContactByFone(cL, fL, 33333333333);

	setTmpFone(&tmpFones);
	setTmpContact(&tmpContact);

	printf("Введите '?' для помощи\n");
	while ((c = getchar()) != '&')
	{
		if (isSimbolAllowd(c))
		{
			if (c == '?')
			{
				printHelpMessage();
			}

			if (c == ':')
			{
				c = getchar();
				switch (whatIsSimbol(c))
				{
				//Встреченный символ буква
				case(1):
				{
					getName(c);
					break;
				}
				//Встреченный символ цифра
				case(3):
				{
					while (c!='\n' && c != ';')
					{
						getFoneNumber(&f,c);
						if (f != unsetFoneNum)
						{
							showContactByFone(cL, fL, f);
						}
						c=getchar();
					}
					break;
				}
				case(5):
				{
					showAll(cL,fL);
					break;
				}
				}
			}

			if (c == '+')
			{
				getName(&tmpContact.contactName);

				i = 0;
				flag = 0;
				if (tmpContact.contactName[0] != emptyNameSymbol)
				{
					c = getchar();
					while (c != '\n' && c != ';' && i<4)
					{
						getFoneNumber(&f, c);
						if (f != unsetFoneNum)
						{
							flag ++;
						}

						tmpFones[i].fone = f;
						i++;
						c = getchar();
					}
				}

				if (flag)
				{	
					addContactAndFones(&cL,&fL,tmpContact,tmpFones);
					setTmpContact(&tmpContact);
					setTmpFone(&tmpFones);

					printf("Контакт добавлен\n");
				}
			}

			if (c=='-')
			{
				i = 0;
				flag = 0;

				c = getchar();
				while (c != '\n' && c != ';' && i < 4)
				{
					getFoneNumber(&f, c);
					if (f != unsetFoneNum)
					{
						flag++;
					}

					tmpFones[i].fone = f;
					i++;
					c = getchar();
				}

				for (i=0;i<4;i++)
				{
					if (tmpFones[i].fone !=unsetFoneNum)
					{					
						deleteFone(&cL,&fL,tmpFones[i].fone);
					}
				}

				setTmpContact(&tmpContact);
				setTmpFone(&tmpFones);
			}
		}
	}
}