#include <boost/ref.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/thread.hpp>
#include <stdio.h>
#include <string.h>

int g_num = 10;
boost::shared_mutex s_mu;

void myread(std::string& str)
{
    const char* c = str.c_str();
    while (1) {
        {
            boost::shared_lock<boost::shared_mutex> m(s_mu);
            printf("%s enter, global num = %d\n", c, g_num);
            boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(1));
            printf("%s out\n", c);
        }
        boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(1));
        boost::this_thread::sleep(boost::posix_time::seconds(1));
    }
}

void mywrite(std::string& str)
{
    const char* c = str.c_str();
    while (1) {
        {
            boost::unique_lock<boost::shared_mutex> m(s_mu);
            ++g_num;
            printf("%s enter, global num = %d\n", c, g_num);
            boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(1));
            printf("%s out\n", c);
        }
        boost::thread::sleep(boost::get_system_time() + boost::posix_time::seconds(3));
    }
}

int main(int argc, char const* argv[])
{
    std::string r1 = "read_1";
    std::string r2 = "read_2";
    std::string w1 = "write_1";
    std::string w2 = "write_2";

    boost::thread_group tg;
    tg.create_thread(bind(myread, boost::ref(r1)));
    tg.create_thread(bind(myread, boost::ref(r2)));
    tg.create_thread(bind(mywrite, boost::ref(w1)));
    tg.create_thread(bind(mywrite, boost::ref(w2)));

    tg.join_all();

    return 0;
}
