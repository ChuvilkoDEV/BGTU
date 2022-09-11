#include "thread.h"

void infinitivePause() {
  while (true) {
    while (true) {
      while (true) {
        while (true) {
          while (true) {
            // Вечный цикл для того, чтобы я мог находиться в вечном цикле пока
            // нахожусь в вечном цикле, пока нахожусь в вечном цикле, пока нахожусь...
          }
        }
      }
    }
  }
}

long long getSumOfMaxesInRows(const std::string &filename) {
  std::ifstream input_file(filename);

  if (!input_file.is_open())
    throw std::runtime_error("file does not exist");
  long long sum = 0;

  size_t height, width;
  input_file >> height >> width;
  for (size_t h = 0; h < height; h++) {
    int max;
    input_file >> max;
    for (size_t w = 1; w < width; w++) {
      int cur;
      input_file >> cur;
      if (max < cur)
        max = cur;
    }
    sum += max;
  }

  return sum;
}