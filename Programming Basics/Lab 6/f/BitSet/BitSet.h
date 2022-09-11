#ifndef F_BITSET_H
#define F_BITSET_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class BitSet {
  private:
  // максимальное поддерживаемое значение битсетом как таковым
  static const int _MAX_VALUE_SUPPORTED = 31;
  // максимальное поддерживаемое значение
  // для создаваемой структуры
  const int _maxValue = _MAX_VALUE_SUPPORTED;
  // поле для хранения значений
  uint32_t _values = 0;
  // мощность множества
  unsigned _power = 0;

  public:
  BitSet() = default;

  BitSet(uint32_t maxValue);

  BitSet(const vector<int> &v);

  uint32_t getValues() const;

  void setValues(uint32_t values);

  unsigned getPower() const;

  bool empty() const;

  bool find(unsigned x) const;

  void insert(unsigned x);

  void erase(unsigned x);

  bool operator==(BitSet &other) const;

  bool operator!=(BitSet &other) const;

  bool isSubset(const BitSet &set) const;

  static BitSet intersection_(const BitSet &lhs, const BitSet &rhs);

  static BitSet difference_(const BitSet &lhs, const BitSet &rhs);

  static BitSet symmetricDifference_(const BitSet &lhs,
                                     const BitSet &rhs);

  static BitSet complement_(const BitSet &set);

  friend ostream& operator<<(std::ostream &out, const BitSet &f);
};

void tests_BitSet();

#endif //F_BITSET_H
