#include <vector>
#include <iostream>
#include <algorithm>

void testLambda01() {
  std::vector<int> some_list;
  int total = 0;
  for (int i = 0; i < 5; ++i) some_list.push_back(i);

  std::for_each(begin(some_list), end(some_list), [&total](int x) { total += x;});
  std::cout << total << std::endl;
}


template<typename T>
void printVec(std::vector<T> vec) {
  for (const T& v : vec) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
}


void testLambda02() {
  std::vector<int> arr = {4, 5, 3, 6, 2, 7, 1};
  std::sort(arr.begin(), arr.end(), [](int a, int b){return a >= b;});
  printVec(arr);

}


int main() {
  testLambda01();
  testLambda02();

  return 0;
}

