#include <stdio.h>
#include <ctype.h>

void reverseText() {
  char n = (char)getchar();
  if (n == '\n')
    return;
  else if (isdigit(n)) {
    reverseText();
    return;
  }
  reverseText();
  printf("%c", n);
}

int main() {
  reverseText();

  return 0;
}
