#include <iostream>
using namespace std;
//请求沿处理链传递，由多个模块按职责逐个尝试处理，发送者无需关心最终由谁处理。
// 抽象处理者
class Approver {
protected:
    Approver* next = nullptr;
public:
    void setNext(Approver* nextApprover) { next = nextApprover; }
    virtual void processRequest(int days) = 0;
};

// 直属上司
class Supervisor : public Approver {
public:
    void processRequest(int days) override {
        if (days <= 3) {
            cout << "直属上司批准请假 " << days << " 天" << endl;
        }
        else if (next) {
            next->processRequest(days);
        }
    }
};

// 部门经理
class Manager : public Approver {
public:
    void processRequest(int days) override {
        if (days <= 7) {
            cout << "部门经理批准请假 " << days << " 天" << endl;
        }
        else if (next) {
            next->processRequest(days);
        }
    }
};

// 总经理
class GeneralManager : public Approver {
public:
    void processRequest(int days) override {
        if (days <= 30) {
            cout << "总经理批准请假 " << days << " 天" << endl;
        }
        else {
            cout << "请假天数太长，无法批准" << endl;
        }
    }
};

int main16() {
    Supervisor sup;
    Manager mgr;
    GeneralManager gm;

    // 设置责任链
    sup.setNext(&mgr);
    mgr.setNext(&gm);

    sup.processRequest(2);
    sup.processRequest(5);
    sup.processRequest(15);
    sup.processRequest(40);

    return 0;
}
