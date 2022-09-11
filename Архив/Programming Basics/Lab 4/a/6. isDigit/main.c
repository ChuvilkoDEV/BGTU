#include <stdio.h>

// Возвращает значение 1 (’истина’), если символ x - является цифрой,
// 0 (’ложь’) - в противном случае.
int isDigit(const char x) {
  return x >= '0' && x <= '9';
}

int main() {
  char c;
  scanf("%c", &c);

  printf("%d", isDigit(c));

  return 0;
}
