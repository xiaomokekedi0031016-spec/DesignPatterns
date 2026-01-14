#if 0
#include <iostream>
#include <string>

class PaymentProcessor {
public:
    void processPayment(const std::string& type, double amount) {
        if (type == "credit_card") {
            std::cout << "Processing credit card:  $" << amount << std::endl;
        }
        else if (type == "paypal") {
            std::cout << "Processing PayPal: $" << amount << std::endl;
        }
        else if (type == "bitcoin") {  // 新增需求，要修改这个类！
            std::cout << "Processing Bitcoin:  $" << amount << std::endl;
        }
    }
};
#endif

// 开闭原则
#include <iostream>
#include <memory>

// 抽象基类
class Payment {
public:
    virtual void process(double amount) = 0;
    virtual ~Payment() = default;
};

// 具体实现
class CreditCardPayment : public Payment {
public:
    void process(double amount) override {
        std::cout << "Processing credit card: $" << amount << std::endl;
    }
};

class PayPalPayment : public Payment {
public:
    void process(double amount) override {
        std::cout << "Processing PayPal:  $" << amount << std::endl;
    }
};

class BitcoinPayment : public Payment {  // 新增功能，不需要修改原有代码！
public:
    void process(double amount) override {
        std::cout << "Processing Bitcoin:  $" << amount << std::endl;
    }
};

// 使用
class PaymentProcessor {
public:
    void processPayment(Payment* payment, double amount) {
        payment->process(amount);
    }
};

// 示例
int main02() {
    PaymentProcessor processor;

    CreditCardPayment cc;
    PayPalPayment pp;
    BitcoinPayment btc;

    processor.processPayment(&cc, 100.0);
    processor.processPayment(&pp, 200.0);
    processor.processPayment(&btc, 300.0);

    return 0;
}