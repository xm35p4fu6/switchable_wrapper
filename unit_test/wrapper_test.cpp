#include <swrapper/wrapper.hpp>
#include "gtest.cpp"

#include <algorithm>
#include <iterator>
#include <iostream>
#include <array>
#include <vector>
#include <deque>

using std::array;
using std::vector;
using std::deque;

TEST(wrapper_off, array)
{
    sw::wrapper<array<int, 5>> arr;
    arr[4] = 10;
    std::cout << arr[5] << std::endl;
}


TEST(wrapper_on, array)
{
    sw::wrapper<array<int, 5>, true> arr;
    arr[4] = 10;
    arr.set_upper(1);
    std::cout << arr[4] << std::endl;
}

TEST(wrapper_off, vector)
{
    sw::wrapper<vector<int>, false> vec = {1, 2, 3, 4, 5};
    vec.resize(2);
    vec[4] = 10;
    std::cout << vec[4] << std::endl;

    sw::wrapper<vector<int>, true> vec2(vec);
    std::cout << std::boolalpha << (vec2 == vec) << std::endl;
}

TEST(wrapper_on, vector)
{
    sw::wrapper<vector<int>, true> vec = {1, 2, 3, 4, 5};
    vec.resize(2);
    vec[4] = 10;
    std::cout << vec[4] << std::endl;
}

TEST(wrapper_off, deque)
{
    sw::wrapper<deque<int>, false> deq {{1, 2, 3, 4, 5}};
    deq.resize(2);
    deq[4] = 10;
    std::cout << deq[4] << std::endl;
}

TEST(wrapper_on, deque)
{
    sw::wrapper<deque<int>, true> deq {{1, 2, 3, 4, 5}};
    deq.resize(2);
    deq[4] = 10;
    std::cout << deq[4] << std::endl;
}

TEST(wrapper_s_off, array)
{
    sw::wrapper_s<array<int, 5>> arr;
    arr[4] = 10;
    std::cout << arr[5] << std::endl;
}
TEST(wrapper_s_on, array)
{
    sw::wrapper_s<array<int, 5>, true> arr;
    arr[2] = 10;
    arr.set_special(0, 2, 4);
    std::cout << arr[2] << std::endl;
}

TEST(wrapper_s_off, vector)
{
    sw::wrapper_s<vector<int>, false> vec = {1, 2, 3, 4, 5};
    vec.resize(2);
    vec[4] = 10;
    std::cout << vec[4] << std::endl;
}

TEST(wrapper_s_on, vector)
{
    sw::wrapper_s<vector<int>, true> vec = {1, 2, 3, 4, 5};
    vec.set_special(2, 4);
    vec[4] = 10;
    std::cout << vec[4] << std::endl;
}

TEST(wrapper_s_off, deque)
{
    sw::wrapper_s<deque<int>, false> deq {{1, 2, 3, 4, 5}};
    deq.resize(2);
    deq[4] = 10;
    std::cout << deq[4] << std::endl;
}

TEST(wrapper_s_on, deque)
{
    sw::wrapper_s<deque<int>, true> deq  {{1, 2, 3, 4, 5}};
    deq.resize(10);
    deq.set_special(3, 4, 5);
    
    auto svec = deq.get_special();
    std::copy(svec.begin(), svec.end(), std::ostream_iterator<int>(std::cout));

    deq[4] = 10;
    std::cout << deq[4] << std::endl;
}

