#ifndef STACK_HPP
# define STACK_HPP

//https://www.cplusplus.com/reference/stack/stack/

#include "vector.hpp"

class vector;
namespace ft
{
	template < class T, class Container = ft::vector<T> >
	class stack
	{
		public :

		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		//constructor with parameter
		explicit stack(const container_type &ctnr = container_type())//tester en le mettant dedans la ft
		{
			c = ctnr;
		}

		//assignation constructor
		stack& operator=(const stack& rhs)
		{
			c = rhs.c;
			return *this;
		}

		//destructor
		virtual ~stack()
		{
			
		}

		//checks whether the underlying container is empty
		bool empty(void) const
		{
			return (this->c.empty());
		}

		//returns the number of elements
		size_t size(void) const
		{
			return (this->c.size());
		}

		//accesses the top element
		value_type &top(void)
		{
			return (this->c.back());
		}

		//accesses the top element (but const)
		const value_type &top(void) const
		{
			return (this->c.back());
		}

		//inserts element at the top
		void push(value_type const &val)
		{
			this->c.push_back(val);
		}

		//removes the top element
		void pop(void)
		{
			this->c.pop_back();
		}


		//https://fr.cppreference.com/w/cpp/container/stack/operator_cmp
		template <typename T1, typename T2>
		friend bool operator==(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);

		template <typename T1, typename T2>
		friend bool operator!=(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);

		template <typename T1, typename T2>
		friend bool operator<(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);

		template <typename T1, typename T2>
		friend bool operator<=(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);

		template <typename T1, typename T2>
		friend bool operator>(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);

		template <typename T1, typename T2>
		friend bool operator>=(stack< T1, T2> const &lhs, stack< T1, T2> const &rhs);


		protected :

		Container c;


	};


	template <typename T1, typename T2>
	bool operator==(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <typename T1, typename T2>
	bool operator!=(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <typename T1, typename T2>
	bool operator<(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <typename T1, typename T2>
	bool operator<=(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c <= rhs.c);
	}

	template <typename T1, typename T2>
	bool operator>(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c > rhs.c);
	}

	template <typename T1, typename T2>
	bool operator>=(stack <T1, T2> const &lhs, stack <T1, T2> const &rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif