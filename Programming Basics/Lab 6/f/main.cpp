#include "BitSet/BitSet.h"
#include "PrefixSum/PrefixSum.h"
#include "MaterialPoint/MaterialPoint.h"
#include "fraction/Fraction.h"

int main() {
  tests_Fraction();
  tests_BitSet();
  tests_PrefixSum();
  tests_MaterialPoint();

  return 0;
}
