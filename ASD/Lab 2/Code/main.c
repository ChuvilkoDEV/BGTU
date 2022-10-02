#ifndef CODE_STRING_H
#define CODE_STRING_H

//Операция прошла успешно
static const int STR_SUCCESSFUL = 0;

//Выход за границу максимально разрешенного размера строки
//при вводе в нее данных
static const int STRING_INPUT_ERROR = -1;

//Выход за границу максимально разрешенного размера строки
//при вставке данных из одной строки в другую
static const int STRING_INSERT_ERROR = -2;

//Попытка вставить элемент на место которое не существует
static const int STRING_NO_PLACE = -3;

//Выход за границу максимально разрешенного размера строки
//при склеивании в нее данных
static const int STRING_MERGE_ERROR = -4;

//Ошибка поиска в меньшей строки большей подстроки
static const int STRING_POS_ERROR = -5;

int STRING_ERROR;

typedef struct str
{
  char *s; // Указатель на строку
  unsigned max; /* Максимальное количество символов в
строке, определяющееся при инициализации*/
  unsigned N; // Динамическая (текущая) длина строки
};

typedef str *string1;


#endif //CODE_STRING_H

