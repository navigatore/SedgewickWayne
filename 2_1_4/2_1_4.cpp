#include <algorithm>

#include "nvg.h"

template <typename T>
void insertionSort(const T first, const T last) {
  for (auto it = first + 1; it != last; ++it) {
    for (auto revIt = it; revIt != first && *revIt < *(revIt - 1); --revIt) {
      std::swap(*revIt, *(revIt - 1));
    }

    nvg::printElementsInRange(first, last);
  }
}

int main() {
  auto v = std::string{"EASYQUESTION"};
  insertionSort(v.begin(), v.end());
}
