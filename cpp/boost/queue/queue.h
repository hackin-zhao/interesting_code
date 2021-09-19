#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <boost/bind.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/threadpool.hpp>

struct TestNode {
    int id;
    char name[64];
    TestNode()
    {
        memset(this, 0, sizeof(TestNode));
    }
};

class TestQueue {
public:
    TestQueue();
    ~TestQueue();
    boost::lockfree::queue<struct TestNode, struct boost::lockfree::fixed_sized<false> > que;
};

#endif /* _QUEUE_H_ */
