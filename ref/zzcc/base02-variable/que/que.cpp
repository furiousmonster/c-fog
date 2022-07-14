#include <queue>
#include <iostream>

using namespace std;


void testBaseQueue() {
  queue<int> que;

  que.push(1);
  que.push(2);
  que.push(3);
  que.push(4);

  cout << que.front() << endl; //1
  cout << que.back() << endl; //4

  que.pop();

  cout << que.empty() << endl; //0
  cout << que.size() << endl; //3

}


int main() {
  testBaseQueue();

  return 0;
}