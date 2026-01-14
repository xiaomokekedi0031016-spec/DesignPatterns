#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
//当一个对象状态变化时，可以在不修改它的前提下，自动通知并影响多个相关对象(观察者模式的好处)

// 抽象观察者
class Observer1 {
public:
    virtual void update(const string& status) = 0;
    virtual ~Observer1() {}
};

// 短信观察者
class SmsObserver : public Observer1 {
public:
    void update(const string& status) override {
        cout << "发送短信: 订单状态 = " << status << endl;
    }
};

// 邮件观察者
class EmailObserver : public Observer1 {
public:
    void update(const string& status) override {
        cout << "发送邮件: 订单状态 = " << status << endl;
    }
};

// 库存观察者
class StockObserver : public Observer1 {
public:
    void update(const string& status) override {
        cout << "更新库存: 订单状态 = " << status << endl;
    }
};

// 抽象被观察者
class Subject {
public:
    virtual void attach(shared_ptr<Observer1> obs) = 0;
    virtual void detach(shared_ptr<Observer1> obs) = 0;
    virtual void notify() = 0;
    virtual ~Subject() {}
};

// 订单类
class Order : public Subject {
public:
    void attach(shared_ptr<Observer1> obs) override {
        observers.push_back(obs);
    }

    void detach(shared_ptr<Observer1> obs) override {
        observers.erase(
            remove(observers.begin(), observers.end(), obs),
            observers.end()
        );
    }

    void setStatus(const string& status) {
        this->status = status;
        cout << "订单状态改变为: " << status << endl;
        notify();
    }

    void notify() override {
        for (auto& obs : observers) {
            obs->update(status);
        }
    }

private:
    string status;
    vector<shared_ptr<Observer1>> observers;
};

int main() {
    Order order;

    auto sms = make_shared<SmsObserver>();
    auto email = make_shared<EmailObserver>();
    auto stock = make_shared<StockObserver>();

    order.attach(sms);
    order.attach(email);
    order.attach(stock);

    order.setStatus("已发货");
    return 0;
}
