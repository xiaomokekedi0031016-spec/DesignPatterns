#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*==========================
  1. 抽象组件：战士
==========================*/
class Soldier
{
public:
    Soldier() {}
    Soldier(string name) : m_name(name) {}
    virtual void fight() = 0;
    string getName() const { return m_name; }
    virtual ~Soldier() {}
protected:
    string m_name;
};

/*==========================
  2. 具体组件：黑胡子
==========================*/
class Teach : public Soldier
{
public:
    Teach(string name) : Soldier(name) {}
    void fight() override
    {
        cout << m_name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

/*==========================
  3. 抽象装饰者：恶魔果实
==========================*/
class DevilFruit : public Soldier
{
public:
    void enchantment(Soldier* soldier)
    {
        m_soldier = soldier;
        m_name = soldier->getName();
    }
protected:
    Soldier* m_soldier = nullptr;
};

/*==========================
  4. 具体装饰者
==========================*/
// 暗暗果实
class DarkFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_soldier->fight();
        cout << m_name
            << "吃了暗暗果实，制造黑洞般的引力攻击敌人..." << endl;
        cout << " 警告：元素化后无法躲避攻击，会承受全部伤害！" << endl;
    }
};

// 震震果实
class QuakeFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_soldier->fight();
        cout << m_name
            << "吃了震震果实，引发空间震动，摧毁一切目标！" << endl;
    }
};

// 大饼果实
class PieFruit : public DevilFruit
{
public:
    void fight() override
    {
        m_soldier->fight();
        cout << m_name
            << "吃了大饼果实，获得大饼铠甲进行防御！" << endl;
        cout << "最强辅助：把周围事物变成大饼，为队友回血！" << endl;
    }
};

/*==========================
  5. 工厂：负责组装装饰链
==========================*/
class DevilFruitFactory
{
public:
    static Soldier* create(
        Soldier* base,
        const vector<string>& fruits
    )
    {
        Soldier* current = base;

        for (auto& f : fruits)
        {
            DevilFruit* fruit = nullptr;

            if (f == "dark")
                fruit = new DarkFruit;
            else if (f == "quake")
                fruit = new QuakeFruit;
            else if (f == "pie")
                fruit = new PieFruit;

            if (fruit)
            {
                fruit->enchantment(current);
                current = fruit;
            }
        }
        return current;
    }
};

/*==========================
  6. 客户端
==========================*/
int main()
{
    // 基础角色
    Soldier* teach = new Teach("黑胡子");

    // 通过工厂组装恶魔果实能力
    Soldier* blackbeard =
        DevilFruitFactory::create(
            teach,
            { "dark", "quake", "pie" }
        );

    cout << "=== 黑胡子战斗开始 ===" << endl;
    blackbeard->fight();

    // 注意：示例中未统一释放内存，真实工程应使用智能指针
    return 0;
}
