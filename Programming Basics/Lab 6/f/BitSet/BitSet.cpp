#include "BitSet.h"


BitSet::BitSet(uint32_t maxValue) {
  insert(maxValue);
}

BitSet::BitSet(const vector<int> &v) {
  for (auto &i: v) {
    insert(i);
  }
}

uint32_t BitSet::getValues() const {
  return _values;
}

void BitSet::setValues(uint32_t values) {
  _values = values;
  _power = 0;
  for (int i = 0; i < 32; i++)
    if (find(i))
      _power++;
}

unsigned BitSet::getPower() const {
  return _power;
}

bool BitSet::empty() const {
  return _power == 0;
}

bool BitSet::find(unsigned x) const {
  return (_values >> x) % 2;
}

void BitSet::insert(unsigned x) {
  try {
    if (x > _MAX_VALUE_SUPPORTED)
      throw (string) "invalid_argument: x > 31";
    if (!find(x)) {
      _values |= 1 << x;
      _power++;
    }
  } catch (const string &s) {
    cerr << s;
    exit(2);
  }
}

void BitSet::erase(unsigned x) {
  try {
    if (x > _MAX_VALUE_SUPPORTED)
      throw (string) "invalid_argument: x > 31";
    if (find(x)) {
      _values &= ~(0 & (1 << x));
      _power--;
    }
  } catch (const string &s) {
    cerr << s;
    exit(2);
  }
}

bool BitSet::operator==(BitSet &other) const {
  return this->_values == other.getValues();
}

bool BitSet::operator!=(BitSet &other) const {
  return this->_values != other.getValues();
}

bool BitSet::isSubset(const BitSet &set) const {
  return set.getValues() == (set.getValues() | this->getValues());
}

BitSet BitSet::intersection_(const BitSet &lhs, const BitSet &rhs) {
  BitSet res(0);
  res.setValues(lhs.getValues() & rhs.getValues());
  return res;
}

BitSet BitSet::difference_(const BitSet &lhs, const BitSet &rhs) {
  BitSet res{};
  res.setValues(intersection_(lhs, complement_(rhs)).getValues());
  return res;
}

BitSet BitSet::symmetricDifference_(const BitSet &lhs,
                                    const BitSet &rhs) {
  BitSet res{};
  res.setValues(
    difference_(lhs, rhs).getValues() |
    difference_(rhs, lhs).getValues());
  return res;
}

BitSet BitSet::complement_(const BitSet &set) {
  BitSet res(0);
  res.setValues(~set.getValues());
  return res;
}

ostream &operator<<(ostream &out, const BitSet &f) {
  out << '{';
  for (int i = 0; i < 31; i++)
    if (f.find(i))
      out << i << ", ";
  out << "\b\b}";
  return out;
}

void test_getValues() {
  BitSet a({1, 2, 3, 4});
  uint32_t res = 0;
  res += 1 << 1;
  res += 1 << 2;
  res += 1 << 3;
  res += 1 << 4;

  assert(a.getValues() == res);
}

void test_find1() {
  BitSet a(4);

  assert(a.find(4));
}

void test_find2() {
  BitSet a(4);

  assert(a.find(4));
}

void test_find() {
  test_find1();
  test_find2();
}

void test_getPower1() {
  BitSet a({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  assert(a.getPower() == 10);
}

void test_getPower2() {
  BitSet a({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  a.erase(1);
  a.erase(10);

  assert(a.getPower() == 8);
}

void test_getPower() {
  test_getPower1();
  test_getPower2();
}

void test_operators_equal() {
  BitSet a({1, 2, 3});
  BitSet b({1, 2, 3});

  assert(a == b);
}

void test_operators_notEqual() {
  BitSet a({1, 2, 3});
  BitSet b({1, 2});

  assert(a != b);
}

void test_operators() {
  test_operators_equal();
  test_operators_notEqual();
}

void test_isSubset1() {
  BitSet a({1, 2, 3});
  BitSet b({1, 2});

  assert(b.isSubset(a));
}

void test_isSubset2() {
  BitSet a({1, 2, 3});
  BitSet b({1, 2});

  assert(!a.isSubset(b));
}

void test_isSubset() {
  test_isSubset1();
  test_isSubset2();
}

void test_intersection() {
  BitSet a({1, 2, 3, 4});
  BitSet b({3, 4, 5, 6});
  BitSet c = BitSet::intersection_(a, b);

  BitSet res({3, 4});

  assert(res == c);
  assert(c.getPower() == res.getPower());
}

void test_difference() {
  BitSet a({1, 2, 3, 4});
  BitSet b({3, 4, 5, 6});
  BitSet c = BitSet::difference_(a, b);

  BitSet res({1, 2});

  assert(res == c);
  assert(c.getPower() == res.getPower());
}

void test_symmetricDifference() {
  BitSet a({1, 2, 3, 4});
  BitSet b({3, 4, 5, 6});
  BitSet c = BitSet::symmetricDifference_(a, b);

  BitSet res({1, 2, 5, 6});

  assert(res == c);
  assert(c.getPower() == res.getPower());
}

void tests_BitSet() {
  test_getValues();
  test_find();
  test_getPower();
  test_operators();
  test_isSubset();
  test_intersection();
  test_difference();
  test_symmetricDifference();
}