#include <iostream>

template <typename T>
class Parent {
public:
    Parent(T p)
    {
        this->p = p;
    }

private:
    T p;
};

/**
 * 如果子类不是模板类，需要指定父类的具体类型
 */
class ChildOne : public Parent<int> {
public:
    ChildOne(int a, int b)
        : Parent(b)
    {
        this->cone = a;
    }

private:
    int cone;
};

/**
 * 如果子类是模板类，可以用子类的泛型表示父类
 */
template <typename T>
class ChildTwo : public Parent<T> {
public:
    ChildTwo(T a, Tb)
        : Parent<T>(b)
    {
        this->ctwo = a;
    }

private:
    T ctwo;
};

/********************************** 分割线 ******************************************/
