#include <algorithm>
#include <cassert>

template <typename T>
void shellsort(const T first, const T last) {
  static constexpr auto gaps = std::array{1L,
                                          4L,
                                          13L,
                                          40L,
                                          121L,
                                          364L,
                                          1093L,
                                          3280L,
                                          9841L,
                                          29524L,
                                          88573L,
                                          265720L,
                                          797161L,
                                          2391484L,
                                          7174453L,
                                          21523360L,
                                          64570081L,
                                          193710244L,
                                          581130733L,
                                          1743392200L,
                                          5230176601L,
                                          15690529804L,
                                          47071589413L,
                                          141214768240L,
                                          423644304721L,
                                          1270932914164L,
                                          3812798742493L,
                                          11438396227480L,
                                          34315188682441L,
                                          102945566047324L,
                                          308836698141973L,
                                          926510094425920L,
                                          2779530283277761L,
                                          8338590849833284L,
                                          25015772549499853L,
                                          75047317648499560L,
                                          225141952945498681L,
                                          675425858836496044L,
                                          2026277576509488133L,
                                          6078832729528464400L};
  auto n = last - first;

  auto hIter = gaps.cbegin();
  while (*hIter < n / 3) {
    ++hIter;
  }
  for (; hIter >= gaps.cbegin(); --hIter) {
    for (auto i = first + *hIter; i < last; ++i) {
      for (auto k = i; k >= first + *hIter && *k < *(k - *hIter); k -= *hIter) {
        std::swap(*k, *(k - *hIter));
      }
    }
  }
}

int main() {
  auto v1 = std::vector{44, 92, 10, 48, 34,  96, 58, 84, 57, 1,  58, 83, 60,
                        20, 73, 62, 96, 4,   18, 51, 44, 78, 76, 39, 21, 87,
                        29, 45, 81, 71, 89,  88, 24, 73, 89, 57, 27, 38, 75,
                        65, 70, 80, 64, 100, 24, 45, 62, 18, 34, 53};
  auto v2 = v1;

  shellsort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());
  assert((v1 == v2));
}
