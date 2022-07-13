#include <queue>
#include <iostream>
#include <vector>

using namespace std;


void testBaseHeap() {
  priority_queue<int> pque;

  pque.push(3);
  pque.push(4);
  pque.push(2);
  pque.push(1);

  cout << pque.top() << endl;
  pque.pop();
  cout << pque.top() << endl;

  cout << pque.empty() << endl;
  cout << pque.size() << endl;

  pque.emplace(0);
  cout << pque.top() << endl;

}


// void mergeSortedArray() {
//   vector<int> arr1 = {7, 5, 4, 3, 1};
//   vector<int> arr2 = {9, 7, 5, 4, 2};
//   vector<int> arr3 = {8, 3, 2, 1, 0};
// }


int main() {
  testBaseHeap();

  return 0;
}