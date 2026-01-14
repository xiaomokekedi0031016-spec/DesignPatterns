#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
不用建造者模式：
- 没有 Builder
- 没有 Director
- 由普通函数直接负责对象的构建过程

不用建造者模式：构建逻辑和业务代码混在一起(逻辑代码负责流程和规则，业务代码负责含义和变化)
用建造者模式：把“怎么造”和“造什么”彻底分离构建流程可复用
*/

/*
模式	       -----------     本质
工厂模式	   -----------     创建“哪一个对象”
建造者模式	   -----------     对象“如何一步一步构建”
*/

// ================= 产品类 =================

// 桑尼号
class SunnyShip
{
public:
    void addParts(const string& part)
    {
        m_parts.push_back(part);
    }

    void showParts() const
    {
        for (const auto& p : m_parts)
        {
            cout << p << "  ";
        }
        cout << endl;
    }

private:
    vector<string> m_parts;
};

// 梅丽号
class MerryShip
{
public:
    void assemble(const string& partName, const string& partType)
    {
        m_parts[partType] = partName;
    }

    void showParts() const
    {
        for (const auto& p : m_parts)
        {
            cout << p.first << " : " << p.second << "  ";
        }
        cout << endl;
    }

private:
    map<string, string> m_parts;
};

// ================= 构建函数（直接组装） =================

// -------- 桑尼号 --------
SunnyShip* createSunnyShipSimple()
{
    SunnyShip* ship = new SunnyShip;
    ship->addParts("船体是神树亚当");
    ship->addParts("可乐驱动的内燃机");
    return ship;
}

SunnyShip* createSunnyShipStandard()
{
    SunnyShip* ship = createSunnyShipSimple();//逻辑
    ship->addParts("狮吼炮");//业务
    return ship;
}

SunnyShip* createSunnyShipRegal()
{
    SunnyShip* ship = createSunnyShipStandard();
    ship->addParts("非常豪华的内室装修");
    return ship;
}

// -------- 梅丽号 --------
MerryShip* createMerryShipSimple()
{
    MerryShip* ship = new MerryShip;
    ship->assemble("优质木材", "船体");
    ship->assemble("烧煤的蒸汽机", "动力系统");
    return ship;
}

MerryShip* createMerryShipStandard()
{
    MerryShip* ship = createMerryShipSimple();
    ship->assemble("普通的四门大炮", "武器系统");
    return ship;
}

MerryShip* createMerryShipRegal()
{
    MerryShip* ship = createMerryShipStandard();
    ship->assemble("非常豪华的内室装修", "内室");
    return ship;
}

// ================= 测试代码 =================

int main06()
{
    cout << "桑尼号（豪华型）：" << endl;
    SunnyShip* sunny = createSunnyShipRegal();
    sunny->showParts();
    delete sunny;

    cout << "-----------------------------" << endl;

    cout << "梅丽号（标准型）：" << endl;
    MerryShip* merry = createMerryShipStandard();
    merry->showParts();
    delete merry;

    return 0;
}
