#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void printVec(vector<T> vec) {
  for (const T& v : vec) {
    cout << v << ' ';
  }
  cout << endl;
}


void testVector() {
  vector<int> v(10);
  vector<int> v2(5, 1);

  cout << "---vec[0]---" << endl;
  cout << v[0] << ' ' << v.at(0) << endl;

  cout << "---v.size v.capacity---" << endl;
  cout << v.size() << ' ' << v.capacity() << endl;
  v.resize(20);
  cout << v.size() << ' ' << v.capacity() << endl;
  v.reserve(30);
  cout << v.size() << ' ' << v.capacity() << endl;

  cout <<  "---v3(v2), v3.assign---" << endl;
  vector<int> v3 = {1,2,3,4};
  printVec(v3);

  vector<int> v4(v3);
  printVec(v4);

  v4.assign(v2.begin(), v2.end());
  printVec(v4);

  v4.assign(5, 2);
  printVec(v4);


  cout << "---v.push_back, pop_back, front, back---" << endl;
  printVec(v3);
  v3.push_back(5);
  printVec(v3);
  cout << v3.front() << ' ' << v3.back() << endl;
  v3.pop_back();
  printVec(v3);


  cout << "---v.insert v.erase---" << endl;
  v3.insert(v3.begin() + 2, 2, 5);
  printVec(v3);
  v3.erase(v3.begin() + 3);
  printVec(v3);

}


int main() {
  testVector();


  return 0;
}