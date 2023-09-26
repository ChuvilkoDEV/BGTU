#include <iostream>
#include <vector>
#include <array>
#include <windows.h>
#include <map>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std::literals;

struct FanoCode {
  wchar_t symbol;
  int count = 0;
  std::vector<bool> code;
};

struct Tree {
  wchar_t symbol = '_';
  int count = -1;
  Tree *zero = nullptr;
  Tree *one = nullptr;
};

std::wostream &operator<<(
        std::wostream &os,
        const FanoCode &code
) {
  os << "<" << code.symbol << ">(" << code.count << ")" << " code: ";
  for (const auto digit : code.code) {
    os << digit;
  }

  return os;
}

template<class T>
std::wostream &operator<<(
        std::wostream &os,
        const std::vector<T> &v
) {
  for (const auto &el : v) {
    os << el;
  }

  return os;
}

template<class Iterator>
Iterator SplitIntoSymmetricSums(
        Iterator begin,
        Iterator end
) {
  long long l_sum = begin->count;
  long long r_sum = 0;

  while (end - begin > 1) {
    if (r_sum > l_sum) {
      l_sum += (++begin)->count;
    } else {
      r_sum += (--end)->count;
    }
  }

  return end;
}

template<class Iterator>
void GetFanoCode(
        const Iterator &begin,
        const Iterator &end
) {
  if (end - begin < 2) { return; }

  Iterator m = SplitIntoSymmetricSums(begin, end);

  for (auto it = begin; it != end; ++it) {
    it->code.push_back(it < m);
  }

  GetFanoCode(begin, m);
  GetFanoCode(m, end);
}

std::vector<FanoCode> GetFanoCode(const std::unordered_map<wchar_t, int> &counters) {
  if (counters.empty()) {
    return {};
  }

  if (counters.size() == 1) {
    return {{counters.begin()->first, 1, std::vector{true}}};
  }

  std::vector<FanoCode> codes;

  for (auto &i : counters) {
    codes.push_back({i.first, i.second});
  }

  std::sort(codes.begin(),
            codes.end(),
            [](
                    FanoCode &a,
                    FanoCode &b
            ) { return a.count > b.count; });
  GetFanoCode(codes.begin(), codes.end());

  return codes;
}

std::unordered_map<wchar_t, int> ParseString(const std::wstring &str) {
  std::unordered_map<wchar_t, int> counters{};
  for (const auto &symbol : str) {
    counters[symbol]++;
  }

  return counters;
}

std::wstring ParseCode(const std::string &str, const size_t n) {
  std::wstring out;

  size_t l = str.length() / n;
  for (::size_t i = 0; i < l; i++) {
    int id = 0;
    for (size_t j = 0; j < n; j++) {
      id = id * 2 + str[i * n + j] - '0';
    }

    out.push_back(id);
  }

  return out;
}

template<class Iterator>
bool Merge(
        Iterator &code_begin,
        Iterator &sum_begin,
        Iterator &sum_end
) {
  auto cmp_tree = [](
          Tree &a,
          Tree &b
  ) { return static_cast<unsigned>(a.count) <= static_cast<unsigned>(b.count); };

  Tree *min[2];

  for (auto &i : min) {
    if (cmp_tree(*code_begin, *sum_begin)) {
      i = &*code_begin;
      code_begin++;
    } else {
      i = &*sum_begin;
      sum_begin++;
    }
  }

  if (min[0]->count == -1 || min[1]->count == -1) {
    return false;
  } else {
    *sum_end = Tree{'_', min[0]->count + min[1]->count, min[0], min[1]};
    sum_end++;
    return true;
  }
}

template<class Iterator>
Tree GetHuffmanCode(
        Iterator code_begin,
        Iterator sum_begin
) {
  auto sum_end = sum_begin;
  while (Merge(code_begin, sum_begin, sum_end)) {}
  auto res = *std::prev(sum_end);
  return res;
}

Tree GetHuffmanCode(const std::unordered_map<wchar_t, int> &counters) {
  if (counters.empty()) {
    return Tree{};
  }

  if (counters.size() == 1) {
    return Tree{counters.begin()->first};
  }

  static std::vector<Tree> sums;
  static std::vector<Tree> codes;

  sums.clear();
  codes.clear();

  for (auto &i : counters) {
    codes.push_back({i.first, i.second});
  }

  codes.push_back({});
  codes.push_back({});

  sums = std::vector<Tree>(codes.size());

  std::sort(codes.begin(),
            codes.end(),
            [](
                    Tree &a,
                    Tree &b
            ) { return static_cast<unsigned>(a.count) < static_cast<unsigned>(b.count); });
  auto res = GetHuffmanCode(codes.begin(), sums.begin());
  return res;
}

