#ifndef HLZMAPSET_H
#define HLZMAPSET_H

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>


/**
 * 
 * 迭代器失效
 * 对于关联容器(如map, set, multimap,multiset)，删除当前的iterator，仅仅会使当前的iterator失效，
 * 只要在erase时，递增当前iterator即可。
 * 这是因为map之类的容器，使用了红黑树来实现，插入、删除一个结点不会对其他结点造成影响。
 * 
 * 
 * 
 * 
 */ 



#endif