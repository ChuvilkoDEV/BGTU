#ifndef _1_DECTOBIN_H
#define _1_DECTOBIN_H


// Выводит представление в память одного байта по адресу a
void PrintByte(const unsigned char *a);

// Выводит представление в памяти переменной по адресу a, размера size
void PrintVar(void *a, int size);

void TestsDecToBin();

#endif //_1_DECTOBIN_H
