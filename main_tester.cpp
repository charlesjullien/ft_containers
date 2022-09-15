#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <stack>
#include <iterator>
//#include <forward_list>

#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"


#ifndef NS
# define NS  ft
#endif

template <typename T>
void print_vector(NS::vector<T> &vect, char const *label)
{
    std::cout << "\nvector Size: " << vect.size();
    std::cout << "\nvector Capacity: " << vect.capacity();
    std::cout << "\nvector MAXSize: " << vect.max_size();
    std::cout << "\nvector [" << label << "] contains:";
    if (!vect.size())
        std::cout << "\tnothing";
    for (typename NS::vector<T>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout << "  [ " << *it << " ]";
    }
    std::cout << std::endl;
}

template <typename T>
void print_stack(NS::stack<T> &mystk, char const *label)
{
    NS::stack<T> stk = mystk;
    std::cout << "\nstack Size: " << stk.size();
    std::cout << "\nstack [" << label << "] contains:";
    if (stk.empty())
        std::cout << "\tnothing";
    for (; stk.size();)
    {
        std::cout << " \n [ " << stk.top() << " ]";
        stk.pop();
    }
    std::cout << std::endl;
}

template <typename T, typename U>
void print_map(NS::map<T, U> &mp, char const *label)
{
	if (!mp.empty())
	{
		std::cout << "\nmap Size: " << mp.size();
		std::cout << "\nmap [" << label << "] contains: ";
		if (!mp.size())
			std::cout << "nothing";
		else
			std::cout << "\n\n";
		for (typename NS::map<T, U>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			std::cout << "[" << it->first << "]"
					  << " = " << it->second << std::endl;
		}
		std::cout << std::endl;
	}
}

