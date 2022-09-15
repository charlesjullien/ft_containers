#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{
	struct input_iterator_tag
	{
	};

	struct output_iterator_tag
	{
	};

	struct forward_iterator_tag : public input_iterator_tag
	{
	};

	struct bidirectional_iterator_tag : public forward_iterator_tag
	{
	};

	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	};

	template <class Iterator>
		struct iterator_traits
		{
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::iterator_category iterator_category;
		};

	template <class T>
		struct iterator_traits<T *>
		{
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef ft::random_access_iterator_tag iterator_category;
		};

	template <class T>
		struct iterator_traits<const T *>
		{
			typedef std::ptrdiff_t difference_type;
			typedef T value_type;
			typedef const T* pointer;
			typedef const T& reference;
			typedef ft::random_access_iterator_tag iterator_category;
		};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct iterator
		{
			typedef T value_type;
			typedef Distance difference_type;
			typedef Pointer pointer;
			typedef Reference reference;
			typedef Category iterator_category;
		};

	template <class Iterator, class Distance>
		void advance(Iterator &it, Distance n)
		{
			it += n;
		}

	template <class Iterator>
		typename iterator_traits<Iterator>::difference_type distance(Iterator first, Iterator last)
		{
			size_t size;
			for (size = 0 ; first != last ; first ++, size++)
				;
			return (size);
		}

	template <class T>
		class random_access_iterator : public iterator<ft::random_access_iterator_tag, T>
	{
		public : 
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;

			random_access_iterator(void)
			{
			}

			random_access_iterator(pointer const ptr) : _ptr(ptr)
			{
			}

			random_access_iterator(random_access_iterator const &src) : _ptr(src._ptr)
			{
			}

			~random_access_iterator(void)
			{
			}

			pointer base() const
			{
				return (_ptr);
			}

			/*************************Operators**************************/

			reference operator*() const
			{
				return (*_ptr);
			}

			pointer operator->(void) const
			{
				return (&(operator*()));
			}

			reference operator[](difference_type index) const
			{
				return (_ptr[index]);
			}

			random_access_iterator & operator=(const random_access_iterator &rhs)
			{
				_ptr = rhs._ptr;
				return (*this);
			}

			random_access_iterator &operator++()
			{
				_ptr++;
				return (*this);
			}

			random_access_iterator operator++(int)
			{
				random_access_iterator tmp = *this;
				operator++();
				return (tmp);
			}

			random_access_iterator &operator--()
			{
				_ptr--;
				return (*this);
			}

			random_access_iterator operator--(int)
			{
				random_access_iterator tmp = *this;
				operator--();
				return (tmp);
			}

			random_access_iterator &operator-=(const difference_type n)
			{
				_ptr -= n;
				return (*this);
			}

			random_access_iterator &operator+=(const difference_type n)
			{
				_ptr += n;
				return (*this);
			}

			random_access_iterator operator-(const difference_type n)
			{
				return (random_access_iterator(_ptr - n));
			}

			random_access_iterator operator+(const difference_type n)
			{
				return (random_access_iterator(_ptr + n));
			}

			difference_type operator-(const random_access_iterator & rhs)
			{
				return (_ptr - rhs._ptr);
			}

			difference_type operator+(const random_access_iterator & rhs)
			{
				return (_ptr + rhs._ptr);
			}


			bool operator>(random_access_iterator const & rhs) const
			{
				return (_ptr > rhs._ptr);
			}

			bool operator>=(random_access_iterator const & rhs) const
			{
				return (_ptr >= rhs._ptr);
			}

			bool operator<(random_access_iterator const & rhs) const
			{
				return (_ptr < rhs._ptr);
			}

			bool operator<=(random_access_iterator const & rhs) const
			{
				return (_ptr <= rhs._ptr);
			}

			operator random_access_iterator<const value_type>() const
			{
				return (random_access_iterator<const value_type>(_ptr));
			}

		protected : 
			pointer _ptr;
	};

	template <class T>
		random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n, random_access_iterator<T> &it)
		{
			return (it + n);
		}

	template <class Iterator1, class Iterator2>
		typename random_access_iterator<Iterator1>::difference_type operator-(random_access_iterator<Iterator1> ite1, random_access_iterator<Iterator2> ite2)
		{
			return (ite1.base() - ite2.base());
		}

	template <class T, class U>
		bool operator!=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

	template <class T, class U>
		bool operator==(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template <class T, class U>
		bool operator>(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

	template <class T, class U>
		bool operator>=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}

	template <class T, class U>
		bool operator<(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

	template <class T, class U>
		bool operator<=(const random_access_iterator<T> &lhs, const random_access_iterator<U> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

	//reverse iterators
	template <class Iterator>
		class reverse_iterator
		{
			public :
				typedef Iterator iterator_type;
				typedef typename Iterator::value_type value_type;
				typedef typename Iterator::pointer pointer;
				typedef typename Iterator::reference reference;
				typedef typename Iterator::difference_type difference_type;
				typedef typename Iterator::iterator_category iterator_category;

				reverse_iterator(void)
				{
				}

				explicit reverse_iterator(iterator_type it) : _i_type(it)
				{
				}

				template <class Iter>
				reverse_iterator(const reverse_iterator<Iter> &rev_it) : _i_type(rev_it.base())
				{
				}

				~reverse_iterator(void)
				{
				}

				iterator_type base(void) const
				{
					return (_i_type);
				}

				/*************************Operators for reverse**************************/

				reference operator*() const
				{
					iterator_type tmp = _i_type;
					tmp--;
					return (*tmp);
				}

				reverse_iterator operator+(difference_type n) const
				{
					reverse_iterator tmp = *this;
					tmp._i_type -= n;
					return (tmp);
				}

				reverse_iterator &operator++()
				{
					--_i_type;
					return (*this);
				}

				reverse_iterator operator++(int)
				{
					reverse_iterator tmp = *this;
					--_i_type;
					return (tmp);
				}

				reverse_iterator &operator+=(difference_type n)
				{
					_i_type -= n;
					return (*this);
				}

				reverse_iterator operator-(difference_type n) const
				{
					reverse_iterator tmp = *this;
					tmp._i_type += n;
					return (tmp);
				}

				reverse_iterator &operator--()
				{
					++_i_type;
					return (*this);
				}

				reverse_iterator operator--(int)
				{
					reverse_iterator tmp = *this;
					++_i_type;
					return (tmp);
				}

				reverse_iterator &operator-=(difference_type n)
				{
					_i_type += n;
					return (*this);
				}


				pointer operator->() const
				{
					return (&(operator*()));
				}

				typename reverse_iterator::reference operator[](difference_type n) const
				{
					return (base()[-n - 1]);
				}

				//template <class Ite>
				//	friend reverse_iterator<Ite> operator-(typename reverse_iterator<Ite>::difference_type n, const reverse_iterator<Ite> &rev_it);

			private :
				iterator_type _i_type;
		};


	template <class T, class U>
	bool operator==(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template <class T, class U>
	bool operator!=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() != rhs.base());
		}

	template <class T, class U>
	bool operator<(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() > rhs.base());
		}

	template <class T, class U>
	bool operator<=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() >= rhs.base());
		}

	template <class T, class U>
	bool operator>(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() < rhs.base());
		}

	template <class T, class U>
	bool operator>=(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (lhs.base() <= rhs.base());
		}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it)
		{
			return (rev_it + n);
		}

	template <typename T, typename U>
	typename reverse_iterator<T>::difference_type operator-(const reverse_iterator<T> &lhs, const reverse_iterator<U> &rhs)
		{
			return (rhs.base() - lhs.base());
		}
}

#endif
