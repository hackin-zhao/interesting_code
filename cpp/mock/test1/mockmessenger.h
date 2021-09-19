#ifndef _MOCKMESSENGER_H_
#define _MOCKMESSENGER_H_

#include "messenger.h"
#include <gmock/gmock.h>

using namespace std;

class MockMessenger : public Messenger {
public:
    MOCK_METHOD0(getMessage, string());
};

#endif
