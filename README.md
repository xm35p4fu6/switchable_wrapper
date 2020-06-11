# Switchable Wrapper

Switchable Wrapper is a simple, easy-to-use container wrapper providing switchable bounding check.

## Getting Started

### Prerequisites

- C++ compiler that supports c++14 or later.
- need google test if building unit test.
    - [Google Test](https://github.com/google/googletest)
    - [install gtest package](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/)

### Installing

This is a header-only library so that simply include `wrapper.hpp` could work.

## Running the tests

Get in the root of this project and make test.

```
make test
./test
```

## Usage

Check test's code in `unit_test/` for detail.

```cpp
sw::wrapper<vector<T>> vec;  // normal vector
sw::wrapper<vector<T>, false> vec;  // same as above

sw::wrapper<vector<T>, true> vec_on(5, 0);  
// vector with auto-check each operator[] range.
// if illegal, throw std::out_of_range.

vec_on.set_upper(3);    // user-define upper bound
vec_on.set_lower(2);    // user-define lower bound

vec_on[3] = 1;          
// this will throw exception due to index(3) >= upper
// index need to be >= lower and < upper and < size()

sw::wrapper_s<vector<T>, false> vec_s_on(5, 0);
vec_s_on.set_special(0, 1, 3, 4);
// if index hit these special value, throw exception
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on this code of conduct, and the process for submitting pull requests to us.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
