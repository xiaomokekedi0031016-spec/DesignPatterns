#if 0
#include <iostream>
using namespace std;

// 短信服务
class SmsService {
public:
    void send(string msg) {
        cout << "发送短信: " << msg << endl;
    }
};

// 邮件服务
class EmailService {
public:
    void send(string msg) {
        cout << "发送邮件: " << msg << endl;
    }
};

// 库存服务
class StockService {
public:
    void update(string msg) {
        cout << "更新库存: " << msg << endl;
    }
};

// 订单类（不使用观察者模式）
class Order {
public:
    Order() {
        sms = new SmsService();
        email = new EmailService();
        stock = new StockService();
    }

    ~Order() {
        delete sms;
        delete email;
        delete stock;
    }

    void setStatus(string status) {
        cout << "订单状态改变为: " << status << endl;

        //强耦合，逐个调用
        sms->send(status);
        email->send(status);
        stock->update(status);
    }

private:
    SmsService* sms;
    EmailService* email;
    StockService* stock;
};

int main17() {
    Order order;
    order.setStatus("已支付");
    return 0;
}
#endif