#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

int func(int in) { return in + 1; }

int main() {
    auto res = std::async(func, 5);
    // res.wait();
    cout << "这里执行了" << endl;
    cout << res.get() << endl; // 阻塞直到函数返回
    return 0;
}