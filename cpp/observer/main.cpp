#include <iostream>
#include "observer.h"

class DataDefine : public observer::BaseObserverProtocol
{
public:
    virtual void IODataTriggered(unsigned int code, int value) {}
};

class Publisher
{
private:
protected:
public:
    Publisher(/* args */){};
    virtual ~Publisher(){};

    virtual void publish(unsigned int code, int value)
    {
        std::cout << "Publisher publish code: " << code << " value: " << value << std::endl;
        observer::ObserverManager::notify(&DataDefine::IODataTriggered, 1, 1);
    }
};

class Subscriber1 : public DataDefine
{
private:
protected:
public:
    Subscriber1(/* args */){};
    virtual ~Subscriber1(){};

    virtual void IODataTriggered(unsigned int code, int value)
    {
        std::cout << "Subscriber1 receive code: " << code << " value: " << value << std::endl;
    }
};

class Subscriber2 : public DataDefine
{
private:
protected:
public:
    Subscriber2(/* args */){};
    virtual ~Subscriber2(){};

    virtual void IODataTriggered(unsigned int code, int value)
    {
        std::cout << "Subscriber2 receive code: " << code << " value: " << value << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    Publisher publisher;
    Subscriber1 subscriber1;
    Subscriber2 subscriber2;
    observer::ObserverManager::subscribe<DataDefine>(&subscriber1);
    observer::ObserverManager::subscribe<DataDefine>(&subscriber2);

    publisher.publish(1, 1);

    return 0;
}
