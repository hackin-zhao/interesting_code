#include <gtest/gtest.h>
#include <string>
#include <vector>

template <template T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

template <class T>
class Stack
{
  public:
    void push(T const &elem);
    void pop();
    T top() const;
    bool empty() const
    {
        return elems.empty();
    }

  private:
    vector<T> elems;
};
