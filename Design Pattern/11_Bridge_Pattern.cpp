#include <iostream>
using namespace std;

// 形状 + 颜色直接组合
class RedCircle {
public:
    void draw() { cout << "画红色圆形" << endl; }
};

class BlueCircle {
public:
    void draw() { cout << "画蓝色圆形" << endl; }
};

class RedRectangle {
public:
    void draw() { cout << "画红色矩形" << endl; }
};

class BlueRectangle {
public:
    void draw() { cout << "画蓝色矩形" << endl; }
};

int main11() {
    RedCircle rc;
    rc.draw();

    BlueRectangle br;
    br.draw();

    return 0;
}
