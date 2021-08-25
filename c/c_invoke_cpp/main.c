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

#include <stdio.h>
#include "cpp_wapper.h"

int main(int argc, char const *argv[])
{
    struct cpp_example_wapper_t *p = get_instance();
    call_cpp_example_function(p, 10);
    printf("%d\n", call_cpp_example_function_overload(p, 5, 5));
    release_instance(&p);

    struct namespace_cpp_example_wapper_t *namespace_p = get_instance_namespace();
    call_cpp_example_function_namespace(namespace_p, 10);
    printf("%d\n", call_cpp_example_function_namespace_overload(namespace_p, 5, 5));
    release_instance_namespace(&namespace_p);

    return 0;
}
