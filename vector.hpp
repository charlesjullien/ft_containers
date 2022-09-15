#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "iterators.hpp"

namespace ft
{

	// https://www.cplusplus.com/reference/vector/vector/

	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public :

			/***********************Member types************************/

			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			/*typedef T *iterator;
			typedef const T *const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;*/
			typedef ft::random_access_iterator<value_type> iterator;
			typedef ft::random_access_iterator<const value_type> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			typedef typename allocator_type::difference_type difference_type;
			typedef typename allocator_type::size_type size_type;
			
			/**********************Member functions**********************/

			//Constructor
			//default
			explicit vector(const allocator_type &_alloc = allocator_type())
			: _size(0), _capacity(0), _data(NULL), _alloc(_alloc)
			{}

			//fill
			explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _data(NULL), _alloc(alloc)
			{
				if (n > 0)
				{
					_data = _alloc.allocate(_capacity);
					for (size_type i = 0 ; i < n ; i++)
						_alloc.construct(_data + i, val);
				}
			}
	
			//range
			template <class InputIterator>
			vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _data(NULL),  _alloc(alloc)
			{
				this->assign(first, last);
			}

			//copy
			vector (const vector &x) : _size(0), _capacity(0), _data(NULL)
			{
				*this = x;
			}

			//destructor
			~vector(void)
			{
				clear();
				if (_capacity != 0)
					_alloc.deallocate(_data, _capacity);
			}

			//operator=
			vector &operator=(const vector &x)
			{
				if (this != &x)
				{
					clear();
					if (_capacity < x._size)
					{
						_alloc.deallocate(_data, _capacity);
						_capacity = x._size;
						if (_capacity > 0)
							_data = _alloc.allocate(_capacity);
						else
							return (*this);
					}
					_size = x._size;
					for(size_type i = 0 ; i < x._size ; i++)
						_alloc.construct(_data + i, x._data[i]);
				}
				return (*this);
			}

			/*************************iterators**************************/

			iterator begin(void) { return (_data); }

			const_iterator begin(void) const { return (const_iterator(_data)); }

			iterator end(void) { return (_data + _size); }

			const_iterator end(void) const { return const_iterator(_data + _size); }

			reverse_iterator rbegin(void) { return (reverse_iterator(end())); }

