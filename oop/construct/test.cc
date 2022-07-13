#include <bits/stdc++.h>

/**
 * 初始化：
 */

class Base1 {
public:
    int a = 5; // c11 后支持类内初始化
    std::string s{"abc"};
};

void test1() {
    Base1 b1;

    std::cout << "a = " << b1.a << std::endl;
    std::cout << "s = " << b1.s << std::endl;
}