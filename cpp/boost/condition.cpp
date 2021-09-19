#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

using namespace std;
using namespace boost;
boost::mutex io_mutex;
boost::condition_variable_any test_condition;

void test(int num)
{
	for (;;)
	{
		boost::mutex::scoped_lock lock(io_mutex);
		cout << get_system_time() << ": waiter " << num << " try lock" << endl;
		if (test_condition.timed_wait(lock, get_system_time() + posix_time::seconds(3)))
		{
			 cout << get_system_time() <<": waiter " << num << " have receive notify" << endl;
		} else
		{
			cout << get_system_time() << ": waiter " << num << " have not received notify" << endl;
		}

        cout << get_system_time() << ": this is " << num << " test function" << endl;
	}
}

void notify()
{
    int count = 1;
	while(1)
	{
        sleep(count);
		//test_condition.notify_one();
        test_condition.notify_all();
        cout << get_system_time() << ": sender have send notify, dur:" << count << endl;
        count++;
        if (count>6) {
            count = 1;
        }
	}
}

int main(int argc, char* argv[])
{
	boost::thread thrd11(bind(test, 1));
	boost::thread thrd12(bind(test, 2));
	boost::thread thrd13(notify);
	thrd11.join();
	thrd12.join();
	thrd13.join();

    return 0;
}
////g++ test.cpp -pthread -lboost_system -lboost_thread
