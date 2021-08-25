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

#if !defined(_CPP_HPP_)
#define _CPP_HPP_

namespace c_invoke_cpp
{
    class NameSpaceCpp
    {
    private:
        /* data */
    public:
        NameSpaceCpp(/* args */);
        ~NameSpaceCpp();

        int fun(int i);
        int fun(int a, int b);
    };

} // namespace c_invoke_cpp

class CppExample
{
private:
    /* data */
public:
    CppExample(/* args */);
    ~CppExample();

    int fun(int i);
    int fun(int i, int b);
};

#endif // _CPP_HPP_
