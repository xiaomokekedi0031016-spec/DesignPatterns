#include <iostream>
#include <vector>
#include <map>
using namespace std;

//不用建造者模式就是：由业务代码直接负责对象的完整构造；
//建造者模式是：把“构造过程”抽象出来，解耦产品和装配步骤。

/*
* 1. 定义船相关的类
* 2. 定义生成器相关的类
* 3. 管理者类 -> 建造不同规格的船
* 4. 编写测试代码
*/

//1.Product
// 定义桑尼号的船
// 存储已经建造好的零部件
class SunnyShip
{
public:
    void addParts(string name)
    {
        m_parts.push_back(name);
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item << "  ";
        }
        cout << endl;
    }
private:
    vector<string> m_parts;
};

// 定义梅丽号的船
class MerryShip
{
public:
    void assemble(string name, string parts)
    {
        m_parts.insert(make_pair(parts, name));
    }
    void showParts()
    {
        for (const auto& item : m_parts)
        {
            cout << item.first << ":" << item.second;
        }
        cout << endl;
    }
private:
    map<string, string> m_parts;
};

//2.抽象建造者（Builder 接口）(抽象逻辑)
// 定义生成器类 - 3
class ShipBuilder
{
public:
    virtual void reset() = 0;
    virtual void buildBody() = 0;
    virtual void buildWeapon() = 0;
    virtual void buildEngine() = 0;
    virtual void buildInterior() = 0;
    virtual ~ShipBuilder() {}
};

//3.具体建造者（Concrete Builder）(逻辑代码)
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder(){
        reset();
    }
    void reset() override{
        m_sunny = new SunnyShip;
    }
    SunnyShip* getSunnyShip(){
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
    }
    void buildBody() override{
        m_sunny->addParts("船体是神树亚当");
    }
    void buildWeapon() override{
        m_sunny->addParts("狮吼炮");
    }
    void buildEngine() override{
        m_sunny->addParts("可乐驱动的内燃机");
    }
    void buildInterior() override{
        m_sunny->addParts("非常豪华的内室装修");
    }
    ~SunnyBuilder(){
        if (m_sunny)
        {
            delete m_sunny;
        }
    }
private:
    SunnyShip* m_sunny;
};

class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    void reset() override
    {
        m_merry = new MerryShip;
    }
    MerryShip* getMerryShip()
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }
    void buildBody() override
    {
        m_merry->assemble("船体是优质木材", "船体");
    }
    void buildWeapon() override
    {
        m_merry->assemble("普通的四门大炮", "武器系统");
    }
    void buildEngine() override
    {
        m_merry->assemble("烧煤的蒸汽机", "动力系统");
    }
    void buildInterior() override
    {
        m_merry->assemble("非常豪华的内室装修", "内室");
    }
    ~MerryBuilder()
    {
        if (m_merry)
        {
            delete m_merry;
        }
    }
private:
    MerryShip* m_merry;
};

// 4.定义管理者
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }

    // 简约型
    void buildSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void buildStandardShip()
    {
        buildSimpleShip();
        m_builder->buildWeapon();
    }

    // 豪华型
    void buildRegalShip()
    {
        buildStandardShip();
        m_builder->buildInterior();
    }

private:
    ShipBuilder* m_builder = nullptr;
};

// 测试代码(业务代码)
// 建造桑尼号
void buildSunnyShip()
{
    Director* director = new Director;//管理者
	SunnyBuilder* builder = new SunnyBuilder;//具体建造者

    // 简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    SunnyShip* ship = builder->getSunnyShip();
    ship->showParts();
    delete ship;

    //// 标准型
    //builder->reset();
    //director->buildStandardShip();
    //ship = builder->getSunnyShip();
    //ship->showParts();
    //delete ship;

    //// 豪华型
    //builder->reset();
    //director->buildRegalShip();
    //ship = builder->getSunnyShip();
    //ship->showParts();
    //delete ship;
    delete builder;
    delete director;
}

// 建造梅利号
// 建造桑尼号
void buildMerryShip()
{
    Director* director = new Director;
    MerryBuilder* builder = new MerryBuilder;

    // 简约型
    director->setBuilder(builder);
    director->buildSimpleShip();
    MerryShip* ship = builder->getMerryShip();
    ship->showParts();
    delete ship;

    // 标准型
    builder->reset();
    director->buildStandardShip();
    ship = builder->getMerryShip();
    ship->showParts();
    delete ship;

    // 豪华型
    builder->reset();
    director->buildRegalShip();
    ship = builder->getMerryShip();
    ship->showParts();
    delete ship;
    delete builder;
    delete director;
}

#if 1
int main05()
{
    //buildMerryShip();
    //cout << "===============================" << endl;
    buildSunnyShip();
    return 0;
}
#endif