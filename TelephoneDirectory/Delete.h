#pragma once

//������� ����� ��������
//-1 ������� �� ������,1 ������� ������ � ������
int deleteFone(struct contactList* cL, struct foneList* fL, ulonglong fone);

//������� ������ �� ������ ��������
int deleteContactByFone();

//������� ������ �� �����
int deleteContactByName();