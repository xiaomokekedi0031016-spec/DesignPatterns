#include <iostream>
using namespace std;
//是否使用适配器的分水岭就在客户端：如果客户端需要判断“你是谁”，就该用适配器了
//不用适配器 -> main（或调用方）里必须“区分对象类型 / 写翻译逻辑”
//用适配器 -> main 完全不用区分，只管调用统一接口

//不使用适配器模式的代码
#include <iostream>
#include <string>
using namespace std;

class Foreigner
{
public:
    virtual string confession() = 0;
    void setResult(string msg)
    {
        cout << "Panda Say: " << msg << endl;
    }
    virtual ~Foreigner() {}
};

// 美国人
class American : public Foreigner
{
public:
    string confession() override
    {
        return string("我是畜生, 我有罪!!!");
    }
};

// 法国人
class French : public Foreigner
{
public:
    string confession() override
    {
        return string("我是强盗, 我该死!!!");
    }
};

// 熊猫
class Panda
{
public:
    void recvMessage(string msg)
    {
        cout << msg << endl;
    }
    string sendMessage()
    {
        return string("强盗、凶手、罪人是不可能被宽恕和原谅的！");
    }
};

int main08()
{
    // ===== 美国人 =====
    {
        Foreigner* human = new American;
        Panda panda;

        // 人 -> 熊猫（main 里硬编码“翻译逻辑”）
        string msg = human->confession();
        panda.recvMessage("美国人说: " + msg);

        // 熊猫 -> 人（main 再写一遍）
        string back = panda.sendMessage();
        human->setResult("美国佬, " + back);

        delete human;
    }

    cout << "------------------------" << endl;

    // ===== 法国人 =====
    {
        Foreigner* human = new French;
        Panda panda;

        // 又复制一套逻辑，只是文字不同
        string msg = human->confession();
        panda.recvMessage("法国人说: " + msg);

        string back = panda.sendMessage();
        human->setResult("法国佬, " + back);

        delete human;
    }

    return 0;
}
