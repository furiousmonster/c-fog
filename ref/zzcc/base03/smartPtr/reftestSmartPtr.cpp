#include <iostream>
#include <memory>


using namespace std;


struct ClassWrapper {
  ClassWrapper() {
    cout << "construct" << endl;
    data = new int[10];
  }
  ~ClassWrapper() {
    cout << "deconstruct" << endl;
    if (data != nullptr) {
      delete[] data;
    }
  }
  void Print() {
    cout << "print" << endl;
  }
  int* data;
};


void Func(std::shared_ptr<ClassWrapper> ptr) {
  ptr->Print();
}


int main() {
    auto smart_ptr = std::make_shared<ClassWrapper>();
    auto ptr2 = smart_ptr; // 引用计数+1
    ptr2->Print();
    Func(smart_ptr); // 引用计数+1
    smart_ptr->Print();
    ClassWrapper *p = smart_ptr.get(); // 可以通过get获取裸指针
    p->Print();
    return 0;
}