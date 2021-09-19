#if !defined(_SIMPLE_H_)
#define _SIMPLE_H_

#include <boost/thread/mutex.hpp>

class Simple {
public:
    Simple() {}
    ~Simple() {}

private:
    typedef boost::shared_lock<boost::shared_mutex> readLock;
    boost::unique_lock<boosr::shared_mutex> writeLock;
};

#endif // _SIMPLE_H_
