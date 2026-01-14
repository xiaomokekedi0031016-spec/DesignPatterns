#include <iostream>
#include <memory>
using namespace std;
//每个策略（算法或行为）封装在独立的类中，主类只依赖抽象接口

// 抽象策略
class IFightStrategy {
public:
    virtual void attack() = 0;
    virtual ~IFightStrategy() {}
};

// 一档攻击策略
class FirstGear : public IFightStrategy {
public:
    void attack() override {
        cout << "使用一档橡胶拳攻击" << endl;
    }
};

// 二档攻击策略
class SecondGear : public IFightStrategy {
public:
    void attack() override {
        cout << "使用二档橡胶炮攻击" << endl;
    }
};

// 三档攻击策略
class ThirdGear : public IFightStrategy {
public:
    void attack() override {
        cout << "使用三档橡胶火箭攻击" << endl;
    }
};

// 四档攻击策略
class FourthGear : public IFightStrategy {
public:
    void attack() override {
        cout << "使用四档橡胶巨人攻击" << endl;
    }
};

// 路飞类
class Luffy {
private:
    shared_ptr<IFightStrategy> strategy;
public:
    void setStrategy(shared_ptr<IFightStrategy> s) {
        strategy = s;
    }
    void fight() {
        if (strategy)
            strategy->attack();
        else
            cout << "使用普通攻击" << endl;
    }
};

int main14() {
    Luffy luffy;

    shared_ptr<IFightStrategy> croc = make_shared<FirstGear>();
    shared_ptr<IFightStrategy> lucci = make_shared<ThirdGear>();
    shared_ptr<IFightStrategy> kaido = make_shared<FourthGear>();

    // 动态选择技能
    luffy.setStrategy(croc);
    luffy.fight();

    luffy.setStrategy(lucci);
    luffy.fight();

    luffy.setStrategy(kaido);
    luffy.fight();

    return 0;
}
