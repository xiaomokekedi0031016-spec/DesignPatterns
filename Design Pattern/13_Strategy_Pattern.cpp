#include <iostream>
#include <string>
using namespace std;
//不使用策略模式：核心逻辑耦合在方法内部，通过大量 if/else 或 switch 判断不同情况，难以维护

class Luffy {
public:
    void fight(string enemy) {
        if (enemy == "Crocodile") {
            cout << "使用一档橡胶拳攻击 Crocodile" << endl;
        }
        else if (enemy == "Blueno") {
            cout << "使用二档橡胶炮攻击 Blueno" << endl;
        }
        else if (enemy == "Lucci") {
            cout << "使用三档橡胶火箭攻击 Lucci" << endl;
        }
        else if (enemy == "Kaido") {
            cout << "使用四档橡胶巨人攻击 Kaido" << endl;
        }
        else {
            cout << "使用普通攻击" << endl;
        }
    }
};

int main13() {
    Luffy luffy;
    luffy.fight("Crocodile");
    luffy.fight("Lucci");
    luffy.fight("Kaido");

    return 0;
}
