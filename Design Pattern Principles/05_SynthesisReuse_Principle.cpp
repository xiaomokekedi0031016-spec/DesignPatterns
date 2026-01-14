#include <string>
#include <memory>

//合成复用原则
//在系统中应该尽量多使用组合和聚合关联(类作为类的成员变量)关系，尽量少使用继承关系
#if 0
class Encryptor {
public:
    void encrypt(std::string& msg);
};

class ChatClient : public Encryptor {//客户端 ≠ 加密器 >> 滥用继承 //err
};
#endif

class Encryptor {
public:
    virtual std::string encrypt(const std::string& msg) = 0;
};

class AESEncryptor : public Encryptor {
public:
    std::string encrypt(const std::string& msg) override {
        return "AES(" + msg + ")";
    }
};

class ChatClient {
public:
    ChatClient(std::unique_ptr<Encryptor> enc)
        : encryptor_(std::move(enc)) {
    }

    void send(const std::string& msg) {
        auto cipher = encryptor_->encrypt(msg);
        // send cipher...
    }

private:
    std::unique_ptr<Encryptor> encryptor_;
};
