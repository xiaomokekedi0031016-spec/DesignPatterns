#include <iostream>
using namespace std;
//装饰器模式 : 处理的是一维
//桥接模式：处理的是二维

// 战士基类
class Soldier
{
public:
    Soldier(string name) : m_name(name) {}
    virtual void fight() = 0;
    virtual ~Soldier() {}

protected:
    string m_name;
};

// 黑胡子（能力写死）
class Teach : public Soldier
{
public:
    Teach(string name) : Soldier(name) {}

    void fight() override
    {
        basicFight();
        darkFruit();
        quakeFruit();
        pieFruit();
    }

private:
    void basicFight()
    {
        cout << m_name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }

    void darkFruit()
    {
        cout << m_name
            << "吃了暗暗果实, 拥有黑洞般的吸引力!" << endl;
        cout << "无法元素化, 会承受全部伤害!" << endl;
    }

    void quakeFruit()
    {
        cout << m_name
            << "吃了震震果实, 引发空间震动, 摧毁目标!" << endl;
    }

    void pieFruit()
    {
        cout << m_name
            << "吃了大饼果实, 获得大饼铠甲!" << endl;
        cout << "最强辅助: 将事物变成大饼, 帮助队友回血!" << endl;
    }
};

int main10()
{
    Soldier* teach = new Teach("黑胡子");
    teach->fight();
    delete teach;
    return 0;
}