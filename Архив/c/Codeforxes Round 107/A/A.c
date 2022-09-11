#include <stdio.h>

int main(void) {
    int n;  // Количество друзей
    int k;  // Количество бутылок газировки
    int l;  // Объем одной бутылки
    int c;  // Количество лаймов
    int d;  // Количество долек одного лайма
    int p;  // Грамм соли
    int nl; // Миллилитров газировки/одна персона
    int np; // Грамм соли/одна персона
    int litres;     // Количество возможных тостов с литрами
    int doles;      // Количество возможных тостов с дольками
    int salt;       // Количество возможных тостов с солью

    scanf("%d %d %d %d %d %d %d %d", &n,&k,&l,&c,&d,&p,&nl,&np);
    litres = (k * l)/(nl * n);
    doles = (c * d)/n;
    salt = p/(np * n);
    if (litres < doles){
        if(litres < salt){printf_s("%d", litres);}
        else{printf_s("%d", salt);}
    }else{
        if(doles < salt){printf_s("%d", doles);}
        else{printf_s("%d", salt);}
    }


    return 0;
}