#include <iostream>
using namespace std;
//迪米特法则

#if 0
class Stock {
public:
    void decrease(int count) {
        cout << "库存减少 " << count << endl;
    }
};

class Product {
public:
    Stock* getStock() {
        return &stock;
    }
private:
    Stock stock;
};

class Order {
public:
    Product* getProduct() {
        return &product;
    }
private:
    Product product;
};

class OrderService {
public:
    void createOrder(Order* order) {
        // 链式调用，知道太多内部细节
        order->getProduct()->getStock()->decrease(1);
    }
};
#endif

#include <iostream>
using namespace std;

class Stock {
public:
    void decrease(int count) {
        cout << "库存减少 " << count << endl;
    }
};

class Product {
public:
    void reduceStock(int count) {
        stock.decrease(count);
    }
private:
    Stock stock;
};

class Order {
public:
    void deductStock() {
        product.reduceStock(1);
    }
private:
    Product product;
};

class OrderService {
public:
    void createOrder(Order* order) {
        //  只和直接朋友 Order 交互
        order->deductStock();
    }
};
