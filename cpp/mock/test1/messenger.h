#ifndef _MESSENGER_H_
#define _MESSENGER_H_

#include <string>
using namespace std;

class Messenger {
public:
    virtual ~Messenger() {}
    virtual string getMessage() = 0;
};

#endif
