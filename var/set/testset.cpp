#include <set>
#include <unordered_set>
#include <vector>
#include <iostream>

// 统计所有不重复的数字
using namespace std;


template<typename T>
void printSet(set<T>& sset) {
  typename set<T>::iterator it = sset.begin(); // 这里需要声明typename
  while (it != sset.end()) {
    cout << *it << ' ';
    it++;
  }
  cout << endl;
}


void testSet() {
  vector<int> v = {1, 1, 2, 2, 3, 4, 5, 6, 9};
  unordered_set<int> uset;
  set<int> sset;

  cout << "---set.find, count---" << endl;
  for (int& i : v) {
    if (uset.find(i) != uset.end()) {
      cout << "duplicate number is " << i << endl;
      cout << "set[i].count is " << uset.count(i) << endl;
    }
    uset.emplace(i);
    sset.emplace(i);
  }

  cout << "---set is ---" << endl;
  printSet(sset);

  sset.erase(2);
  printSet(sset);

  sset.erase(sset.begin()); //返回下一个元素迭代器
  printSet(sset);

  cout << "set.size is " << sset.size() << endl;
  sset.clear();
  cout << "set.size after clear is " << sset.size() << endl;

}


int main() {
  testSet();

  return 0;
}