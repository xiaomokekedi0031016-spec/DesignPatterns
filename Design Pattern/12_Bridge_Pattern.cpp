#include <iostream>
using namespace std;
//如果增加新的形状（如三角形）或者新的颜色（如绿色），类的数量会 成倍增长，代码会变得难维护(不使用桥接模式)

// ---- 实现部分（颜色接口） ----
class Color {
public:
    virtual void fill() = 0;
    virtual ~Color() {}
};

class Red : public Color {
public:
    void fill() override { cout << "红色" << endl; }
};

class Blue : public Color {
public:
    void fill() override { cout << "蓝色" << endl; }
};

// ---- 抽象部分（形状接口） ----
class Shape {
protected:
    Color* color; // 桥接到颜色
public:
    Shape(Color* c) : color(c) {}
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle(Color* c) : Shape(c) {}
    void draw() override {
        cout << "画圆形，颜色: ";
        color->fill();
    }
};

class Rectangle : public Shape {
public:
    Rectangle(Color* c) : Shape(c) {}
    void draw() override {
        cout << "画矩形，颜色: ";
        color->fill();
    }
};

int main12() {
    Color* red = new Red();
    Color* blue = new Blue();

    Shape* circle1 = new Circle(red);
    Shape* circle2 = new Circle(blue);

    Shape* rect1 = new Rectangle(red);

    circle1->draw(); // 画圆形，颜色: 红色
    circle2->draw(); // 画圆形，颜色: 蓝色
    rect1->draw();   // 画矩形，颜色: 红色

    delete red;
    delete blue;
    delete circle1;
    delete circle2;
    delete rect1;

    return 0;
}
