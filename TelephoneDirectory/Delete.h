#pragma once

//Удалить номер телефона
//-1 телефон не найден,1 телефон найден и удален
int deleteFone(struct contactList* cL, struct foneList* fL, ulonglong fone);

//Удалить запись по номеру телефона
int deleteContactByFone();

//Удалить запись по имени
int deleteContactByName();