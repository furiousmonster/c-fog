#include <bits/stdc++.h>

/**
 * 初始化：
 * 普通成员：类内/花括号（c11支持）；初始化列表；构造函数
 * 静态成员：类外初始化
 *   static const 成员：一般类外初始化。如果是int可以类内初始化
 * const: 可以类内赋值。或采用初始化列表
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



class Base2 {
private:
    // 类内不初始化，const除外
    static int a;
public:
    static int b;

    static const int sc = 1;
    const std::string ss = "abc";


    const int c = 5; // 类内const 初始化方式
    // const int d(6);
    
};


int main() {
    test1();
}