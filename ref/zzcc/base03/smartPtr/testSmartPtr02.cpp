#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>

#include "student.h"

using namespace std;


void testSmartPtr01() {
	std::shared_ptr<int> age(new int(28));
	std::shared_ptr<int> height(new int(160));

  std::cout << "VersionTwo: your age is " << *age << ", and your height is "
            << *height << std::endl;
	// 不需要做任何额外的事情，内存会自动的释放掉
}

void testSmartPtr02() {

	std::shared_ptr<int> age = std::make_shared<int>(35);
	std::shared_ptr<int> height = std::make_shared<int>(160);

  std::cout << "VersionThree: your age is " << *age << ", and your height is "
            << *height << std::endl;
}

void testSharedPtr() {
  // person* pPtr01 = new person(18, "小红"); //不会执行析构函数，必须手动delete
  shared_ptr<person> pPtr01(new person(18, "小红")); //智能指针
  auto pPtr02 = make_shared<person>(20, "小明");

  cout << pPtr01->id << ' ' << pPtr01->name << ' ' << pPtr01->getAge() << "岁了" << endl;
  cout << pPtr02->id << ' ' << pPtr02->name << ' ' << pPtr02->getAge() << "岁了" << endl;

  // 计数
  cout << "pPtr01.get()" << pPtr01.get() << ' ' << "pPtr01.use_count()" << pPtr01.use_count() << endl;
  cout << "pPtr02.get()" << pPtr02.get() << ' ' << "pPtr02.use_count()" << pPtr02.use_count() << endl;

  cout << "---ptr02 = ptr01---" << endl;
  pPtr02 = pPtr01;
  cout << "pPtr01.get()" << pPtr01.get() << ' ' << "pPtr01.use_count()" << pPtr01.use_count() << endl;
  cout << "pPtr02.get()" << pPtr02.get() << ' ' << "pPtr02.use_count()" << pPtr02.use_count() << endl;
  cout << "pPtr01.unique()" << pPtr01.unique() << endl; //引用计数为1则为unique。指向NULL不是unique


  cout << "---pPtr02.reset()---" << endl;
  pPtr02.reset();
  cout << "pPtr01.get()" << pPtr01.get() << ' ' << "pPtr01.use_count()" << pPtr01.use_count() << endl;
  cout << "pPtr01.unique()" << pPtr01.unique() << endl;
  // cout << pPtr02->id << ' ' << pPtr02->name << ' ' << pPtr02->getAge() << "岁了" << endl; //错误，释放了指向的对象

  // swap(pPtr01, pPtr02); //交换
  // auto p = pPtr01.get(); //返回地址
  
}


void testSharedBindPtr() {
  // template<class Y> shared_ptr(shared_ptr<Y> const & a, T * p); 
  // 基本上它与a共享所有权，但b.get()将返回p。 不是a.get()！
  // 即a存在，b就存在
  int* p = new int(10);

	std::shared_ptr<int> a(new int(20));
	std::shared_ptr<int> b(a, p);
  cout << "*b = " << *b << " b.get() " << b.get() << "  b.use_count() " << b.use_count() << endl;
  cout << "*a = " << *a << " a.get() " << a.get() << "  a.use_count() " << a.use_count() << endl;
  cout << "*p = " << *p << endl;

  a.reset();
  
  // delete p;
  // p = nullptr;
  cout << "*b = " << *b << " b.get() " << b.get() << "  b.use_count() " << b.use_count() << endl; //b.use_count() 1

}

