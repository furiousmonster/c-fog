#include <iostream>

using namespace std;


void printArray(int arr[], int size) {
  cout << "start traverse array" << endl;

  for (int i = 0; i < size; i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}


void sort(int* arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        arr[j] = arr[j] + arr[j + 1];
        arr[j + 1] = arr[j] - arr[j + 1];
        arr[j] = arr[j] - arr[j + 1];
      }
    }
  }
}


void testBaseArray01() {
  // 声明：指定size
  int arr[5];

  // 初始值
  cout << "---arr 初始值为 ----" << arr[0] << endl;

  // 直接初始化，可省略size
  int arr2[] = {3, 4, 5, 6, 1, 2, 3, 7, 8, 9};

  // 遍历
  // 必须指定数组大小
  int size = sizeof(arr2) / sizeof(arr2[0]);
  cout << "array size is " << size <<endl;
  printArray(arr2, size);
}


void test2DArray() {
  // 初始化
  int a[2][4] = {  
    {0, 1, 2, 3} ,
    {4, 5, 6, 7} , 
  };

  int b[][4] = {0, 1, 2, 3, 4, 5, 6, 7}; // 和上面等价，最高维可以省略

  cout << b[1][1] << endl;
}

// 动态数组
int* getDynamicArray(int* arr, int n) {
  arr = new int[n];
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
  return arr;
}

int insert_arr(int *arr, int pos, int x, int n){
	for (int i = n - 1; i >= pos ; i--) arr[i + 1] = arr[i];
	arr[pos] = x;
	return n + 1; 
}


int delete_arr(int *arr, int pos, int n){
  for (int i = 0; i < n; i++) arr[i] = arr[i + 1];
  return n - 1;
}


void testDyanmicArray() {
  // 增删
  /**
   * c++ 数组大小不能更改
   * 方法一 申请新数组，循环将原来数组赋值
   * 方法二 申请数组时申请较大大小, 用一个size记录当前
   */ 
  int* arr;
  arr = getDynamicArray(arr, 10);
  cout << "request array is " << endl;
  printArray(arr, 10);

  int use_count = 5;
  for (int i = 0; i < use_count; i++) arr[i] = i;
  cout << "init array is " << endl;
  printArray(arr, use_count);

  // 增加元素
  int insert_number = 7;
  use_count = insert_arr(arr, use_count, insert_number, use_count);
  cout << "inserted array is " << endl;
  printArray(arr, use_count);

  // 删除元素
  int delete_number_pos = 2;
  use_count = delete_arr(arr, delete_number_pos, use_count);
  cout << "deleted array is " << endl;
  printArray(arr, use_count);

}


void testSort() {
  int arr[10] = {3, 4, 5, 6, 1, 2, 3, 7, 8, 9};
  sort(arr, 10);
  printArray(arr, 10);
}



int main() {
  testBaseArray01();

  test2DArray();

  testDyanmicArray();

  testSort();

  return 0;
}