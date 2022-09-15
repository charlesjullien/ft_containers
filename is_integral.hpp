#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <iostream>
//#include <type_traits>

namespace ft
{

	template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

	/*******************************Types********************************/

    //bool
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    //char
    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    //signed char
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    //short int
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    //int
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    //long int
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    //long long int
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    //unsigned char
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    //unsigned short int
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    //unsigned int
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    //unsigned long int
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    //unsigned long long int
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    
    template <typename T>
        struct is_integral : public is_integral_type<T> { };

}

#endif