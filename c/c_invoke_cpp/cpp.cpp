// The MIT License (MIT)

// Copyright (c) 2021 hackin zhao

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <iostream>

#include "cpp.h"

namespace c_invoke_cpp
{

    NameSpaceCpp::NameSpaceCpp(/* args */)
    {
        std::cout << "construct namespace class NameSpaceCpp" << std::endl;
    }

    NameSpaceCpp::~NameSpaceCpp()
    {
        std::cout << "destruct namespace class NameSpaceCpp" << std::endl;
    }

    int NameSpaceCpp::fun(int i)
    {
        std::cout << "invoke namespace cpp class function" << std::endl;
        return i;
    }

    int NameSpaceCpp::fun(int a, int b)
    {
        std::cout << "invoke namespace cpp class overload function" << std::endl;
        return a + b;
    }

} // namespace c_invoke_cpp

CppExample::CppExample(/* args */)
{
    std::cout << "construct class CppExample" << std::endl;
}

CppExample::~CppExample()
{
    std::cout << "destruct class CppExample" << std::endl;
}

int CppExample::fun(int i)
{
    std::cout << "invoke cpp class function" << std::endl;
    return i;
}

int CppExample::fun(int a, int b)
{
    std::cout << "invoke cpp class overload function" << std::endl;
    return a + b;
}