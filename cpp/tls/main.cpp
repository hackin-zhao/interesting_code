/**
 *  The MIT License (MIT)
 *  Copyright (c) 2021 hackin zhao
 */

#include <iostream>
#include <future>
#include <vector>
#include <chrono>
#include <random>

thread_local std::default_random_engine dre;

std::vector<int> test_dre(int seed)
{
    dre.seed(seed);
    int vecSize = 10;
    std::vector<int> temp(vecSize);
    for (int i = 0; i < vecSize; ++i)
    {
        temp[i] = dre();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << __FUNCTION__ << " thread id: " << std::this_thread::get_id() << std::endl;

    return temp;
}

bool equal(const std::vector<int> &v1, const std::vector<int> &v2)
{
    int size1 = v1.size();
    int size2 = v2.size();
    if (size1 != size2)
        return false;

    for (int i = 0; i < size1; ++i)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

int main()
{
    int numThread = 2;

    std::cout << __FUNCTION__ << " thread id: " << std::this_thread::get_id() << std::endl;

    std::future<std::vector<int>> future1 = std::async(test_dre, 0);
    std::vector<int> result2 = test_dre(0);
    std::vector<int> result1 = future1.get();

    if (equal(result1, result2))
        std::cout << "they are equal" << std::endl;
    else
        std::cout << "they are not equal" << std::endl;

    return 0;
}
