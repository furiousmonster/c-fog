#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>
 
using namespace std;


void download1() {
    cout << "开始下载第一个视频..." << endl;
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        cout << "第一个视频下载进度:" << i << endl;
    }
    cout << "第一个视频下载完成..." << endl;
}


void download2() {
    cout << "开始下载第二个视频..." << endl;
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        cout << "第二个视频下载进度:" << i << endl;
    }
    cout << "第二个视频下载完成..." << endl;
}


void process() {
    cout << "开始处理两个视频" << endl;
}


int main() {
  cout << "主线程开始运行\n";

  std::thread d2(download2);
  download1();

  /**
   * 谁调用了join()函数？
   *    d2这个线程对象调用了join()函数，因此必须等待d2的下载任务结束了，d2.join()函数才能得到返回。
   * d2在哪个线程环境下调用了join()函数？
   *    d2是在主线程的环境下调用了join()函数，因此主线程要等待d2的线程工作做完，否则主线程将一直处于block状态；
   */ 
  d2.join();

  process();
}