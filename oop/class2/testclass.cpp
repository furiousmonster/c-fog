/**
 * 1. typedef 普通别名和指针别名
 *    struct 
 * 
 * 2. malloc new 野指针
 * 
 * 3. class
 *    构造、拷贝构造  继承访问
 * 
 * 
 * 5. 函数重载重写 - √
 *    虚函数与纯虚函数区别
 *    什么函数不可以是虚函数  - 非类成员函数
 *                          - 静态函数
 *                          - 构造函数
 *    
 *    动态绑定 - 当使用基类的引用或指针调用一个虚函数时将发生动态绑定
 *             - 可以将派生类的对象赋值给基类的指针或引用，反之不可
 * 
 *    虚析构函数 -虚析构函数是为了解决基类的指针指向派生类对象，并用基类的指针删除派生类对象。 
 *              -基类指针指向子类，删除基类指针时，遇到虚析构函数，先调用子类析构函数**
 * 
 * 6. 什么可以是纯虚函数
 * 
 * 
 * 7. 虚继承与虚表
 * 
 * 
 * 
 */ 


#include<bits/stdc++.h>

using namespace std;


// 1. struct typedef 普通别名和指针别名
typedef struct student
{
    /* data */
    char *name;
    int age;
    char score;
} inform, *Pform;


void testStructAndNew() {
  Pform p = new inform; // 指针struct
  p->age = 18;
  p->name = (char*)"abc";
  p->score = 'A';
  printf(p->name);
  delete p;
  p = NULL;
  printf(p->name);

  // inform p;   // 对象strcut
  // p.age = 18;
  // p.name = (char*)"abc";
  // // p.name = "abc"; //"abc" 是  string constant
  // p.score = 'A';
  // printf(p.name);
}



// 2. malloc
struct type{
	int a;
	int b;
};

void testMalloc() {
	type *T = (type*)malloc(sizeof(type));//分配一个有着type大小的内存区域 并将这个地址返回为type指针类型 
	T->a = 0;
	T->b = 0;
	cout<<T->a<<" "<<T->b<<endl;
	
	
	type A, *t = &A;
  // type *t; //要是不先声明A来给t的地址进行初始化 t就是一个野指针 访问野指针会有无法预计的后果 
	t->a = 1;
	t->b = 1;
	cout<< t->a <<" "<< t->b <<endl;
}



// 3. class与继承综合
class person {
private:
  int age;

protected:
  int protectedAge;

public:
  int publicAge;

  person() {
    cout << "construction function execute" << endl;
  }

  person(int a) : age(a) {
    cout << "parameter construction function execute" << endl;
  }

  person(person& p) {
    cout << "copy construction function execute" << endl;
  }

  void setAge(int sage) {
    this->age = sage;
  }

  void getAge() {
    // cout<<"sage="<<sage<<endl;
    cout<<"age="<<age<<endl;
  }

  ~person() {
    cout << "destroyed construction function execute" << endl;
  }

};

/**
 * 默认是private继承
 * 子类访问父类
 *    父类private不能访问
 *    父类protect可以内部访问，不能通过对象访问
 *    都能访问则双public
 * 
 * 
 */ 
class childPersion : public person {
public:
  childPersion() {
    cout << "执行子类构造函数" << endl;
  }

  void visitProtect(int age) {
    protectedAge = age;
    cout << "protectedAge is " << protectedAge << endl;
  }


  ~childPersion() {
    cout << "执行子类析构函数" << endl;
  }
};


void testClass() {
  // childPersion* p = new childPersion;

  // 3-1 公有继承, 可以通过对象访问
  // p->setAge(6); 
  // p->publicAge = 6;
  // cout << p->publicAge << endl;

  // p->protectedAge = 6; //不可通过对象访问protected
  // p->visitProtect(2); // 通过内部函数访问

  // cout<< p->age << endl; //子类不能访问父类的private


  // 3-2 拷贝构造
  person *p = new person;
  person* p2(p);

  delete p;
}



void testNewMalloc() {
  //Person p1; //栈区开辟
  
  /** 
   * 堆区开辟
   * 所有new出来的对象，都会返回该类型的指针
   * 
   * malloc返回void*还要强转
   * malloc不会调用构造 new会调用构造
   * new运算符，malloc是函数
   * 
   */ 
  person *p2 = new person;
  delete p2;
  p2 = nullptr;

  // 当用void* 接受new出来的指针，会出现释放的问题
  // void *p = new person;
  // delete p; //无法释放p deleting 'void*' is undefined


  //new来开辟数组
  //一定会调用默认构造函数,所以一定要提供默认构造
  person *pArray = new person[10];
  delete []pArray;  //释放数组 delete[]必须加上中括号

  //在栈上开辟数组，可以指定有参构造
  //Person pArray2[2] = { Person(1), Person(2) };
  
  
}


class base {
private:
  int baseId;

public:
  virtual void getId() = 0;

};


class shape : public base {

};


class triangle : public shape {

};


class rectangle : public shape {

};



void testVirtual() {

}





int main() {


  // 1. struct typedef 普通别名和指针别名
  // testStructAndNew();


  // 2. malloc
  // testMalloc();
  // testNewMalloc();


  // 3. class与继承综合
  testClass();
  // testVirtual();
  // testSmartPtr();



  return 0;
}