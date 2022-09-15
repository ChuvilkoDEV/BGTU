#include "BinToDec.h"

#define BIT_IN_BYTE 8
#define ARRAY_SIZE 6

void GetByteFromString(const char *s, char *res) {
  for (int i = BIT_IN_BYTE; i > 0; i--)
    if (s[i - 1] == '1')
      *res |= 1 << (BIT_IN_BYTE - i);
}

void GetVarFromString(char *s, void *res, int size) {
  for (int i = 0; i < size; i++)
    GetByteFromString(s + i * BIT_IN_BYTE, res + size - i - 1);
}

void Test_Integers_BTD() {
  int a = 0;
  char s1[] = "00000000000000000000000010110010";
  GetVarFromString(s1, &a, sizeof(int));
  printf("int a = %d\n", a);

  int b = 0;
  char s2[] = "11111111111111111110000100101001";
  GetVarFromString(s2, &b, sizeof(int));
  printf("int b = %d\n\n", b);
}

void Test_LongDouble_BTD() {
  long double x = 0;
  char s1[] = "00000000000000000000000010110010"
              "11111111111111110100000000000100"
              "11100001111010111000010100011110"
              "10111000010100011110100000000000";
  GetVarFromString(s1, &x, sizeof(long double));
  printf("long double x = %Lf\n", x);

  long double y = 0;
  char s2[] = "00000000000000000000000000000000"
              "00010000000000011100000000000101"
              "11111100011101111100111011011001"
              "00010110100001110010100000000000";
  GetVarFromString(s2, &y, sizeof(long double));
  printf("long double y = %Lf\n\n", y);
}

// Массив целых чисел
void Test_IntArray_BTD() {
  int n[ARRAY_SIZE] = {0,0,0,0,0,0};
  char s1[] = "00000000000000000000000000000101"
              "00000000000000000000000000000100"
              "00000000000000000000000000000011"
              "00000000000000000000000000000010"
              "00000000000000000000000000000001"
              "00000000000000000000000000000000";
  GetVarFromString(s1, n, sizeof(int) * ARRAY_SIZE);
  printf("int n[6] = {");
  for (int i = 0; i < ARRAY_SIZE; i++)
    printf("%d, ", n[i]);
  printf("\b\b}\n");

  int m[ARRAY_SIZE] = {0,0,0,0,0,0};
  char s2[] = "00000000000011110100001000111111"
              "00000000000000000000000101000001"
              "00000000000000000000001100001001"
              "00000000000000000000010001010111"
              "00000000000000000000000010010100"
              "00000000000000000000000011111101";
  GetVarFromString(s2, m, sizeof(int) * ARRAY_SIZE);
  printf("int m[6] = {");
  for (int i = 0; i < ARRAY_SIZE; i++)
    printf("%d, ", m[i]);
  printf("\b\b}");
}

void TestsBinToDec() {
  Test_Integers_BTD();
  Test_LongDouble_BTD();
  Test_IntArray_BTD();
}