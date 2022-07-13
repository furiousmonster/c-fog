#ifndef HLZBASE_H
#define HLZBASE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void printOneDVector(vector<T> v) {
  for (const T& i : v) {
    cout<<i<<' ';
  }
  cout<<endl;
};


template<typename T>
void printTwoDVector(vector<vector<T>>& vs) {
  for (const auto& v : vs) { 
    for (const T& i : v) {
      cout<<i<<' ';
    }
    cout<<endl;
  }
 
};



#endif