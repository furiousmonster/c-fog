#include <iostream>

using namespace std;


void printArray(int arr[], int size) {
  cout << "start traverse array" << endl;

  for (int i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}


// 1. 指针基本使用
void testBasePtr01() {
  int var = 20; 
  int* p;         // int* 为声明指针

  p = &var;       // p实际为地址， *p为注入地址，找到对应值

  cout << "Value of var variable: ";
  cout << var << endl;

  // 输出在指针变量中存储的地址
  cout << "Address stored in p: ";
  cout << p << endl;

  // 访问指针中地址的值
  cout << "Value of *p: ";
  cout << *p << endl;
}

// 2. 数组与指针
void testArrayPtr() {
  int arr[] = {1, 2, 3, 4, 5};
  int* p = arr;

  cout << "arr traverse: " << endl;
  int i = 0;
  while (i < 5) {
    cout << *p << ' ';
    i++;
    p++; // 地址加sizeof(int*)个字节，指向下一个元素
    (*p)++; //*p 操作元素
  }
  cout << endl;

  cout << "current p is " << p << " *p is " << *p << endl;
  p++;
  cout << *p << endl;
  p++;
  cout << *p << endl;
  p++;
  cout << *p << endl;

  for (int j = 0; j < 5; j++) {
    cout << arr[j] << ' ';
  }
  
}


// 3. 二维数组指针

void print2DArray(int** p, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << p[i][j] << ' ';
    }
    cout << endl;
  }
}



void test2DArrayPtr() {
  // 2行4列
  // int** p = new int*[2];
  // for (int i = 0; i < 2; i++) {
  //   p[i] = new int[4];
  // }
  // print2DArray(p, 2, 4);

  // 二维数组指针指向
  // int arr[2][4] = {{1,2,3,4}, {5,6,7,8}};
  // cout << arr << endl; //0x61fdd0
  // cout << arr[0] << endl; //0x61fdd0
  // cout << arr[0][0] << endl; //1

  // cout << arr + 1 << endl; //0x61fde0
  // cout << (arr + 1)[0] << endl; //0x61fde0
  // cout << (arr + 1)[0][0] << endl; //5

  // 二维数组赋值给指针
  int arr[2][4] = {{1,2,3,4}, {5,6,7,8}};
  int (*p)[4] = arr;
  cout << p[0][0] << endl;
}


// 4. 指针的参数传递
int* getArr() {
  static int arr[5] = {1, 2, 3, 4, 5}; // 必须是static
  // int arr[5] = {1, 2, 3, 4, 5}; // 报错，临时变量不能返回
  return arr;
}


void ptrOp(int* p) {
  (*p)++;
}

void ptrOp2(int& p) {
  p++;
}

void ptrOp3(int* p) {
  // p为指向a的地址，*p即可得到数据a
  (*p)++;
}

void ptrOp4(int* &p) {
  // 传递的是指针的副本，不会改变原来的p
  p += 2;
}

// void testPtrTramsfer() {
//   /** 返回指针 */ 
   
//   int* p;
//   p = getArr();
//   printArray(p, 5);

//   /** 指针传递和引用传递 */ 
   
//   int a = 10;
//   int* p2;
//   p2 = &a;
//   cout << *p2 << endl;

//   ptrOp(p2);
//   cout << *p2 << endl; //11 

//   ptrOp2(a);
//   cout << a << endl; // 12

//   ptrOp3(&a);
//   cout << a << endl; // 12

//   /** 操作指针指向 */
//   int arr[5] = {1, 2, 3, 4, 5};
//   int* p = arr;
//   cout << *p << ' ' << p << endl; // 1 0x61fdd0

//   ptrOp3(p);
//   cout << *p << ' ' << p << endl; // 2 0x61fdd0

//   ptrOp4(p);
//   cout << *p << ' ' << p << endl; // 3 0x61fdd8

// }


int main() {
  // testBasePtr01();

  // testArrayPtr();

  test2DArrayPtr();

  // testPtrTramsfer();

  return 0;
}