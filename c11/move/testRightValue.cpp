#include <iostream>
#include <vector>
#include <cstring>

using namespace std;



/**
 * 右值
 *    看能不能对表达式取地址，如果能，则为左值，否则为右值
 * 
 * 生命周期
 *    getTemp()返回的右值本来在表达式语句结束后，其生命也就该终结了（因为是临时变量），
 *    而通过右值引用，该右值又重获新生，其生命期将与右值引用类型变量a的生命期一样，
 *    只要a还活着，该右值临时变量将会一直存活下去。实际上就是给那个临时变量取了个名字。
 * 
 * 常量左值引用
 *    可以绑定任意值，但不能修改
 */ 


void testRightValue01() {
  int a = 10; 
  int& refA = a; // refA是a的别名， 修改refA就是修改a, a是左值，左移是左值引用
  // int& b = 1; //编译错误! 1是右值，不能够使用左值引用
  cout << "origin refA = " << refA << " a = " << a << endl;
  cout << "---refA = 20---" << endl;
  refA = 20;
  cout << "changed refA = " << refA << " a = " << a << endl;

  const int & cona = 1; //常量左值引用绑定右值
  cout << "const int & cona = " << cona << endl;
}


class A {
public:
  int a = 10;
  A(int aa) : a(aa) {
    cout << "construt func execute" << endl;
  }
};

A getTemp() {
  A a(20);
  return a;
}

void getInt(int* p) {
  *p = 1234;
}

char* getString(char *s) {
  s = (char*)"abcde";
  return s;
}


void testRightValue02() {
  A as = getTemp(); //也对
  cout << "A.a = " << as.a << endl;

  A&& a = getTemp();   //getTemp()的返回值是右值（临时变量）
  cout << "A.a = " << a.a << endl;

  int c = 20;
  int *p = &c;
  cout << "*p = " << *p << endl;
  getInt(p);
  cout << "*p = " << *p << endl; // 没问题

  char* p2 = (char*)malloc(sizeof(char*)*10);
  // char p2[20];

  memset(p2, 'a', 10);
  cout << p2 << endl;

  p2 = getString(p2);
  cout << p2 << endl; //abcde

}


void testCstring() {
  char str[50];

  strcpy(str,"This is string.h library function");
  puts(str);

  memset(str,'$',7);
  puts(str);
}



class MyString
{
public:
    static size_t CCtor; //统计调用拷贝构造函数的次数
    static size_t MCtor; //统计调用移动构造函数的次数
    static size_t CAsgn; //统计调用拷贝赋值函数的次数
    static size_t MAsgn; //统计调用移动赋值函数的次数

public:
  // 构造函数
  MyString(const char* cstr=0){
    if (cstr) {
      m_data = new char[strlen(cstr)+1];
      strcpy(m_data, cstr);
    }
    else {
      m_data = new char[1];
      *m_data = '\0';
    }
  }

  // 拷贝构造函数
  MyString(const MyString& str) {
    CCtor ++;
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
  }

  // 移动构造函数
  MyString(MyString&& str) noexcept
    :m_data(str.m_data) {
    MCtor ++;
    str.m_data = nullptr; //不再指向之前的资源了
  }

  // 拷贝赋值函数 =号重载
  MyString& operator=(const MyString& str){
    CAsgn ++;
    if (this == &str) // 避免自我赋值!!
      return *this;

    delete[] m_data;
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
    return *this;
  }

  // 移动赋值函数 =号重载
  MyString& operator=(MyString&& str) noexcept{
    MAsgn ++;
    if (this == &str) // 避免自我赋值!!
      return *this;

    delete[] m_data;
    m_data = str.m_data;
    str.m_data = nullptr; //不再指向之前的资源了
    return *this;
  }

  ~MyString() {
    delete[] m_data;
  }

  char* get_c_str() const { return m_data; }
private:
  char* m_data;
};
size_t MyString::CCtor = 0;
size_t MyString::MCtor = 0;
size_t MyString::CAsgn = 0;
size_t MyString::MAsgn = 0;


