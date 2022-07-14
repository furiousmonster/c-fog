
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
std::mutex mutex_;

int main() {
  auto func1 = [](int k) {
      mutex_.lock();
      for (int i = 0; i < k; ++i) {
          cout << i << " ";
    }
      cout << endl;
      mutex_.unlock();
};

  std::thread threads[5];
  for (int i = 0; i < 5; ++i) {
      threads[i] = std::thread(func1, 200);
}
  for (auto& th : threads) {
      th.join();
}
  return 0;
}