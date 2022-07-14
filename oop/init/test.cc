#include <bits/stdc++.h>

/**
 * 不同成员初始化：
 *      普通成员：类内/花括号（c11支持）；初始化列表；构造函数
 *      static成员：类外初始化
 *      static const 成员：一般类外初始化。如果是int可以类内初始化
 *      const: 可以类内赋值。或采用初始化列表
 *      constexpr: 可以类内赋值。或采用初始化列表
 * 
 * 不同的初始化方式：
 *      类内直接赋值：=/{}
 *      类外赋值
 *      构造函数初始化列表
 *      构造函数赋值
 */

// 1. c11 类内直接初始化 以及 initializer_list 测试
class Base1 {
public:
    int a = 5; // c11 后支持类内初始化
    std::string s{"abc"};
    void print(std::initializer_list<int> list) {
        for (auto it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
};

void test1() {
    Base1 b1;
    std::cout << "a = " << b1.a << std::endl;
    std::cout << "s = " << b1.s << std::endl;
    std::cout << "print list: ";
    b1.print({1, 2, 3});
}


// 2. static和const初始化测试
class Base2 {
private:
    // static必须类外初始化
    static int a;
public:
    static int geta() {
        return a;
    }
    const int b = 5; // 类内const var初始化
    static constexpr double sc{1.2};
    const std::string ss = "abc";
    
};
int Base2::a = 2;

void test2() {
    Base2* b = new Base2();
    std::cout << "static a = " << b->geta() << std::endl;
    std::cout << "const b = " << b->b << std::endl;
    std::cout << "static const sc = " << b->sc << std::endl;
    std::cout << "const ss = " << b->ss << std::endl;
    delete b;
}


// 3. 构造函数初始化列表
class Base3 {
private:
    static int total;
public:
    int age;
    int id;
    const std::string name;
};


// 4. 构造函数初始化


int main() {
    std::cout << ">>>>>>>c11 类内直接初始化 以及 initializer_list 测试" << std::endl;
    test1();
    std::cout << ">>>>>>>static和const初始化测试" << std::endl;
    test2();

}