void testMoveConstruct() {
  vector<MyString> vecStr;
  vecStr.reserve(1000); //先分配好1000个空间
  for(int i=0;i<1000;i++){
      vecStr.push_back(MyString("hello"));
  }
  cout << "CCtor = " << MyString::CCtor << endl;
  cout << "MCtor = " << MyString::MCtor << endl;
  cout << "CAsgn = " << MyString::CAsgn << endl;
  cout << "MAsgn = " << MyString::MAsgn << endl;

  cout << "----拷贝构造函数----" << endl;
  vector<MyString> vecStr2;
  vecStr2.reserve(1000); //先分配好1000个空间
  for(int i=0;i<1000;i++){
      MyString tmp("hello");
      vecStr2.push_back(tmp); //调用的是拷贝构造函数
  }
  cout << "CCtor = " << MyString::CCtor << endl;
  cout << "MCtor = " << MyString::MCtor << endl;
  cout << "CAsgn = " << MyString::CAsgn << endl;
  cout << "MAsgn = " << MyString::MAsgn << endl;

  cout << endl;

  cout << "----move移动构造函数----" << endl;
  MyString::CCtor = 0;
  MyString::MCtor = 0;
  MyString::CAsgn = 0;
  MyString::MAsgn = 0;

  vector<MyString> vecStr3;
  vecStr3.reserve(1000); //先分配好1000个空间
  for(int i=0;i<1000;i++){
    MyString tmp("hello");
    vecStr3.push_back(std::move(tmp)); //调用的是移动构造函数
  }
  cout << "CCtor = " << MyString::CCtor << endl;
  cout << "MCtor = " << MyString::MCtor << endl;
  cout << "CAsgn = " << MyString::CAsgn << endl;
  cout << "MAsgn = " << MyString::MAsgn << endl;
}


// 完美转发
void process(int& i){
  cout << "process(int&):" << i << endl;
}
void process(int&& i){
  cout << "process(int&&):" << i << endl;
}

void myforward(int&& i){
  cout << "myforward(int&&):" << i << endl;
  process(i); //传的时左值i
}

void myforward2(int&& i){
  // 实现了右值转换，但左值就无法处理
  cout << "myforward(int&&):" << i << endl;
  process(std::forward<int>(i));
}


void testPerfectForward() {
  int a = 0;
  process(a); //a被视为左值 process(int&):0
  process(1); //1被视为右值 process(int&&):1
  process(move(a)); //强制将a由左值改为右值 process(int&&):0
  myforward(2);  //右值经过forward函数转交给process函数，却称为了一个左值，
  //原因是该右值有了名字  所以是 process(int&):2
  myforward(move(a));  // 同上，在转发的时候右值变成了左值  process(int&):0
  // forward(a) // 错误用法，右值引用不接受左值
}


// 通用转发
void RunCode(int &&m) {
    cout << "rvalue ref" << endl;
}
void RunCode(int &m) {
    cout << "lvalue ref" << endl;
}
void RunCode(const int &&m) {
    cout << "const rvalue ref" << endl;
}
void RunCode(const int &m) {
    cout << "const lvalue ref" << endl;
}

// 这里利用了universal references，如果写T&,就不支持传入右值，而写T&&，既能支持左值，又能支持右值
template<typename T>
void perfectForward(T && t) {
    RunCode(forward<T> (t));
}

template<typename T>
void notPerfectForward(T && t) {
    RunCode(t);
}


void testPerfectForward2() {
  int a = 0;
  int b = 0;
  const int c = 0;
  const int d = 0;

  notPerfectForward(a); // lvalue ref
  notPerfectForward(move(b)); // lvalue ref
  notPerfectForward(c); // const lvalue ref
  notPerfectForward(move(d)); // const lvalue ref

  cout << endl;
  perfectForward(a); // lvalue ref
  perfectForward(move(b)); // rvalue ref
  perfectForward(c); // const lvalue ref
  perfectForward(move(d)); // const rvalue ref
}


int main() {
  // testRightValue01();
  // testRightValue02();

  // testCstring();

  // testMoveConstruct();

  // testPerfectForward();
  testPerfectForward2();


  return 0;
}