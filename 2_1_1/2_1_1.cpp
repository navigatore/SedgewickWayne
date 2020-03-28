#include <algorithm>
#include <iostream>

template <typename T>
void printAll(const T first, const T last) {
  for (auto i = first; i != last; ++i) {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void selectionSort(const T first, const T last) {
  for (auto writeIt = first; writeIt != last; ++writeIt) {
    auto minIt = writeIt;
    for (auto readIt = writeIt + 1; readIt != last; ++readIt) {
      if (*readIt < *minIt) {
        minIt = readIt;
      }
    }
    printAll(first, last);
    std::swap(*writeIt, *minIt);
  }
}

int main() {
  auto v = std::string{"EASYQUESTION"};
  selectionSort(v.begin(), v.end());
}
