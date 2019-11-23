#include <vector>
#include <algorithm>
int sumOfDifferences(const std::vector<int>& arr) {
  if (arr.empty()) return 0;
  auto p = std::minmax_element(arr.cbegin(), arr.cend());
  return *p.second - *p.first;
}