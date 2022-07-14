#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>


using namespace std;


void testException01() {
  // 退出时会自动释放程序所使用的资源，但运行期间不会自动释放
  // bad alloc new时内存不足
  try {
     char* p = new char[0x7fffffff];  //无法分配这么多空间，会抛出异常, 实际没有抛出
    // delete[] p;
  }
  // catch (bad_alloc & e)  {
  catch (exception e) {
    cerr << e.what() << endl;
  }
}


void testException02() {

  vector<int> v(10);
  try {
    v.at(100) = 100;  //拋出 out_of_range 异常
  }
  catch (out_of_range & e) {
    cerr << e.what() << endl;
  }

  string s = "hello";
  try {
    char c = s.at(100);  //拋出 out_of_range 异常
  }
  catch (out_of_range & e) {
    cerr << e.what() << endl;
  }

}


void testException03() {
  int m, n;
  cin >> m >> n;
  try {
    if (n == 0) throw -1;
    if (m % n != 0) throw -1.0;

    int res = m / n;
    cout << "m / n = " << res << endl;
  } catch (int e) {
    cerr << e << " n cannot be 0" << endl;
  } catch (double e) {
    cerr << e << " m / n is not int" << endl;
  }
}


void testException04() {

}


void testException05() {

}


int main() {
  // testException01();
  // testException02();
  testException03();
  // testException04();
  // testException05();

  // system("pause");
  return 0;
}