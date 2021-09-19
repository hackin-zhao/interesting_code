#include "queue.h"
#include <stdio.h>

using namespace boost;
using namespace boost::threadpool;
using namespace boost::lockfree;

TestQueue::TestQueue()
    : que(0)
{
}

TestQueue::~TestQueue()
{
}

#if 1

TestQueue myqueue;

int ID = 0;
void ThreadSetQueue()
{
    bool ret = false;
    struct TestNode node;
    strcpy(node.name, "hello world");

    while (1) {
        node.id = ID++;
        ret = myqueue.que.push(node);
        boost::thread::sleep(boost::get_system_time() + boost::posix_time::millisec(1000));
    }
}

void ThreadSetQueue2()
{
    bool ret = false;

    struct TestNode node;
    strcpy(node.name, "hello johnny");

    while (1) {
        node.id = ID++;
        ret = myqueue.que.push(node);
        boost::thread::sleep(boost::get_system_time() + boost::posix_time::millisec(500));
    }
}

void ThreadGetQueue()
{
    bool ret = true;
    struct TestNode node;

    while (1) {
        if (myqueue.que.pop(node))
            printf("get ID:%d, name:%s\n", node.id, node.name);
        else
            boost::thread::sleep(boost::get_system_time() + boost::posix_time::millisec(200));
    }
}

//#if 0
int main(int argc, char* atgv[])
{
    pool QueThread(3);
    QueThread.schedule(&ThreadSetQueue);
    QueThread.schedule(&ThreadSetQueue2);
    QueThread.schedule(&ThreadGetQueue);
    QueThread.wait();
    return 0;
}
#endif
