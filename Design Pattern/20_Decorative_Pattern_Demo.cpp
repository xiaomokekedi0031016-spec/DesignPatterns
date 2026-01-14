#include <iostream>
#include <string>
#include <memory> 

using namespace std;

class Phone {
public:
	virtual ~Phone() = default;
	virtual void SendMessage() {};
	virtual void Call() {};
	virtual void Charging() {};
	virtual void addFeature() {};//添加新功能

private:
};

class ApplePhone : public Phone {
public:
	void SendMessage() override {
		cout << "ApplePhone SendMessage" << endl;
	}
	void Call() override {
		cout << "ApplePhone Call" << endl;
	}
	void Charging() override {
		cout << "ApplePhone Charging" << endl;
	}
};

class MiPhone :public Phone {
public:
	void SendMessage() override {
		cout << "MiPhon SendMessage" << endl;
	}
	void Call() override {
		cout << "MiPhon Call" << endl;
	}
	void Charging() override {
		cout << "MiPhon Charging" << endl;
	}
};
//...todo

//装饰器基类
class PhoneDecorator : public Phone {
public:
	void enchantment(Phone* phone) {
		_phone = phone;
	}
	void addFeature()override {
		cout << "装饰器启动..." << endl;
	}
protected:
	Phone* _phone = nullptr;
};

class BluetoothDecorator : public PhoneDecorator {
public:
	void Connect() {
		cout << "[蓝牙模块] 设备已连接" << endl;
	}
	void addFeature()override {
		_phone->addFeature();
		Connect();
	}
};

class GPSDecorator : public PhoneDecorator {
public:
	void Location() {
		cout << "[GPS模块] 定位成功：北纬30度" << endl;
	}
	void addFeature()override {
		_phone->addFeature();
		Location();
	}
};

class RapidChargingDecorator : public PhoneDecorator {
public:
	void FastCharging() {
		cout << "[快充模块] 电压提升至 20V" << endl;
	}

	void addFeature()override {
		_phone->addFeature();
		FastCharging();

	}
};

class CameraDecorator : public PhoneDecorator {
public:
	void VideoCall() {
		cout << "[摄像头模块] 视频画面已开启" << endl;
	}

	void addFeature()override {
		_phone->addFeature();
		VideoCall();

	}

};

int main() {
	cout << "基础小米手机功能：" << endl;
	Phone* myPhone = new MiPhone();
	myPhone->Call();
	myPhone->Charging();

	cout << "添加功能后小米手机：" << endl;
	PhoneDecorator* blue = new BluetoothDecorator;
	PhoneDecorator* gps = new GPSDecorator;
	PhoneDecorator* rapid = new RapidChargingDecorator;
	PhoneDecorator* camer = new CameraDecorator;
	blue->enchantment(myPhone);
	gps->enchantment(blue);
	rapid->enchantment(gps);
	camer->enchantment(rapid);
	camer->addFeature();

	delete blue;
	delete gps;
	delete rapid;
	delete camer;
	delete myPhone;

	return 0;
}