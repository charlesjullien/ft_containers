#ifndef EQUAL_HPP
#define EQUAL_HPP

#include <iostream>
#include <cstring>

namespace ft
{

	/***************************Equal*********************************/

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    //
    template <class InputIterator1, class InputIterator2, class Predicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, Predicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

}

#endif