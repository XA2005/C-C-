#include "stdlib.h"
#include <iostream>
#include "stdio.h"
using namespace std;
int n=0,k=0;
// 声明一个表示矩形的类 Physcis
class Physcis {
    // 数据成员
private: 
         int mechanics;
         int electricity;
         
public:
    int out1 = mechanics, out2 = electricity;
    // 构造函数(使用初始化列表进行赋值）
    Physcis(int M, int E) : mechanics(M), electricity(E) {
        k += 1;
        cout << "第"<<k<<"个构造Physci对象已创建: " << mechanics << "x" << electricity << endl;
    }
    // 拷贝构造函数
    Physcis(const Physcis& pointer) : mechanics(pointer.mechanics), electricity(pointer.electricity) {
        cout << "已拷贝构造对象: " << mechanics << "x" << electricity << endl;
    }
    // 析构函数
    ~Physcis() {
        n += 1;
        cout << "第"<<n<<"个构造Physcis对象已销毁: " << mechanics << "x" << electricity << endl;
    }
    // 成员函数，计算乘积
    int accumulate() const {
        return mechanics * electricity;
    }
    // 友元函数，允许外部直接访问私有数据
    friend void Friend_function(Physcis& pointer);
    // 内联函数
    inline void resize(int Mechanics, int Electricity) {
        mechanics = Mechanics;
        electricity = Electricity;
        cout << "内联函数已调用，" << "mechanics值为: " <<mechanics << ", electricity值为: " << electricity << endl;;
    }
    // 使用 this 指针访问当前对象的数据成员
    void scaleByFactor(int multiple) {
        mechanics *= multiple;
        electricity *= multiple;
        std::cout << "this指针函数已调用，新的值为：" << this->mechanics << "x" << this->electricity << "， 扩大倍数为： " << multiple << std::endl;
    }
    // 静态成员，记录创建的矩形数量
    static int count;
};


// 实现静态成员初始化
int Physcis::count = 0;
// 友元函数实现
void Friend_function(Physcis& pointer) {
    cout << "友元函数已调用，" << "mechanics值为: " << pointer.mechanics << ", electricity值为: " << pointer.electricity << endl;
}
// 重载运算符
Physcis operator+(const Physcis& pointer1, const Physcis& pointer2) {
    return Physcis(pointer1.out1 + pointer2.out2, pointer1. out2+ pointer2.out1);
}


// 纯虚函数，抽象基类
class Math {

public:
    Math() {};
    virtual ~Math() {}
    virtual int number () const = 0; // 抽象方法（纯虚函数）
};


// 继承自 Math 的子类 Algebra
class Algebra : public Math {
private:
    int side;
public:
    Algebra(int s) : side(s) {}
    int number() const override {
        return side * side;
    }
};


int main() {
    int m, e;
    cout<<"请输入electricity的值：";
    scanf_s("%d",&e);
    cout<<"请输入mechanics的值：";
    scanf_s("%d",&m);
    // 创建指向类的指针
    Physcis* pointer = new Physcis(m,e);
    // 访问静态成员
    ++Physcis::count; 
    printf("\n");
    cout<<"count值为："<<pointer->count << endl;
    printf("\n");
    // 调用友元函数
    Friend_function(*pointer); 
    printf("\n");
    // 调用内联函数
    cout << "请重新输入electricity的值：";
    cin>>e;
    cout << "请输入mechanics的值：";
    cin >> m;
    printf("\n");
    pointer->resize(m, e);                                                                                                   
    printf("\n");
    // 显示 this 指针的应用
    pointer->scaleByFactor(2);
    printf("\n");
    // 重载运算符应用
    Physcis rect3 = *pointer + Physcis(3, 4);
    std::cout << "Rect3's accumulate: " << rect3.accumulate() << std::endl;
    printf("\n");
    // 多态和抽象的应用
    Math* array[2] = {new Algebra(5), new Algebra(7)};
    for (auto array : array) {
    std::cout << "accumulate of array: " << array->number() << std::endl;
    }
    // 释放内存
    delete pointer; 
    system("pause");
    return 0;
}
/*以上代码中涵盖了大部分C++面向对象编程中的类相关知识点，
 * 包括但不限于：数据成员、构造函数、析构函数、拷贝构造函数、
 * 成员函数、友元函数、内联函数、this指针、指向类的指针、
 * 静态成员、重载运算符、虚函数以及纯虚函数，
 * 并通过继承、封装、多态和抽象展示了类的设计*/
