#include <iostream>

template <typename T>
class Complex {
public:
    Complex(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    Complex<T> operator+(Complex& c)
    {
        Complex<T> tmp(this->a + c.a, this->b + c.b);
        return tmp;
    }

private:
    T a;
    T b;
};

int main(int argc, char const* argv[])
{
    Complex<int> a(10, 20);
    Complex<int> b(20, 30);
    Complex<int> c = a + b;

    return 0;
}
