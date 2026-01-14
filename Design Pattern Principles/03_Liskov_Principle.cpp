#include <iostream>
// 里氏替换原则

#if 0
class Bird {
public:
    virtual void fly() {
        std::cout << "Flying in the sky" << std::endl;
    }
    virtual ~Bird() = default;
};

class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow flying" << std::endl;  // 麻雀可以飞
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::logic_error("Penguins can't fly!");  // 破坏了父类的行为！ >> 企鹅不会飞
    }
};
#endif

#include <iostream>
#include <stdexcept>

class Bird {
public:
    virtual void eat() {
        std::cout << "Eating..." << std::endl;
    }
    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    virtual void fly() {
        std::cout << "Flying in the sky" << std::endl;
    }
};

class FlightlessBird : public Bird {
public:
    virtual void walk() {
        std::cout << "Walking on ground" << std::endl;
    }
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        std::cout << "Sparrow flying high" << std::endl;
    }
};

class Penguin : public FlightlessBird {
public:
    void swim() {
        std::cout << "Penguin swimming" << std::endl;
    }
};

// 使用
void makeBirdFly(FlyingBird* bird) {
    bird->fly();
}

int main03() {
    Sparrow sparrow;
    makeBirdFly(&sparrow);  //正常工作

    Penguin penguin;
    penguin.swim();  //企鹅做自己擅长的事
    // makeBirdFly(&penguin);  //编译错误！类型不匹配

    return 0;
}