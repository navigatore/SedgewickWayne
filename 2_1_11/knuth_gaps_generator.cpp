#include <iostream>

#include "nvg.h"

int main() {
  auto h = 1L;
  auto gaps = std::vector{h};
  h = h * 3 + 1;
  while (h / 3 == gaps.back()) {
    gaps.push_back(h);
    h = h * 3 + 1;
  }

  nvg::printElementsInRange(gaps.cbegin(), gaps.cend(), ", ");
}
