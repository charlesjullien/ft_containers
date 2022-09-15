#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP


#include <iostream>
#include <limits>
#include "iterators.hpp"
#include "enable_if.hpp"

namespace ft
{

	/****************************Pair******************************/

	template <class T1, class T2> struct pair {

		public:

			typedef T1 first_type;
			typedef T2 second_type;

			T1 first;
			T2 second;
			
			pair() : first(first_type()) , second(second_type())
			{}

			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first) , second(pr.second)
			{}

			pair (const first_type& a, const second_type& b) : first(a), second(b)
			{}

			pair &operator=(const pair &pr)
			{
				new (this) pair<first_type, second_type>(pr);
				return (*this);
			}

	};

	/*************************Make Pair****************************/

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return ( pair<T1, T2>(x, y) );
    }

	/*********************Non member functions*********************/

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first == p2.first && p1.second == p2.second);
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first != p2.first || p1.second != p2.second);
    }
	
    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first < p2.first || p1.second < p2.second);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first > p2.first || p1.second > p2.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first <= p2.first || p1.second <= p2.second);
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
    {
        return (p1.first >= p2.first || p1.second >= p2.second);
    }

    template <class T1, class T2>
    void swap(pair<T1, T2> &p1, pair<T1, T2> &p2)
    {
        pair<T1, T2> temp = p1;
        p1 = p2;
        p2 = temp;
    }

    template <std::size_t I, class T1, class T2>
    typename ft::enable_if<I == 0, T1>::type &get(pair<T1, T2> &p)
    {
        return p.first;
    }

}

#endif