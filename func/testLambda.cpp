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


template<typename T>
void printTwoDVector(std::vector<std::vector<T>>& vs) {
  for (const auto& v : vs) { 
    for (const T& i : v) {
      std::cout<<i<<' ';
    }
    std::cout<<std::endl;
  }
 
};


void testLambda03() {
  std::vector<std::vector<int>> arr = {
    {4, 5, 3},
    {6, 2, 7},
    {8, 9, 1}
  };
  std::sort(arr.begin(), arr.end(), [](std::vector<int> a, std::vector<int> b){return a[0] >= b[0];});
  printTwoDVector(arr);

}


int main() {
  // testLambda01();
  // testLambda02();
  testLambda03();

  return 0;
}

