#ifndef LESS_HPP
# define LESS_HPP

# include <iostream>

//when using key/value compare... going to reach this bool

namespace ft
{
	template <class arg_1, class arg_2, class Result>
	struct binary_function
	{
		typedef arg_1 first_arg_type;
		typedef arg_2 second_arg_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const
		{
			return (x < y);
		}
	};
}

#endif
