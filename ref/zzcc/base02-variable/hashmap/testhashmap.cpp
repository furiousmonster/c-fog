#include <unordered_map>
#include <iostream>


using namespace std;

template<typename T1, typename T2>
void printMap(unordered_map<T1, T2> hashmap) {
  for (auto& m : hashmap) {
    cout << m.first << ' ' << m.second << endl;
  }
}


void testHashMap() {
    
  //初始化
  cout << "---init hashmap---" << endl;
  unordered_map<int, int> hashmap;
  unordered_map<int, int> hashmap2 = { {1, 2}, {2, 4} };
  
  // 增
  cout << "---insert element---" << endl;
  int key = 4, value = 8;
  hashmap[key] = value;

  pair<int, int> p(3, 6);
  hashmap.insert(p);

  hashmap.insert(make_pair<int, int>(5, 10));
  hashmap.insert(hashmap2.begin(), hashmap2.end());
  hashmap.insert({{6, 12}, {7, 14}});

  // index
  cout << "---print hashmap[7]---" << endl;
  key = 7;
  cout << hashmap[key] << endl;
  cout << hashmap.at(key) << endl;

  // 遍历
  cout << "---Traverse hashmap---" << endl;
  printMap(hashmap);


  // 查
  cout << "---print hashmap.find(4)---" << endl;
  int target = 4;

  auto it = hashmap.find(target);
  if (it == hashmap.end()) cout << "no target" << endl;
  else cout << it->second << endl;

  // if ((auto it = hashmap.find(target)) != hashmap.end()) cout << it->second;

  if (hashmap.count(target) != 0) cout << hashmap[target] << endl;


  // 改
  cout << "---modify hashmap[4]---" << endl;
  hashmap[4] = 100;
  printMap(hashmap);
  
  // 删
  cout << "hashmap size is " << hashmap.size() << endl;
  hashmap.erase(hashmap.begin());  //通过位置
  hashmap.erase(1);    //通过key
  printMap(hashmap);
  cout << "hashmap size after delete is " << hashmap.size();

    
}

int main() {

  testHashMap();

  return 0;
}