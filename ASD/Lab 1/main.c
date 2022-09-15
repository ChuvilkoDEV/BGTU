#include "DecToBin/DecToBin.h"
#include "BinToDec/BinToDec.h"

#define ARRAY_SIZE 6


int main() {
  printf("\tTask 5\n");
  TestsDecToBin();
  printf("\tTask 7\n");
  TestsBinToDec();

  /*
  long double x = 0;
  char s1[] = "0000000000000000000000001011001011111111111111110100"
              "0000000001001110000111101011100001010001111010111000"
              "010100011110100000000000";
  GetVarFromString(s1, &x, sizeof(long double));
  printf("x = %Lf\n", x);
*/
  return 0;
}