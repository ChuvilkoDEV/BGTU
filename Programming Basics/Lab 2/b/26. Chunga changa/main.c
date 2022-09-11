#include <stdio.h>

int main() {
    long long sMoney;    // Количество монет у Саши
    long long mMoney;    // Количество монет у Маши
    long long cPrice;    // Цена одного кокоса
    scanf("%lld %lld %lld", &sMoney, &mMoney, &cPrice);

    // Количество кокосов, которое может купить Саша (без займов)
    long long s_cnt = sMoney / cPrice;
    // Количество кокосов, которое может купить Маша (без займов)
    long long m_cnt = mMoney / cPrice;
    // Количество кокосов, которое могли бы купит Саша и Маша, если бы покупали вместе
    long long s = (sMoney + mMoney) / cPrice;

    long long duty;   // Количество денег, которое необходимо взять в займ
    if (s_cnt + m_cnt == s)
        duty = 0;
    else if (sMoney % cPrice > mMoney % cPrice)
        duty = cPrice - sMoney % cPrice;
    else
        duty = cPrice - mMoney % cPrice;

    printf("%lld %lld", s, duty);

    return 0;
}