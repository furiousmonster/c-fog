#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>

using namespace std;


class runner {
public:
  virtual void run()=0;
};


class swimmer {
public:
  virtual void swim()=0;
};


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

  int getAge() {
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

#endif