			const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(end())); }

			reverse_iterator rend(void) { return (reverse_iterator(begin())); }

			const_reverse_iterator rend(void) const { return (const_reverse_iterator(begin())); }

			/*************************Capacity**************************/

			//size
			size_type size(void) const { return _size; }

			//max_size
			size_type max_size(void) const
			{
				return (_alloc.max_size());
			}

			//resize
			void resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					while (n < _size)
						pop_back();
				}
				else if (n > _size)
					insert(end(), n - _size, val);
			}

			//capacity
			size_type capacity(void) const { return _capacity; }

			//empty
			bool empty(void) const { return _size == 0; }

			//reserve
			void reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n >= _capacity && n > 0)
				{
					pointer tmp = _alloc.allocate(n);
					if (_capacity > 0)
					{
						for (size_t i = 0 ; i < _size ; i++)
						{
							_alloc.construct(tmp + i, _data[i]);
							_alloc.destroy(&_data[i]);
						}
						_alloc.deallocate(_data, _capacity);
					}
					_data = tmp;
					_capacity = n;
				}
			}

			/***********************Element access***********************/

			//operator[]
			reference operator[](size_type n) { return _data[n]; }

			const_reference operator[](size_type n) const { return _data[n]; }

			//at
			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("Exception out_of_range for function at ");
				return (_data[n]);
			}

			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size)
					throw std::out_of_range("Error for 'at' ");
				return (_data[n]);
			}

			//front
			reference front() { return _data[0]; }

			const_reference front() const { return _data[0]; }

			//back
			reference back(void)
			{
				if (_size == 0)
					return (_data[0]);
				else
					return (_data[_size - 1]);
			}
			
			const_reference back(void) const
			{
				if (_size == 0)
					return (_data[0]);
				else
					return (_data[_size - 1]);
			}


			/*************************Modifiers**************************/
			//assign
			template<class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				clear();
				size_type size = 0;
				for (InputIterator it = first ; it != last ; it++)
					size++;
				_size = size;
				if (_capacity < size)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = size;
					if (size > 0)
						_data = _alloc.allocate(_capacity);
					else
						return ;
				}
				pointer it2 = _data;
				while (first != last)
				{
					_alloc.construct(it2, *first);
					first++;
					it2++;
				}
			}

			void assign(size_type n, const value_type& val)
			{
				if (!n)
					return;
				this->reserve(n);
				this->_size = n;
				for (size_type i = 0; i < this->_size; i++)
				{
					this->_alloc.construct(this->_data + i, val);
				}
			}

			//push_back
			void push_back(const T &val)
			{
				if ((this->_size + 1) > this->_capacity)
				{
					if (this->_capacity == 0)
						reserve(this->_capacity + 1);
					else
						reserve(this->_capacity * 2);
				}
				else
					this->reserve(this->_size + 1);
				this->_alloc.construct(&this->_data[this->_size++], val);
			};

			//pop_back
			void pop_back()
			{
				if (_size == 0)
					throw std::out_of_range("out of range");
				_alloc.destroy(_data + _size - 1);
				--_size;
			};

			//insert
			//single element
			iterator insert(iterator position, const value_type &val)
			{
				difference_type idx = position - _data;
				insert(position, 1, val);
				return (iterator(begin() + idx));
			}

			//fill
			void insert(iterator position, size_type n, const value_type &val)
			{
				difference_type idx = position - _data;
				if (n <= 0)
					return ;
				if (_size + n > _capacity)
				{
					if (_size * 2 > _size + n)
						reserve(_size * 2);
					else
						reserve(_size + n);
				}
				for (pointer it = _data + _size + n - 1, ite = _data + idx + n - 1 ; it != ite ; --it)
				{
					_alloc.construct(it, *(it - n));
					_alloc.destroy(it - n);
				}
				_size += n;
				while (n > 0)
				{
					_alloc.construct(_data + idx - 1 + n, val);
					n--;
				}
			}

			//range
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				if (first == last)
					return ;
				difference_type idx = position - _data;
				size_type size = 0;
				for (InputIterator it = first ; it != last ; it++)
					size++;
				if (_size + size > _size * 2)
					reserve(_size + size);
				else if (_size + size > _capacity)
					reserve(_size * 2);
				for (pointer it2 = _data + _size + size - 1, ite = _data + idx + size - 1 ;it2 != ite ; it2--)
				{
					_alloc.construct(it2, *(it2 - size));
					_alloc.destroy(it2 - size);
				}
				_size += size;
				while (size > 0)
				{
					last--;
					_alloc.construct(_data + idx + size - 1, *last);
					size--;
				}
			}

			//erase
			//single element
			iterator erase(iterator position)
			{
				return (erase(position, position + 1));
			}

			//range
			iterator erase(iterator first, iterator last)
			{
				size_type i = last - first;
				size_type j = first - _data;
				if (i > 0)
				{
					for ( ; j < _size - i ; j++)
					{
						_alloc.destroy(_data + j);
						_alloc.construct (_data + j, _data[j + i]);
					}
					for ( ; j < _size ; j++)
						_alloc.destroy(_data + j);
					_size -= i;
				}
				return (iterator(first));
			}

			//swap
			void swap (vector &v)
			{
				allocator_type tmp_all = v._alloc;
				size_type tmp_size = v._size;
				size_type tmp_cap = v._capacity;
				pointer tmp_arr = v._data;

				v._alloc = _alloc;
				v._size = _size;
				v._capacity = _capacity;
				v._data = _data;

				_alloc = tmp_all;
				_size = tmp_size;
				_capacity = tmp_cap;
				_data = tmp_arr;
			}

			//clear
			void clear(void)
			{
				if (empty())
					return ;
				for (size_type _i = 0; _i < this->size(); _i++)
					this->_alloc.destroy(&this->_data[_i]);
				this->_size = 0;
			}

			/*************************Allocator**************************/
			//get allocator
			allocator_type get_allocator(void) const
			{
				return (_alloc);
			}

			/*************************Variables**************************/

		private :
			size_type _size;
			size_type _capacity;
			pointer _data;
			allocator_type _alloc;	
			
	}; //class vector

	/********************Non member function overloads*******************/
	//relational operators
	//==
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			for (size_t i = 0 ; i < lhs.size() ; i++)
			{
				if (lhs[i] != rhs[i])
					return (false);
			}
			return (true);
		}
		return (false);
	}
	
	//!=
    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs == rhs);
    }

	//<
    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }

	//<=
    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs > rhs);
    }

	//>
    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return rhs < lhs;
    }

	//>=
    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return !(lhs < rhs);
    }

	//swap
	template <class T, class Alloc>
    void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
    {
        x.swap(y);
    }

} // namespace ft

#endif