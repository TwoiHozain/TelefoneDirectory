#pragma once

//1 ���� ������ ��������,0-���� ���
int isSimbolAllowd(char c);

//0 ���� ��� ����������� ������,1-���� �����,2-������,3-���� �����,4 ���� +,-,+,=,?,:,5-���� \n
//6 - ������ ����� ������, 7- ������ �����������
int whatIsSimbol(char c);

//������ unsetFoneNum,���� ��������� ������ �� �������� ������� ��������
void getFoneNumber(ulonglong* fone, char prefC);

//-1 ,���� � �� ������� ������,����� ����� �� 0 �� 9
int charToNum(char c);

//������ ��������� �� ������ ������� ������� ������ 30
//���� ��������� ������ �� ������������� ������� �����,������ ����� ��������� �� ������ ����� '0'
void getName(char* c);

