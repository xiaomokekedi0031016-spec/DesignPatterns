//依赖倒转原则

#if 0
#include <iostream>

//高层直接依赖低层具体实现
class MySQLDatabase {//低层(底层封装好的api)
public:
    void connect() {
        std::cout << "Connecting to MySQL" << std::endl;
    }
};

class UserService {//高层(业务层)
private:
	MySQLDatabase db;  //err >> 直接依赖具体实现 >> 换成redis/oracle你不炸了

public:
    void getUser(int id) {
        db.connect();
        std::cout << "Getting user " << id << std::endl;
    }
};
#endif

#include <iostream>
#include <memory>
//都依赖抽象

// 抽象接口
class Database {
public:
    virtual void connect() = 0;
    virtual ~Database() = default;
};

// 具体实现(低层)
class MySQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connecting to MySQL" << std::endl;
    }
};

class PostgreSQLDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connecting to PostgreSQL" << std::endl;
    }
};

class MongoDBDatabase : public Database {
public:
    void connect() override {
        std::cout << "Connecting to MongoDB" << std::endl;
    }
};

// 高层模块依赖抽象
class UserService {
private:
    Database* db;//依赖抽象

public:
    UserService(Database* database) : db(database) {}

    void getUser(int id) {
        db->connect();
        std::cout << "Getting user " << id << std::endl;
    }
};

// 使用 - 可以轻松切换数据库
int main04() {
    MySQLDatabase mysql;
    PostgreSQLDatabase postgres;
    MongoDBDatabase mongo;

    UserService service1(&mysql);
    service1.getUser(1);

    UserService service2(&postgres);
    service2.getUser(2);

    UserService service3(&mongo);
    service3.getUser(3);

    return 0;
}