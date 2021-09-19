#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include "messenger.h"
using namespace std;

class HelloWorld {
public:
    HelloWorld();
    virtual ~HelloWorld();
    string getMessage(Messenger* messenger) const;
};

#endif