int test_shared_ptr_reset_delete() {
	// new int[], with shard_ptr'reset function delete
  // 通过reset对普通指针数组进行删除操作
	int* p1 = new int[10];

  {
    std::for_each(p1, p1 + 10, [](int& v){v = 5; }); //for_each函数
    std::shared_ptr<int> p2;

    // p2和p1指向同一个内存空间
    p2.reset(p1, [](int* p) {delete[] p; });
  
    for (int i = 0; i < 10; ++i) {
      fprintf(stdout, "p1:  %d  \n", p1[i]);
      fprintf(stdout, "p2:  %d  \n", p2.get()[i]);
    }
  }

	// 运行到大括号外，此时p1的空间已经被释放
	for (int i = 0; i < 10; ++i) {
		fprintf(stdout, "p1:  %d  \n", p1[i]);
	}

	//delete[] p1; // p1已释放，不能再delete
 
	int* pa = new int[10];
  {
    std::for_each(pa, pa + 10, [](int& v){v = 8; });

    std::shared_ptr<int> pb;
    // pb和pa指向同一个内存空间
    pb.reset(pa, [](int*) { });
  
    for (int i = 0; i < 10; ++i) {
      fprintf(stdout, "pa:  %d  \n", pa[i]);
      fprintf(stdout, "pb:  %d  \n", pb.get()[i]);
    }
  }

	// 运行到大括号外，此时pa的空间没有被释放
	for (int i = 0; i < 10; ++i) {
		fprintf(stdout, "pa:  %d  \n", pa[i]);
	}

	delete[] pa; // pa没有被释放，需要delete
 
	return 0;
}


// 循环引用
struct A;
struct B;

struct A {
  int a = 10;
  std::shared_ptr<B> bptr;
  ~A() {
    cout << "A delete" << endl;
  }
  void PrintA() {
    cout << "A" << endl;
  }
};

struct B {
  int b = 20;
  std::weak_ptr<A> aptr; // 这里改成weak_ptr
  ~B() {
    cout << "B delete" << endl;
  }
  void PrintB() {
    if (!aptr.expired()) { // expired对象是否解放，A的use_count为0时返回true
      auto ptr = aptr.lock(); // 对象没解放时，返回一个指向A的shared_ptr
      cout << "A.use_count by tmp ptr : " << ptr.use_count() << endl;
      cout << "A.use_count by weak aptr : " << aptr.use_count() << endl;
      ptr->PrintA();
    }
    cout << "A.use_count by weak aptr : " << aptr.use_count() << endl;
  }
};

  
void testWeakPtr() {
   auto aaptr = std::make_shared<A>();
   auto bbptr = std::make_shared<B>();

   aaptr->bptr = bbptr;
   bbptr->aptr = aaptr;

   cout << "A.a = " << aaptr->a << " aaptr.use_count " << aaptr.use_count() << endl; //1
   cout << "B.b = " << bbptr->b << " bbptr.use_count " << bbptr.use_count() << endl; //2

   bbptr->PrintB();
}


void testUniquePtr() {
  // auto ptr = std::unique_ptr<A>(new A);
  unique_ptr<A> ptr = std::make_unique<A>(); // error, c++11还不行，需要c++14
  //std::unique_ptr<A> tem = ptr; // error, unique_ptr不允许移动
  cout << "A.a = " << ptr->a << endl;
  ptr->PrintA();

  // reset delete关联的原始指针并使unique_ptr 对象为空
  // ptr.reset();

  // get
  // A* p = ptr.get();

  // unique_ptr<A> *ptr2 = ptr; //error unique_ptr不能赋值
  cout << "unique_ptr 不能赋值, 通过move函数移动到另一个uniptr中" << endl;
  unique_ptr<A> ptr2 = move(ptr);
  if (ptr == nullptr) cout << "ptr is nullptr" << endl;
  cout << "ptr2.a = " << ptr2->a << endl;

}


void testMove() {
  //move
	std::shared_ptr<int> foo_4;
	std::shared_ptr<int> bar_4(new int(10));
 
	foo_4 = bar_4;                          // copy
  std::cout << "*foo_4: " << *foo_4 << '\n'; //10
	std::cout << "*bar_4: " << *bar_4 << '\n'; //10
 
	bar_4 = std::make_shared<int>(20);   // move
  std::cout << "*foo_4: " << *foo_4 << '\n'; //10
	std::cout << "*bar_4: " << *bar_4 << '\n'; //20
 
	std::unique_ptr<int> unique(new int(30));
	foo_4 = std::move(unique);            // move from unique_ptr
 
	std::cout << "*foo_4: " << *foo_4 << '\n'; //30
	std::cout << "*bar_4: " << *bar_4 << '\n'; //20
}



int main() {

  // testSmartPtr01();
  // testSmartPtr02();


  // testSharedPtr();
  // testWeakPtr();
  // testUniquePtr();

  testMove();

  // test_shared_ptr_reset_delete();
  // testSharedBindPtr();

  return 0;
}
