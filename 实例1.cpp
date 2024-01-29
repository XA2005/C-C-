#include <iostream>

// 声明一个表示矩形的类 Rectangle
class Rectangle {
 // 数据成员
private: int width;
         int height;
public:
    int a=width,b=height;
    // 构造函数
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Constructing a rectangle with dimensions: " << width << "x" << height << std::endl;
    }
    // 拷贝构造函数
    Rectangle(const Rectangle &other) : width(other.width), height(other.height) {
        std::cout << "Copying a rectangle with dimensions: " << width << "x" << height << std::endl;
    }
    // 析构函数
    ~Rectangle() {
        std::cout << "Destructing a rectangle with dimensions: " << width << "x" << height << std::endl;
    }
    // 成员函数，计算面积
    int area() const {
        return width * height;
    }
    // 友元函数，允许外部直接访问私有数据
    friend void displayDimensions(Rectangle &rect);
    // 内联函数，提高效率
    inline void resize(int newWidth, int newHeight) {
        width = newWidth;
        height = newHeight;
    }
    // 使用 this 指针访问当前对象的数据成员
    void scaleByFactor(int factor) {
        width *= factor;
        height *= factor;
        std::cout << "Scaled rectangle (" << this->width << "x" << this->height << ") by a factor of " << factor << std::endl;
    }
    // 静态成员，记录创建的矩形数量
    static int count;
};

// 实现静态成员初始化
int Rectangle::count = 0;
// 友元函数实现
void displayDimensions(Rectangle &rect) {
    std::cout << "Width: " << rect.width << ", Height: " << rect.height << std::endl;
}
// 重载运算符
Rectangle operator+(const Rectangle &rect1, const Rectangle &rect2) {
    return Rectangle(rect1.a + rect2.a, rect1.b + rect2.b);
}

// 纯虚函数，抽象基类
class Shape {
public:
    virtual ~Shape() {}
    virtual int getArea() const = 0; // 抽象方法（纯虚函数）
};

// 继承自 Shape 的子类 Square
class Square : public Shape {
private:
    int side;

public:
    Square(int s) : side(s) {}

    int getArea() const override {
        return side * side;
    }
};

int main() {
    // 创建指向类的指针
    Rectangle* rectPtr = new Rectangle(5, 10);
    ++Rectangle::count; // 访问静态成员

    displayDimensions(*rectPtr); // 调用友元函数
    rectPtr->resize(8, 12); // 调用内联函数

    // 显示 this 指针的应用
    rectPtr->scaleByFactor(2);

    // 重载运算符应用
    Rectangle rect3 = *rectPtr + Rectangle(3, 4);
    std::cout << "Rect3's area: " << rect3.area() << std::endl;

    // 多态和抽象的应用
    //Shape* shapes[2] = {new Square(5), new Rectangle(3, 4)};
    //for (auto shape : shapes) {
    //    std::cout << "Area of shape: " << shape->getArea() << std::endl;
    //}

    delete rectPtr; // 释放内存
    scanf_s("%d");
    return 0;
}

/*以上代码中涵盖了大部分C++面向对象编程中的类相关知识点，
 * 包括但不限于：数据成员、构造函数、析构函数、拷贝构造函数、
 * 成员函数、友元函数、内联函数、this指针、指向类的指针、
 * 静态成员、重载运算符、虚函数以及纯虚函数，
 * 并通过继承、封装、多态和抽象展示了类的设计特点。*/