int main ()
{
	std::cout << "==========> VECTOR TESTS :" << std::endl;
	NS::vector<int> vectGolbal;
    // front() and back()
    {
        std::cout << "\n==========>Calls to PUSH_BACK, FRONT and BACK :" << std::endl;
        NS::vector<int> beautifulVector;
        int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        NS::vector<int> sexyvector(array, array + 10);

        print_vector(beautifulVector, "beautifulVector");

        print_vector(sexyvector, "sexyvector");

        beautifulVector.push_back(42);
        beautifulVector.push_back(100);
        beautifulVector.push_back(125);

        print_vector(beautifulVector, "beautifulVector");

        beautifulVector.front() -= beautifulVector.back(); //42 - 125 = ?

        std::cout << "beautifulVector.front == " << beautifulVector.front() << std::endl;
    }
    // max_size()
    {
        std::cout << "\n==========>Calls to MAX_SIZE :" << std::endl;
        NS::vector<size_t> beautifulVector;

        beautifulVector.push_back(42);
        beautifulVector.push_back(100);
        beautifulVector.push_back(125);

        std::cout << "beautifulVector.max_size == " << beautifulVector.max_size() << std::endl;
    }

    // capacity()
    {
        std::cout << "\n==========>Calls to CAPACITY, SIZE, and INSERT:" << std::endl;
        NS::vector<size_t> randomVec(10, 232);
        NS::vector<size_t> beautifulVector(10, 100);
        std::cout << "beautifulVector.capacity == " << beautifulVector.capacity() << std::endl;
        std::cout << "beautifulVector.size == " << beautifulVector.size() << std::endl;
		std::cout << std::endl;

        beautifulVector.pop_back();
        beautifulVector.pop_back();
        beautifulVector.pop_back();
        beautifulVector.push_back(160);
        beautifulVector.push_back(161);
        beautifulVector.push_back(162);
        beautifulVector.push_back(163);
        beautifulVector.push_back(164);
        std::cout << "beautifulVector.capacity == " << beautifulVector.capacity() << std::endl;
        std::cout << "beautifulVector.size == " << beautifulVector.size() << std::endl;
		std::cout << std::endl;

        beautifulVector.insert(beautifulVector.begin(), randomVec.begin(), randomVec.end());

        std::cout << "beautifulVector.capacity == " << beautifulVector.capacity() << std::endl;
        std::cout << "beautifulVector.size == " << beautifulVector.size() << std::endl;
		std::cout << std::endl;

        beautifulVector.push_back(165);
        std::cout << "beautifulVector.capacity == " << beautifulVector.capacity() << std::endl;
        std::cout << "beautifulVector.size == " << beautifulVector.size() << std::endl;
		std::cout << std::endl;

        print_vector(randomVec, "randomVec");
        print_vector(beautifulVector, "Beautifulvector");
    }

    // assign()
    {
        std::cout << "\n==========>Calls to ASSIGN:" << std::endl;
        NS::vector<int> vecA;
        NS::vector<int> vecB;

        vecA.assign(10, 42); // 10 ints with value 42

        vecB.assign(vecA.begin(), vecA.end()); // a copy of vecA
        print_vector(vecA, "vecA");
        print_vector(vecB, "vecB");

        NS::vector<int> vecC(3);
        vecA.assign(vecC.begin(), vecC.end());
        print_vector(vecA, "vecA");

        std::cout << "Size of vecA: " << int(vecA.size()) << std::endl;
        std::cout << "Size of vecB: " << int(vecB.size()) << std::endl;
		std::cout << std::endl;
    }

    // insert()
    {
        std::cout << "\n==========>Calls to INSERT (more complex):" << std::endl;
        NS::vector<int> beautifulVector;
        NS::vector<int>::iterator ite;

		beautifulVector.push_back(1);
		beautifulVector.push_back(642);
		beautifulVector.push_back(527);
		beautifulVector.push_back(-80);
        print_vector(beautifulVector, "beautifulVector");
        
        ite = beautifulVector.begin();
        ++ite;

        beautifulVector.insert(ite++, 55);
        print_vector(beautifulVector, "beautifulVector");


        ite = beautifulVector.begin();
        ite += 2;
        beautifulVector.insert(ite, 2, 65);
        print_vector(beautifulVector, "beautifulVector");

        NS::vector<int> random(4, 99);
        print_vector(random, "random");

        ite = beautifulVector.begin();
        beautifulVector.insert(ite, random.begin(), random.end());

        print_vector(beautifulVector, "beautifulVector");
    }

    //insert reverse + range
    {
        NS::vector<int> vecTest;
        NS::vector<int>::iterator ite;
        for (int i = 1; i < 5; ++i)
		    vecTest.push_back(i * 3);
        NS::vector<int> vct(vecTest.begin(), vecTest.end());
        print_vector(vct, "vct");

        ite = vecTest.begin();
        for (int i = 1; ite != vecTest.end(); ++i)
		    *ite++ = i * 5;
	    vct.assign(vecTest.begin(), vecTest.end());
        print_vector(vct, "vct");

        vct.insert(vct.end(), vecTest.rbegin(), vecTest.rend());
        print_vector(vct, "vct");
    }

    // erase()
    {
        std::cout << "\n==========>Calls to ERASE:" << std::endl;

        NS::vector<int> beautifulVector;
        NS::vector<int>::iterator it1, it2;

        beautifulVector.push_back(6);
        beautifulVector.push_back(-1982);
        beautifulVector.push_back(17);
        beautifulVector.push_back(98);
        beautifulVector.push_back(98);
        beautifulVector.push_back(1001);
        beautifulVector.push_back(4343);
        beautifulVector.push_back(3322);

        print_vector(beautifulVector, "beautifulVector");

        it1 = beautifulVector.begin();
        it2 = beautifulVector.begin();
        for (size_t i = 0; i < 4; i++, it2++);
        ++it1;
        --it2;
        it1 = beautifulVector.erase(it1);

        print_vector(beautifulVector, "beautifulVector");
        std::cout << "*it1 = " << *it1 << std::endl;
        std::cout << "*it2 = " << *it2 << std::endl;

        it2 = beautifulVector.erase(it2);

        print_vector(beautifulVector, "beautifulVector");
        std::cout << "*it1 = " << *it1 << std::endl;
        std::cout << "*it2 = " << *it2 << std::endl;

        ++it1;
        --it2;
        std::cout << "*it1 = " << *it1 << std::endl;
        std::cout << "*it2 = " << *it2 << std::endl;

        it2 = beautifulVector.end();
        beautifulVector.erase(it1, it2);

        print_vector(beautifulVector, "beautifulVector");
    }

    // swap()
    {
        std::cout << "\n==========>Calls to SWAP:" << std::endl;
        // ft::vector
        NS::vector<int> vecA(4, 100);  // 4 ints with a value of 100
        NS::vector<int> vecB(6, 200); // 6 ints with a value of 200

        print_vector(vecA, "vecA");
        print_vector(vecB, "vecB");

        vecA.swap(vecB);

        print_vector(vecA, "vecA");
        print_vector(vecB, "vecB");
    }

    // resize()
    {
        std::cout << "\n==========>Calls to RESIZE:" << std::endl;

        NS::vector<int> beautifulVector;

        for (int i = 1; i < 10; i++)
            beautifulVector.push_back(i * 2 - 1);

        print_vector(beautifulVector, "beautifulVector");
        beautifulVector.resize(5);
        print_vector(beautifulVector, "beautifulVector");
        beautifulVector.resize(8, 100);
        print_vector(beautifulVector, "beautifulVector");
        beautifulVector.resize(12);
        print_vector(beautifulVector, "beautifulVector");
    }

    // relational operators()
    {
        std::cout << "\n==========>Calls to RELATIONAL OPERATORS:" << std::endl;
        NS::vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        print_vector(a, "a");
        NS::vector<int> b;
        b = a;

        print_vector(b, "b");

        NS::vector<int> c;
        c.push_back(3);
        c.push_back(2);
        c.push_back(1);
        print_vector(c, "c");

        if (a == b)
            std::cout << "\na and b are equal\n";
        if (b != c)
            std::cout << "b and c are not equal\n";
        if (b < c)
            std::cout << "b is inferior to c\n";
        if (c > b)
            std::cout << "c is superior to b\n";
        if (a <= b)
            std::cout << "a is inferior or equal to b\n";
        if (a >= b)
            std::cout << "a is superior or equal to b\n";
    }

    // non-member swap()
    {
        std::cout << "\n==========>Calls to \"specialized algo\" SWAP:" << std::endl;

        NS::vector<int> mac(4, 100); // 4 ints with a value of 100
        NS::vector<int> linux(6, 200); // 6 ints with a value of 200

        print_vector(mac, "mac");
        print_vector(linux, "linux");
        NS::swap(mac, linux);
        print_vector(mac, "mac");
        print_vector(linux, "linux");
    }

    // reverse iterators
    {
        std::cout << "\n==========>Calls to REVERSE ITERATORS:" << std::endl;
        NS::vector<int> l;
        l.push_back(0);
        l.insert(l.end(), 4, 777);
        l.push_back(1);
        NS::vector<int>::reverse_iterator ite = l.rbegin();
        NS::vector<int>::reverse_iterator it = l.rend();
        for (; it != ite; ite++)//modified
        {
            std::cout << "[" << *ite << "]  ";
        }
		std::cout << std::endl;
		std::cout << std::endl;

    }
    // const_iterator
    {
        std::cout << "\n==========>Calls to CONST ITERATORS:" << std::endl;
        NS::vector<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);
        NS::vector<int>::const_iterator ite = l.begin();
        NS::vector<int>::const_iterator it = l.end();
        for (; it != ite; ite++)
        {
            std::cout << "[" << *ite << "]  ";
        }
		std::cout << std::endl;
		std::cout << std::endl;
    }

    // iterator relational operators
    {
        std::cout << "\n==========>Calls to RELATIONAL OPERATORS (ITERATORS):" << std::endl;
        NS::vector<int> l;
        l.push_back(1);
        l.push_back(2);
        l.push_back(3);
        l.push_back(4);
        l.push_back(5);
        NS::vector<int>::const_iterator ite = l.begin();
        NS::vector<int>::const_iterator it = l.begin() + 2;
        std::cout << "first index =" << *ite << std::endl;
        std::cout << "third index =" << *it << std::endl;
        std::cout << "difference =" << it - ite << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
    }
	std::cout << "==========> VECTOR TESTS ENDS HERE:" << std::endl;

	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

	std::cout << "==========> STACK TESTS :" << std::endl;

	NS::stack<int> stackGolbal;
    // top() and empty()
    {
        std::cout << "\n==========>Calls to EMPTY, PUSH, and TOP" << std::endl;
        NS::stack<int> beautifulStack;

        if (beautifulStack.empty())
            std::cout << "beautifulStack is empty." << std::endl;
        
		std::cout << std::endl;

        beautifulStack.push(3843);

        if (!beautifulStack.empty())
            std::cout << "beautifulStack is NOT empty." << std::endl;

		std::cout << std::endl;

        beautifulStack.push(-293939);

        std::cout << "beautifulStack.top() is now " << beautifulStack.top() << '\n';
		std::cout << std::endl;

        beautifulStack.push(8282);

        std::cout << "beautifulStack.top() is now " << beautifulStack.top() << '\n';
		std::cout << std::endl;


        print_stack(beautifulStack, "beautifulStack");

        
    }

    // size()
    {
        std::cout << "\n==========>Calls to SIZE and POP:" << std::endl;
        NS::stack<size_t> beautifulStack;

        beautifulStack.push(19);//1
        beautifulStack.push(11);//2
        beautifulStack.push(10);//3
        beautifulStack.push(17);//4
        beautifulStack.push(15);//5
        beautifulStack.push(12);//6
        beautifulStack.push(14);//7

        std::cout << "beautifulStack.size == " << beautifulStack.size() << '\n';

        print_stack(beautifulStack, "beautifulStack");

        beautifulStack.pop();//removes 14
        beautifulStack.pop();//removes 12

        print_stack(beautifulStack, "beautifulStack");


        std::cout << "beautifulStack.size == " << beautifulStack.size() << '\n';
    }

    /*{
        std::cout << "\n==========>TEST " << std::endl;
        ft::stack<float>								other_stack;
        ft::vector<std::string>							lst;

        lst.push_back("salut");
        lst.push_back("tu vas bien?");
        lst.push_back("super");
        lst.push_back("et toi?");

        ft::stack<std::string, ft::vector<std::string> >	my_stack(lst);

        std::cout << std::boolalpha << other_stack.empty() << std::endl;
        other_stack.push(8.5); // 8.5;
        other_stack.push(42.4242); // 8.5; 42.4242;
        std::cout << other_stack.size() << '\n'; // 2
        other_stack.pop(); // 8.5;
        std::cout << other_stack.size() << '\n'; // 1
        other_stack.push(78541.987); // 8.5; 78541.987;
        std::cout << other_stack.size() << '\n'; // 2
        std::cout << other_stack.top() << '\n'; //78541.987
        std::cout << std::boolalpha << other_stack.empty() << std::endl;

        const std::string const_top = my_stack.top();

        std::cout << "const top: " << const_top << '\n';

        while (!my_stack.empty())
        {
            std::cout << my_stack.top() << '\n';
            my_stack.pop();
        }
    }*/

    // relational operators()
    {
        std::cout << "\n==========>Calls to RELATIONAL OPERATORS:" << std::endl;

        NS::stack<int> a;
        a.push(200);
        a.push(400);
        a.push(600);
        print_stack(a, "a");
        NS::stack<int> b = a;
        // b = a;

        print_stack(b, "b");

        NS::stack<int> c;
        c.push(600);
        c.push(400);
        c.push(200);
        print_stack(c, "c");

        if (a == b)
            std::cout << "\na and b are equal\n";
        if (b != c)
            std::cout << "b and c are not equal\n";
        if (b < c)
            std::cout << "b is inferior to c\n";
        if (c > b)
            std::cout << "c is superior to b\n";
        if (a <= b)
            std::cout << "a is inferior or equal to b\n";
        if (a >= b)
            std::cout << "a is superior or equal to b\n";
    }

	std::cout << "==========> STACK TESTS ENDS HERE:" << std::endl;

    /* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
	/* ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/


	std::cout << "==========> MAP TESTS :" << std::endl;


	// begin()
	{
        std::cout << "\n==========>Calls to MAKE_PAIR, BEGIN and END :" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(5, 1));
		beautifulMap.insert(NS::make_pair(100, 377));
		beautifulMap.insert(NS::make_pair(2, 2));
		NS::map<int, int>::iterator it = beautifulMap.begin();
		print_map(beautifulMap, "beautifulMap");
		std::cout << "beautifulMap.begin = " << (*it).first << std::endl;
	}
	// assign operator=()
	{
        std::cout << "\n==========>Calls to OPERATOR= :" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(50, 1));
		beautifulMap.insert(NS::make_pair(21, 2));
		beautifulMap.insert(NS::make_pair(10, 32));
		beautifulMap.insert(NS::make_pair(100, 376));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int> otherMapB;
		std::cout << "before assignation :" << std::endl;
		print_map(otherMapB, "otherMapB");
		otherMapB = beautifulMap;
		std::cout << "after assignation :" << std::endl;
		print_map(otherMapB, "otherMapB");
	}

	// clear()
	{
        std::cout << "\n==========>Calls to CLEAR:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(50, 1));
		beautifulMap.insert(NS::make_pair(21, 2));
		beautifulMap.insert(NS::make_pair(10, 32));
		beautifulMap.insert(NS::make_pair(100, 376));
		print_map(beautifulMap, "beautifulMap");
		beautifulMap.clear();
		std::cout << "After clear() call :" << std::endl;
		print_map(beautifulMap, "beautifulMap");
	}

	// count()
	{
        std::cout << "\n==========>Calls to COUNT:" << std::endl;
		NS::map<std::string, std::string> beautifulMap;
		beautifulMap.insert(NS::make_pair("Hello", "bonjour"));
		beautifulMap.insert(NS::make_pair("world", "monde"));
		beautifulMap.insert(NS::make_pair("wassup", "ca va"));
		beautifulMap.insert(NS::make_pair("?", "interrogation"));
		print_map(beautifulMap, "beautifulMap");
		std::cout << "beautifulMap.count(\"world\") = " << beautifulMap.count("world") << std::endl;
		std::cout << "beautifulMap.count(\"random\") = " << beautifulMap.count("random") << std::endl;
	}

	// empty()
	{
        std::cout << "\n==========>Calls to EMPTY:" << std::endl;
		NS::map<std::string, std::string> beautifulMap;
		beautifulMap.insert(NS::make_pair("Hello", "bonjour"));
		beautifulMap.insert(NS::make_pair("world", "monde"));
		beautifulMap.insert(NS::make_pair("wassup", "ca va"));
		beautifulMap.insert(NS::make_pair("?", "interrogation"));
		print_map(beautifulMap, "beautifulMap");
		std::cout << "beautifulMap.empty = " << beautifulMap.empty() << std::endl;
		beautifulMap.clear();
		std::cout << "after call to clear() :" << std::endl;
		print_map(beautifulMap, "beautifulMap");
		std::cout << "beautifulMap.empty = " << beautifulMap.empty() << std::endl;
	}

	// find()
	{
        std::cout << "\n==========>Calls to FIND:" << std::endl;
		NS::map<std::string, std::string> beautifulMap;
		beautifulMap.insert(NS::make_pair("Hello", "bonjour"));
		beautifulMap.insert(NS::make_pair("world", "monde"));
		beautifulMap.insert(NS::make_pair("wassup", "ca va"));
		beautifulMap.insert(NS::make_pair("?", "interrogation"));
		print_map(beautifulMap, "beautifulMap");
		if (beautifulMap.find("Hello") != beautifulMap.end())
			std::cout << "Hello has been found and is linked to " << beautifulMap.find("Hello")->second << std::endl;
		else
			std::cout << "Hello has not been found" << std::endl;
		if (beautifulMap.find("Random") != beautifulMap.end())
			std::cout << "Random has been found and is linked to " << beautifulMap.find("Random")->second << std::endl;
		else
			std::cout << "Random has not been found" << std::endl;
	}

	// insert()
	{
        std::cout << "\n==========>Calls to INSERT:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 10));
		beautifulMap.insert(NS::make_pair(20, 2000));
		beautifulMap.insert(NS::make_pair(1000, 7647));

		print_map(beautifulMap, "beautifulMap");

		NS::map<int, int>::iterator it = beautifulMap.insert(NS::make_pair(777, 888)).first;

		print_map(beautifulMap, "beautifulMap");

		std::cout << "inserted value 888 at key " << (*it).first << std::endl;
		NS::pair<int, int> arr[] = {NS::make_pair(100, 10), NS::make_pair(200, 20),
									NS::make_pair(300, 30), NS::make_pair(400, 40)};

		NS::map<int, int> otherMapB;

		otherMapB.insert(arr, arr + 4);

		print_map(otherMapB, "otherMapB");
	}

	// map constructors
	{
        std::cout << "\n==========>Calls to MAP CONSTRUCTORS:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(777, 888));
		beautifulMap.insert(NS::make_pair(444, 555));
		beautifulMap[777] = 333;
		beautifulMap[444] = 111;
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int> otherMapB(beautifulMap);
		print_map(otherMapB, "otherMapB");
		NS::map<int, int> otherMapC(otherMapB.begin(), otherMapB.end());
		print_map(otherMapC, "otherMapC");
	}

	// erase()
	{
        std::cout << "\n==========>Calls to ERASE:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(0, 10));
		beautifulMap.insert(NS::make_pair(1, 20));
		beautifulMap.insert(NS::make_pair(2, 30));
		beautifulMap.insert(NS::make_pair(3, 40));
		beautifulMap.insert(NS::make_pair(4, 50));
		beautifulMap.insert(NS::make_pair(5, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		std::cout << "beautifulMap.erase at key 5 (returns the number of element erased which is : ) " << beautifulMap.erase(5) << std::endl;
		NS::map<int, int>::iterator it = beautifulMap.begin();
		//std::advance(it, 2);//advance the iterator it by n elements positions
        it++;
        it++;
		beautifulMap.erase(beautifulMap.begin(), it);
		print_map(beautifulMap, "beautifulMap");
		beautifulMap.erase(beautifulMap.begin());
		print_map(beautifulMap, "beautifulMap");
	}

	// max_size()
	{
        std::cout << "\n==========>Calls to MAX_SIZE:" << std::endl;
		NS::map<int, int> beautifulMap;
		std::cout << "beautifulMap.max_size = " << beautifulMap.max_size() << std::endl;
	}

	// swap()
	{
        std::cout << "\n==========>Calls to SWAP:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(0, 10));
		beautifulMap.insert(NS::make_pair(1, 20));
		beautifulMap.insert(NS::make_pair(2, 30));
		beautifulMap.insert(NS::make_pair(3, 40));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int> otherMapB;
		otherMapB.insert(NS::make_pair(4, 50));
		otherMapB.insert(NS::make_pair(5, 60));
		otherMapB.insert(NS::make_pair(6, 70));
		otherMapB.insert(NS::make_pair(7, 80));
		print_map(otherMapB, "otherMapB");
		beautifulMap.swap(otherMapB);
		print_map(beautifulMap, "beautifulMap");
		print_map(otherMapB, "otherMapB");
	}

	// lower_bound()
	{
        std::cout << "\n==========>Calls to LOWER_BOUND:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 50));
		beautifulMap.insert(NS::make_pair(3, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int>::iterator it = beautifulMap.lower_bound(2);
		std::cout << "beautifulMap.lower_bound with a key : 2 = " << (*it).first << std::endl;
		it = beautifulMap.lower_bound(3);
		std::cout << "beautifulMap.lower_bound with a key : 3 = " << (*it).first << std::endl;
		it = beautifulMap.lower_bound(5);
		std::cout << "beautifulMap.lower_bound with a key : 5 = " << (*it).first << std::endl;
	}

	// upper_bound()
	{
        std::cout << "\n==========>Calls to UPPER_BOUND:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 50));
		beautifulMap.insert(NS::make_pair(3, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int>::iterator it = beautifulMap.upper_bound(1);
		std::cout << "beautifulMap.lower_bound with a key : 1 = " << (*it).first << std::endl;
		it = beautifulMap.upper_bound(4);
		std::cout << "beautifulMap.lower_bound with a key : 4 = " << (*it).first << std::endl;
		it = beautifulMap.upper_bound(6);
		std::cout << "beautifulMap.lower_bound with a key : 6 = " << (*it).first << std::endl;
	}

	// equal_range()
	{
        std::cout << "\n==========>Calls to EQUAL_RANGE:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 50));
		beautifulMap.insert(NS::make_pair(3, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		NS::pair<NS::map<int, int>::iterator, NS::map<int, int>::iterator> range = beautifulMap.equal_range(2);
		std::cout << "beautifulMap.equal_range with a key 2 =  from " << (*range.first).first << " to " << (*range.second).first << std::endl;
		range = beautifulMap.equal_range(3);
		std::cout << "beautifulMap.equal_range with a key 3 =  from " << (*range.first).first << " to " << (*range.second).first << std::endl;
		range = beautifulMap.equal_range(6);
		std::cout << "beautifulMap.equal_range with a key 2 =  from " << (*range.first).first << " to " << (*range.second).first << std::endl;
	}

	// get_allocator()
	{
        std::cout << "\n==========>Calls to GET_ALLOCATOR:" << std::endl;
		NS::map<int, int> beautifulMap;
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int>::allocator_type alloc = beautifulMap.get_allocator();
		NS::pair<const int, int> *ptr = alloc.allocate(1);
		alloc.deallocate(ptr, 1);
		std::cout << "alloc max size: " << alloc.max_size() << std::endl;
	}

	// const iterators
	{
        std::cout << "\n==========>Calls to CONST ITERATORS:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 50));
		beautifulMap.insert(NS::make_pair(3, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int>::const_iterator it = beautifulMap.begin();
		std::cout << "beautifulMap.begin = " << (*it).first << std::endl;
		it = beautifulMap.end();
		--it;
		std::cout << "beautifulMap.end = " << (*it).first << std::endl;
	}

	// reverse iterators
	{
        std::cout << "\n==========>Calls to REVERSE ITERATORS:" << std::endl;
		NS::map<int, int> beautifulMap;
		beautifulMap.insert(NS::make_pair(1, 50));
		beautifulMap.insert(NS::make_pair(3, 60));
		beautifulMap.insert(NS::make_pair(6, 70));
		beautifulMap.insert(NS::make_pair(7, 80));
		print_map(beautifulMap, "beautifulMap");
		NS::map<int, int>::reverse_iterator it = beautifulMap.rbegin();
		for (; it != beautifulMap.rend(); ++it)
		{
			std::cout << "[" << (*it).first << "] = " << (*it).second << std::endl;
		}
	}

	std::cout << "==========> MAP TESTS ENDS HERE:" << std::endl;
	return (0);
}