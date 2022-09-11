#include <iostream>
#include <vector>

int *getmem(size_t partSize) {
  return new int[partSize];
}

std::vector<int *> getParts(int nParts, size_t partSize) {
  std::vector<int *> result(nParts);
  try {
    for (auto &part: result)
      part = getmem(partSize);
  } catch (std::bad_alloc &error) {
    for (auto &part: result)
      free(part);
    throw;
  }
  return result;
}

int main() {
  int nParts;
  size_t partSize;
  std::cin >> nParts >> partSize;
  try {
    auto result = getParts(nParts, partSize);

    for (auto &part: result)
      free(part);
  } catch (std::bad_alloc &error) {
    std::cerr << error.what();
  } catch (std::length_error &error) {
    if (nParts < 0)
      std::cerr << "nParts < 0 \n";
    std::cerr << error.what();
  }

  return 0;
}