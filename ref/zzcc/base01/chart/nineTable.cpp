#include <iostream>
 
using namespace std;
 
int main(int argc, char **argv){
    
  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= i; j++){
      cout << j << "*" << i << "=" << j * i << " ";
    }
    cout << endl;
  }
}