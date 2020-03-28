#include <algorithm>

#include "nvg.h"

template <typename T>
void shellsort(const T first, const T last) {
  auto n = last - first;
  auto h = 1;
  while (h < n / 3) {
    h = h * 3 + 1;
  }
  for (; h >= 1; h /= 3) {
    std::cout << "h = " << h << std::endl;
    for (auto i = first + h; i < last; ++i) {
      for (auto k = i; k >= first + h && *k < *(k - h); k -= h) {
        std::swap(*k, *(k - h));
      }
      nvg::printElementsInRange(first, last);
    }
  }
}

int main() {
  auto v = std::string{"EASYSHELLSORTQUESTION"};
  shellsort(v.begin(), v.end());
}
