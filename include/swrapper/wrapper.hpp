/*
 * (c) 2020-present Zhen-Qi Lu
 * Released under the MIT License.
 */

#pragma once
#include <type_traits>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <limits>

namespace sw { 

template<typename T, bool NeedCheck = false>
class wrapper : public T
{
  public:
    using typename T::size_type;
    using typename T::reference;
    using typename T::const_reference;


    template<typename... Args>
    wrapper(Args... args) : 
        T(args...)
      , lower(std::numeric_limits<size_type>::min())
      , upper(std::numeric_limits<size_type>::max())
    {}

    template<typename T2>
    wrapper(std::initializer_list<T2> list) :
        T(list)
      , lower(std::numeric_limits<size_type>::min())
      , upper(std::numeric_limits<size_type>::max())
    {}

    void set_upper(size_type n) { upper = n; }
    void set_lower(size_type n) { lower = n; }
    auto get_upper() { return upper; }
    auto get_lower() { return lower; }

    constexpr reference       operator[](size_type n);
    constexpr const_reference operator[](size_type n) const;

    std::string oors = "Position in container out of range : ";

  private:
    size_type lower, upper;

    void check(size_type);
};

template<typename T, bool NeedCheck = false>
class wrapper_s : public wrapper<T, NeedCheck>
{
  public:
    using Base = wrapper<T, NeedCheck>;
    using typename Base::size_type;
    using typename Base::reference;
    using typename Base::const_reference;

    template<typename... Args>
    wrapper_s(Args... args): 
        Base(args...) 
    {}

    template<typename T2>
    wrapper_s(std::initializer_list<T2> list) :
        Base(list)
    {}

    template<typename... Args>
    void set_special(Args...);

    template<typename... Args>
    void add_special(Args...);

    auto get_special() { return special;}

    constexpr reference       operator[](size_type n);
    constexpr const_reference operator[](size_type n) const;

  private:
    std::vector<size_type> special;
    void check(size_type);
};

template<typename T, bool NeedCheck>
constexpr typename wrapper<T, NeedCheck>::reference 
    wrapper<T, NeedCheck> ::operator[](size_type n)
{
    if constexpr (NeedCheck)
        check(n);
    return T::operator[](n);
}

template<typename T, bool NeedCheck>
constexpr typename wrapper<T, NeedCheck>::const_reference 
    wrapper<T, NeedCheck> ::operator[](size_type n) const
{
    if constexpr (NeedCheck)
        check(n);
    return T::operator[](n);
}

template<typename T, bool NeedCheck>
constexpr typename wrapper_s<T, NeedCheck>::reference 
    wrapper_s<T, NeedCheck> ::operator[](size_type n)
{
    if constexpr (NeedCheck)
        check(n);
    return Base::operator[](n);
}

template<typename T, bool NeedCheck>
constexpr typename wrapper_s<T, NeedCheck>::const_reference 
    wrapper_s<T, NeedCheck> ::operator[](size_type n) const
{
    if constexpr (NeedCheck)
        check(n);
    return Base::operator[](n);
}

template<typename T, bool NeedCheck>
    template<typename... Args>
void wrapper_s<T, NeedCheck> ::set_special(Args... args)
{
    special.clear();
    add_special(args...);
}

template<typename T, bool NeedCheck>
    template<typename... Args>
void wrapper_s<T, NeedCheck> ::add_special(Args... args)
{
    ((special.push_back(args)), ...);
}

template<typename T, bool NeedCheck>
void wrapper<T, NeedCheck> ::check(size_type pos)
{
    std::string prefix = oors + std::to_string(pos);
    if     ( pos < 0 )
        throw std::out_of_range(prefix + " < " +
                "0");
    else if( pos < lower)
        throw std::out_of_range(prefix + " < " + 
                std::to_string(lower) + "(lower)");
    else if( pos >= T::size())
        throw std::out_of_range(prefix + " >= "+ 
                std::to_string(T::size()) + "(size)");
    else if( pos >= upper)
        throw std::out_of_range(prefix + " >= "+ 
                std::to_string(upper) + "(upper)");
}

template<typename T, bool NeedCheck>
void wrapper_s<T, NeedCheck> ::check(size_type pos)
{
    std::string prefix = Base::oors + std::to_string(pos);
    for(auto p : special) if(pos == p)
        throw std::out_of_range(prefix + " = " +
                std::to_string(p) + "(special)");
}

}
