#include "helloworld.h"
#include "messenger.h"

HelloWorld::HelloWorld() {}
HelloWorld::~HelloWorld() {}

std::string HelloWorld::getMessage(Messenger* messenger) const
{
    return messenger->getMessage();
}
