#include <string>
#include <iostream>
//单一职责原则

#if 0
//一个类做太多事情
class User {
private:
    std::string name;
    std::string email;

public:
    User(std::string n, std::string e) : name(n), email(e) {}

    void saveToDatabase() {
        // 保存到数据库
        std::cout << "Saving to database..." << std::endl;
    }

    void sendEmail() {
        // 发送邮件
        std::cout << "Sending email..." << std::endl;
    }

    void generateReport() {
        // 生成报告
        std::cout << "Generating report..." << std::endl;
    }
};
#endif

//每个类只做一件事
class User {
private:
    std::string name;
    std::string email;

public:
    User(std::string n, std::string e) : name(n), email(e) {}

    std::string getName() const { return name; }
    std::string getEmail() const { return email; }
};

class UserRepository {
public:
    void save(const User& user) {
        std::cout << "Saving " << user.getName() << " to database" << std::endl;
    }
};

class EmailService {
public:
    void send(const std::string& to, const std::string& subject) {
        std::cout << "Sending email to " << to << std::endl;
    }
};

class ReportGenerator {
public:
    void generate(const User& user) {
        std::cout << "Generating report for " << user.getName() << std::endl;
    }
};