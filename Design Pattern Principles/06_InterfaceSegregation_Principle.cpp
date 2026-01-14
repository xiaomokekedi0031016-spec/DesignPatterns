//接口隔离原则
#if 0
//一个大接口包含所有能力 >> err
#include <iostream>
//臃肿的接口：所有动物都必须实现所有方法
class Animal {
public:
    virtual void walk() = 0;
    virtual void swim() = 0;
    virtual void fly() = 0;
    virtual ~Animal() = default;
};

// 狗：可以走和游泳，但不会飞
class Dog : public Animal {
public:
    void walk() override {
        std::cout << " Dog is walking" << std::endl;
    }

    void swim() override {
        std::cout << " Dog is swimming" << std::endl;
    }

    void fly() override {//err
        // 狗不会飞！但被迫实现这个方法
        std::cout << "Dog can't fly!" << std::endl;
    }
};

// 鱼：只会游泳
class Fish : public Animal {
public:
    void walk() override {
        // 鱼不会走路//err
        std::cout << "Fish can't walk!" << std::endl;
    }

    void swim() override {
        std::cout << " Fish is swimming" << std::endl;
    }

    void fly() override {
        //  鱼不会飞//err
        std::cout << " Fish can't fly!" << std::endl;
    }
};

// 鸟：可以走和飞，但不会游泳
class Bird : public Animal {
public:
    void walk() override {
        std::cout << " Bird is walking" << std::endl;
    }

    void swim() override {
        //  鸟不会游泳（大部分）
        std::cout << " Bird can't swim!" << std::endl;
    }

    void fly() override {
        std::cout << " Bird is flying" << std::endl;
    }
};

int main() {
    Dog dog;
    dog.walk();
    dog.swim();
    dog.fly();  //  尴尬！

    return 0;
}
#endif


#include <iostream>

//  把能力拆分成独立的小接口
class Walkable {
public:
    virtual void walk() = 0;
    virtual ~Walkable() = default;
};

class Swimmable {
public:
    virtual void swim() = 0;
    virtual ~Swimmable() = default;
};

class Flyable {
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

//  狗：会走路和游泳
class Dog : public Walkable, public Swimmable {
public:
    void walk() override {
        std::cout << " Dog is walking" << std::endl;
    }

    void swim() override {
        std::cout << " Dog is swimming" << std::endl;
    }
};

//  鱼：只会游泳
class Fish : public Swimmable {
public:
    void swim() override {
        std::cout << " Fish is swimming" << std::endl;
    }
};

//  鸟：会走路和飞
class Bird : public Walkable, public Flyable {
public:
    void walk() override {
        std::cout << " Bird is walking" << std::endl;
    }

    void fly() override {
        std::cout << " Bird is flying" << std::endl;
    }
};

//  鸭子：全能！会走、游、飞
class Duck : public Walkable, public Swimmable, public Flyable {
public:
    void walk() override {
        std::cout << " Duck is walking" << std::endl;
    }

    void swim() override {
        std::cout << " Duck is swimming" << std::endl;
    }

    void fly() override {
        std::cout << " Duck is flying" << std::endl;
    }
};

int main() {
    Dog dog;
    dog.walk();
    dog.swim();
    // dog.fly();  //  编译错误！狗没有 fly() 方法

    Fish fish;
    fish.swim();
    // fish.walk();  //  编译错误！鱼没有 walk() 方法

    Bird bird;
    bird.walk();
    bird.fly();
    // bird.swim();  //  编译错误！鸟没有 swim() 方法

    Duck duck;
    duck.walk();
    duck.swim();
    duck.fly();  //  鸭子全能！

    return 0;
}