void GetTable(
        const Tree &huffman,
        std::unordered_map<wchar_t, std::vector<bool>> &codes
) {
  static std::vector<bool> dcode;

  if (huffman.zero == nullptr && huffman.one == nullptr) {
    codes.insert({
                         huffman.symbol, dcode.empty()
                                         ? std::vector{true}
                                         : dcode
                 });
  } else {
    if (huffman.zero != nullptr) {
      dcode.push_back(false);
      GetTable(*huffman.zero, codes);
      dcode.pop_back();
    }

    if (huffman.one != nullptr) {
      dcode.push_back(true);
      GetTable(*huffman.one, codes);
      dcode.pop_back();
    }
  }
}

std::unordered_map<wchar_t, std::vector<bool>> GetTable(const std::vector<FanoCode> &fano) {
  std::unordered_map<wchar_t, std::vector<bool>> codes;
  for (auto &el : fano) {
    codes.insert({el.symbol, el.code});
  }
  return codes;
}

std::unordered_map<wchar_t, std::vector<bool>> GetTable(const Tree &huffman) {
  std::unordered_map<wchar_t, std::vector<bool>> codes;
  GetTable(huffman, codes);
  return codes;
}

std::wstring CodeToStr(const std::vector<bool> &code) {
  std::wstring s;
  for (auto x : code) {
    s.push_back(x + '0');
  }

  return s;
}

std::wstring CodeMessage(
        const std::unordered_map<wchar_t, std::vector<bool>> &code,
        const std::wstring &str
) {
  std::wstring out;

  for (wchar_t i : str) {
    out += CodeToStr(code.find(i)->second);
  }

  return out;
}

std::unordered_map<std::vector<bool>, wchar_t> GetDecodeTable(const std::unordered_map<wchar_t, std::vector<bool>> &code) {
  std::unordered_map<std::vector<bool>, wchar_t> out;

  for (auto& el: code) {
    out[el.second] = el.first;
  }

  return out;
}

std::wstring DecodeMessage(
        const std::unordered_map<std::vector<bool>, wchar_t> &code,
        const std::wstring &str
) {
  std::wstring out;
  std::vector<bool> c;

  int i = 0;
  while (i < str.length()) {
    c.clear();
    while (!code.contains(c)) {
      c.push_back(str[i] - '0');
      i++;
    }

    out.push_back(code.find(c)->second);
  }

  return out;
}

std::wostream &operator<<(
        std::wostream &os,
        const std::unordered_map<wchar_t, std::vector<bool>> &v
) {
  for (const auto &el : v) {
    os << "<" << el.first << "> = " << el.second << "\n";
  }

  return os;
}


int GetCodeWeight(const std::wstring &str) {
  std::unordered_map<wchar_t, int> counters{};
  for (const auto &symbol : str) {
    counters[symbol]++;
  }

  int i = ceil(log(counters.size()) / log(2));

  return i * str.length();
}

float GetDispersion(const std::unordered_map<wchar_t, std::vector<bool>> &v, const std::wstring& msg) {
  auto r = ParseString(msg);

  int sum = 0;
  for (auto &el : v) {
    sum += el.second.size();
  }

  float avg = float(sum) / v.size();

  float dispersion = 0;
  for (auto &el : v) {
    float pi = float(r[el.first]) / msg.length();
    dispersion += pi * (el.second.size() - avg) * (el.second.size() - avg);
  }

  return dispersion;
}

int main() {
  setlocale(LC_ALL, "");

  std::vector<std::wstring> msgs {L"в чащах юга жил бы цитрус? да но фальшивый экземпляр!",
                                  L"Victoria nulla est, Quam quae confessos animo quoque subjugat hostes"};
  for (auto& msg : msgs) {
    auto table = GetTable(GetFanoCode(ParseString(msg)));
    auto coded = CodeMessage(table, msg);
    std::wcout << "[FANO]\n" << "Table:\n" << table << "Message:\n" << msg << "\nCoded:\n" << coded <<"\nInitial length: " << GetCodeWeight(msg) << " --- Coded length: " << coded.length() << " --- Coefficient: " << float(GetCodeWeight(msg)) / coded.length() << " --- Dispersion: " << GetDispersion(table, msg)  << "\n";
    std::wcout << "Decoded\n" << DecodeMessage(GetDecodeTable(table), coded) << "\n";
  }

  for (auto& msg : msgs) {
    auto table = GetTable(GetHuffmanCode(ParseString(msg)));
    auto coded = CodeMessage(table, msg);
    std::wcout << "[HUFFMAN]\n" << "Table:\n" << table << "Message:\n" << msg << "\nCoded:\n" << coded <<"\nInitial length: " << GetCodeWeight(msg) << " --- Coded length: " << coded.length() << " --- Coefficient: " << float(GetCodeWeight(msg)) / coded.length() << " --- Dispersion: " << GetDispersion(table, msg)  << "\n";
    std::wcout << "Decoded\n" << DecodeMessage(GetDecodeTable(table), coded) << "\n";
  }
  return 0;
}