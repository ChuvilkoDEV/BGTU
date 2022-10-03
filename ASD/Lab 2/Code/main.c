#include "String/String.h"

int main() {
  str s1;
  InitStr(&s1, 20);
  str s2;
  InitStr(&s2, 20);

  WriteToStr(&s1, (char*){"a   b   cm    "});
  WriteToStr(&s2, (char*){"a b   c    m  "});

  printf("%d", WordCmp(&s1, &s2));
}
