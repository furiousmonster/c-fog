#include <iostream>
#include <string>

#include "interface.h"

using namespace std;


class person {
private:
  int age;

protected:
  int protectedAge;

public:
  static int total;
  int id;
  string name;
  int publicAge;

  person() {
    cout << "construction function execute" << endl;
  }

  person(int a, string nam) : age(a), name(nam) {
    total++;
    this->id = total;
    cout << "parameter construction function execute" << endl;
  }

  person(const person& p) {
    cout << "copy construction function execute" << endl;
  }

  void setAge(int sage) {
    this->age = sage;
  }

  int getAge() const {
    // cout<<"sage="<<sage<<endl;
    cout<<"age="<<age<<endl;
    return age;
  }

  ~person() {
    cout << "destroyed construction function execute" << endl;
  }

};

int person::total = 0;


class student : public person, public runner, public swimmer {
private:
  int score = 300;

public:
  student() {
    cout << "执行子类构造函数" << endl;
  }

  void visitProtect(int age) {
    protectedAge = age;
    cout << "protectedAge is " << protectedAge << endl;
  }

  void run() {
    cout << "I am a runner, my speed is 10" << endl;
  }

  void swim() {
    cout << "I am a swimmer, my speed is 8" << endl;
  }

  ~student() {
    cout << "执行子类析构函数" << endl;
  }
};



void testClassStatic() {
  person xh(18, "xiaohong");
  person xm(20, "xiaoming");

  cout << "this city has " << person::total << " person" << endl;
  cout << "the " << xh.id << "is" << endl;
  cout << xh.name << ' ' << xh.getAge() << "岁了" << endl;

  cout << "the " << xm.id << "is" << endl;
  cout << xm.name << ' ' << xm.getAge() << "岁了" << endl;
 
}



/**
 * 拷贝构造
 *   person p;
 *   person p2 = p;
 *   person p2(p);
 * 指针创建对象不执行
 */ 
void testClassCopy() {

  // 3-2 拷贝构造1
  person *p = new person(6, "harry");
  person* p2(p); // 不执行拷贝构造

  p->getAge();
  p2->getAge();

  // 一个改动，另一个也会改动
  p2->setAge(7);
  p->getAge();
  p2->getAge();

  delete p;
  p2->getAge();

}


void testClassCopy02() {
  person p;
  // person p2 = p; // 执行拷贝构造
  person p2(p); // 执行拷贝构造

  p2.setAge(7);
  p.getAge(); //0
  p2.getAge(); //7

  // delete p; //错误
}


void testClassCopy03() {
  person* p = new person(6, "harry");
  person* p2 = p; // 不执行拷贝构造

  p2->setAge(7);
  p->getAge(); //7
  p2->getAge(); //7

  delete p;
  p2->getAge(); //无效数字
}


void testClassInherit() {
  student* p = new student;

  // 3-1 公有继承, 可以通过对象访问
  p->setAge(6); 
  p->publicAge = 6;
  cout << p->publicAge << endl;

  // p->protectedAge = 6; //不可通过对象访问protected
  p->visitProtect(2); // 通过内部函数访问

  // cout<< p->age << endl; //子类不能访问父类的private
}


void testInterface() {
  student* p = new student;

  p->run();
  p->swim();

  delete p;
  p = nullptr;
}


int main() {

  // testClassStatic();

  // testClassCopy();
  // testClassCopy02();
  // testClassCopy03();

  // testClassInherit();

  // testInterface();
  return 0;
}