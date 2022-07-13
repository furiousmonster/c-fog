#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;


void testStringBase01() {
  string str;
  string str1 = "i am";
  string str2 = " hlz";

  str = str1 + str2;
  cout << str << endl;

  cout << "---str.find(hlz)---" << endl;
  int i = str.find("hlz");
  cout << i << ' ' << str[i] << endl;

  cout << "string.size is " << str.size() << endl;

  string sub = str.substr(5, 3); // hlz
  cout << "--str.substr(i, len) is " << sub << endl;

  cout << "---str.append(str)---" << endl;
  str.append(" dy");
  cout << str << endl;

  cout << "---str.insert(i, str)---" << endl;
  str.insert(8, " love");
  cout << str << endl;

  cout << "---str.erase(i, len)---" << endl;
  str.erase(8);
  cout << str << endl;


}


void testStringConvert() {
  string str = "1234";

  int i = stoi(str);
  cout << "int i = " << typeid(i).name() << ' ' << i << endl;

  double d = stod(str);
  cout << "double d = " << typeid(d).name() << ' ' << d << endl;

}



int main() {
  // testStringBase01();

  testStringConvert();

  return 0;
}