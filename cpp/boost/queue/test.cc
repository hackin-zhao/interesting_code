#include "queue.h"
#include <gtest/gtest.h>
#include <stdio.h>

using namespace boost;
using namespace boost::threadpool;
using namespace boost::lockfree;

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

TEST(GtestQueueTest, ReadWrite)
{
    pool QueThread(3);
    QueThread.schedule(&ThreadSetQueue);
    QueThread.schedule(&ThreadSetQueue2);
    QueThread.schedule(&ThreadGetQueue);
    QueThread.wait();
    EXPECT_EXIT(_exit(1), testing::ExitedWithCode(1), "");
}

// Run all the tests that were declared with TEST()
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
