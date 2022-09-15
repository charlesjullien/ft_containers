#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "less.hpp"
# include "make_pair.hpp"
# include "iterators.hpp"

//https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
//https://www.programiz.com/dsa/red-black-tree

namespace ft
{

	/********************************Node*********************************/

	template <class T>
	struct Node
	{
		T _data;
		Node *_parent;
		Node *_left;
		Node *_right;
		int _color;	//0 : black. 1 : red.

		Node(T data, Node *parent, Node *left, Node *right, int color) : _data(data), _parent(parent), _left(left), _right(right), _color(color)
		{
		}
	};

	template <class T>
	Node<T> *minimum(Node<T> *node)
	{
		while (node && node->_left != NULL)
			node = node->_left;
		return (node);
	}

	template <class T>
	Node<T> *maximum(Node<T> *node)
	{
		while (node && node->_right != NULL)
			node = node->_right;
		return (node);
	}

	/*****************************RBT_iterator*****************************/
	//classic
	template <class T>
	class rbt_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef rbt_iterator iterator_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::reference node_reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::pointer node_ptr;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::reference reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::difference_type difference_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::iterator_category iterator_category;

			/*************************Iterator protos**************************/

			rbt_iterator(void) : _ptr(NULL)
			{
			}
		
			rbt_iterator(node_ptr const &ptr) : _ptr(ptr)
			{
			}

			rbt_iterator(rbt_iterator const &src) : _ptr(src._ptr)
			{
			}

			~rbt_iterator(void)
			{
			}

			node_ptr base(void) const
			{
				return (_ptr);
			}

			/*************************Operators for ref, pointer and it_type**************************/

			reference operator*() const
			{
				return (_ptr->_data);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			iterator_type &operator++()
			{
				if (_ptr->_right == _ptr->_left && _ptr->_parent->_parent == _ptr)
				{
					if (!_ptr->_right)
						_ptr = _ptr->_parent;
					else
						_ptr = maximum(_ptr->_right);
				}
				else if (_ptr->_right)
				{
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (y && _ptr == y->_right)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator++(int)
			{
				iterator_type temp = *this;
				operator++();
				return (temp);
			}

			iterator_type &operator--()
			{
				if (_ptr->_left)
				{
					_ptr = _ptr->_left;
					while (_ptr->_right)
						_ptr = _ptr->_right;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (_ptr == y->_left)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_left != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator--(int)
			{
				iterator_type temp = *this;
				operator--();
				return (temp);
			}

		private :
			node_ptr _ptr;
	};

	template <class T1, class T2>
	bool operator==(const rbt_iterator<T1> &rbt1, const rbt_iterator<T2> &rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const rbt_iterator<T1> &rbt1, const rbt_iterator<T2> &rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}
	//const
	template <class T>
	class const_rbt_iterator : public iterator<ft::bidirectional_iterator_tag, T>
	{
		public :
			typedef const_rbt_iterator iterator_type;
			typedef T value_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::reference node_reference;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::pointer node_ptr;
			typedef const T &reference;
			typedef const T *pointer;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::difference_type difference_type;
			typedef typename iterator<ft::bidirectional_iterator_tag, Node<T> >::iterator_category iterator_category;

			const_rbt_iterator(void) : _ptr(NULL)
			{
			}
		
			const_rbt_iterator(node_ptr const &ptr) : _ptr(ptr)
			{
			}

			const_rbt_iterator(rbt_iterator<T> const &src) : _ptr(src.base())
			{
			}

			const_rbt_iterator(const_rbt_iterator const &src) : _ptr(src._ptr)
			{
			}

			~const_rbt_iterator(void)
			{
			}

			node_ptr base(void) const
			{
				return (_ptr);
			}

			reference operator*() const
			{
				return (_ptr->_data);
			}

			pointer operator->() const
			{
				return (&(operator*()));
			}

			iterator_type &operator++()
			{
				if (_ptr->_right == _ptr->_left && _ptr->_parent->_parent == _ptr)
				{
					if (!_ptr->_right)
						_ptr = _ptr->_parent;
					else
						_ptr = maximum(_ptr->_right);
				}
				else if (_ptr->_right)
				{
					_ptr = _ptr->_right;
					while (_ptr->_left)
						_ptr = _ptr->_left;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (y && _ptr == y->_right)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_right != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator++(int)
			{
				iterator_type temp = *this;
				operator++();
				return (temp);
			}

			iterator_type &operator--()
			{
				if (_ptr->_left)
				{
					_ptr = _ptr->_left;
					while (_ptr->_right)
						_ptr = _ptr->_right;
				}
				else
				{
					node_ptr y = _ptr->_parent;
					while (_ptr == y->_left)
					{
						_ptr = y;
						y = y->_parent;
					}
					if (_ptr->_left != y)
						_ptr = y;
				}
				return (*this);
			}

			iterator_type operator--(int)
			{
				iterator_type temp = *this;
				operator--();
				return (temp);
			}

			bool operator==(const const_rbt_iterator rbt2) const
			{
				return (base() == rbt2.base());
			}

			bool operator!=(const const_rbt_iterator rbt2) const
			{
				return (base() != rbt2.base());
			}

		private :
			node_ptr _ptr;
	};

	template <class T1, class T2>
	bool operator==(const rbt_iterator<T1> &rbt1, const const_rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator==(const const_rbt_iterator<T1> &rbt1, const rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() == rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const rbt_iterator<T1> &rbt1, const const_rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}

	template <class T1, class T2>
	bool operator!=(const const_rbt_iterator<T1> &rbt1, const rbt_iterator<T2> rbt2)
	{
		return (rbt1.base() != rbt2.base());
	}

	/**********************************RBT***********************************/

	template <class T, class Compare = ft::less<T> >
	class red_black_tree
	{
		public :
			typedef T data_type;
			typedef Node<T> node;
			typedef Node<T> *node_ptr;
			typedef rbt_iterator<T> iterator;
			typedef const_rbt_iterator<T> const_iterator;
			typedef Compare key_compare;

			red_black_tree(const key_compare &comp = key_compare()) : _size(0), _root(NULL),  _comp(comp)
			{
				_end = malloc_node();
				_end->_parent = _root;
				_end->_right = _root;
				_end->_left = _root;
			}

			~red_black_tree(void)
			{
				clear();
				free_node(_end);
			}

			red_black_tree &operator=(const red_black_tree &src)
			{
				_allocator = src._allocator;
				_comp = src._comp;
				clear();
				const_iterator it = src.begin();
				for ( ; it != src.end() ; it++)
					insert(*it);
				return (*this);
			}

			/*************************Empty + Size**************************/

			bool empty(void) const
			{
				return (_size == 0);
			}

			size_t size(void) const
			{
				return (_size);
			}

			size_t max_size(void) const
			{
				return (_allocator.max_size());
			}

			/*************************Basic iterators**************************/
		
			iterator begin(void)
			{
				if (!_root)
					return (end());
				return (iterator(minimum(_root)));
			}

			const_iterator begin(void) const
			{
				if (!_root)
					return (end());
				return (const_iterator(minimum(_root)));
			}

			iterator end(void)
			{
				return (iterator(_end));
			}

			const_iterator end(void) const
			{
				return (const_iterator(_end));
			}

			/*************************Allocate node**************************/

			node_ptr malloc_node(data_type data = data_type(), node_ptr parent = NULL, node_ptr left = NULL, node_ptr right = NULL, int color = 0)
			{
				node_ptr new_node = _allocator.allocate(1);
				_allocator.construct(new_node, node(data, parent, left, right, color));
				return (new_node);
			}

			/*************************Rotate**************************/

			void left_rotation(node_ptr nd)
			{
				node_ptr nd2 = nd->_right;
				nd->_right = nd2->_left;
				if (nd2->_left)
					nd2->_left->_parent = nd;
				nd2->_parent = nd->_parent;
				if (nd->_parent == _end)
				{
					_root = nd2;
					_root->_parent = _end;
					_end->_right = _root;
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (nd == nd->_parent->_left)
					nd->_parent->_left = nd2;
				else
					nd->_parent->_right = nd2;
				nd2->_left = nd;
				nd->_parent = nd2;
			}

			void right_rotation(node_ptr nd)
			{
				node_ptr nd2 = nd->_left;
				nd->_left = nd2->_right;
				if (nd2->_right)
					nd2->_right->_parent = nd;
				nd2->_parent = nd->_parent;
				if (nd->_parent == _end)
				{
					_root = nd2;
					_root->_parent = _end;
					_end->_right = _root;
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (nd == nd->_parent->_right)
					nd->_parent->_right = nd2;
				else
					nd->_parent->_left = nd2;
				nd2->_right = nd;
				nd->_parent = nd2;
			}

			/*************************Insert**************************/

			pair<iterator, bool> insert(const data_type &key)
			{
				node_ptr node = malloc_node(key, NULL, NULL, NULL, 1);
				node_ptr nd = _root;
				node_ptr nd2 = NULL;

				while (nd)
				{
					nd2 = nd;
					if (_comp(node->_data, nd->_data))
						nd = nd->_left;
					else if (_comp(nd->_data, node->_data))
						nd = nd->_right;
					else
					{
						free_node(node);
						return (pair<iterator, bool>(iterator(nd), false));
					}
				}
				_size++;
				node->_parent = nd2;
				if (!nd2)
				{
					_root = node;
					_root->_parent = _end;
					_end->_right = _root,
					_end->_left = _root;
					_end->_parent = _root;
				}
				else if (_comp(node->_data, nd2->_data))
					nd2->_left = node;
				else
					nd2->_right = node;
				if (node->_parent == _end)
				{
					node->_color = 0;
					return (pair<iterator, bool>(iterator(node), true));
				}

				if (node->_parent->_parent == _end)
					return (pair<iterator, bool>(iterator(node), true));
				fix_insert(node);
				return (pair<iterator, bool>(iterator(node), true));
			}

			void fix_insert(node_ptr nd)
			{
				node_ptr nd2;
				while (nd->_parent->_color == 1)
				{
					if (nd->_parent == nd->_parent->_parent->_right)
					{
						nd2 = nd->_parent->_parent->_left;
						if (nd2 && nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							nd = nd->_parent->_parent;
						}
						else
						{
							if (nd == nd->_parent->_left)
							{
								nd = nd->_parent;
								right_rotation(nd);
							}
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							left_rotation(nd->_parent->_parent);
						}
					}
					else
					{
						nd2 = nd->_parent->_parent->_right;
						if (nd2 && nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							nd = nd->_parent->_parent;
						}
						else
						{
							if (nd == nd->_parent->_right)
							{
								nd = nd->_parent;
								left_rotation(nd);
							}
							nd->_parent->_color = 0;
							nd->_parent->_parent->_color = 1;
							right_rotation(nd->_parent->_parent);
						}
					}
					if (nd == _root)
						break ;
				}
				_root->_color = 0;
				_allocator.destroy(_end);
				_allocator.construct(_end, node(maximum(_root)->_data, _root, _root, _root, 0));
			}

			/*************************Search / Replace**************************/

			node_ptr search_tree_helper(node_ptr node, data_type key) const
			{
				if (node == NULL)
					return (node);
				if (_comp(key, node->_data))
					return (search_tree_helper(node->_left, key));
				else if (_comp(node->_data, key))
					return (search_tree_helper(node->_right, key));
				return (node);
			}

			node_ptr search_tree(data_type key) const
			{
				node_ptr element_found = search_tree_helper(_root, key);
				if (!element_found)
					return (_end);
				return (element_found);
			}

			void replace(node_ptr first, node_ptr second)
			{
				if (first->_parent == _end)
				{
					_root = second;
					if (_root)
					{
						_root->_parent = _end;
						_end->_right = _root;
						_end->_left = _root;
						_end->_parent = _root;
					}
				}
				else if (first == first->_parent->_left)
					first->_parent->_left = second;
				else
					first->_parent->_right = second;
				if (second)
					second->_parent = first->_parent;
			}

			/*************************Clear and free**************************/

			void clear_helper(node_ptr &curr)
			{
				if (!curr)
					return ;
				clear_helper(curr->_left);
				clear_helper(curr->_right);
				free_node(curr);
				_size--;
				curr = NULL;
			}

			void free_node(node_ptr node)
			{
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}

			void clear(void)
			{
				clear_helper(_root);
			}

			/*************************Delete**************************/

			void fix_delete(node_ptr nd)
			{
				node_ptr nd2;

				while (nd != _root && nd->_color == 0)
				{
					if (nd == nd->_parent->_left)
					{
						nd2 = nd->_parent->_right;
						if (nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 1;
							left_rotation(nd->_parent);
							nd2 = nd->_parent->_right;
						}
						if ((nd2->_left->_color == 0 || !nd2->_left) && (nd2->_right->_color == 0 || !nd2->_right))
						{
							nd2->_color = 1;
							nd = nd->_parent;
						}
						else
						{
							if (nd2->_right->_color == 0)
							{
								nd2->_left->_color = 0;
								nd2->_color = 1;
								right_rotation(nd2);
								nd2 = nd->_parent->_right;
							}
							nd2->_color = nd->_parent->_color;
							nd->_parent->_color = 0;
							nd2->_right->_color = 0;
							left_rotation(nd->_parent);
							nd = _root;
						}
					}
					else
					{
						nd2 = nd->_parent->_left;
						if (nd2->_color == 1)
						{
							nd2->_color = 0;
							nd->_parent->_color = 1;
							right_rotation(nd->_parent);
							nd2 = nd->_parent->_left;
						}
						if (!nd2->_right || nd2->_right->_color == 0)
						{
							nd2->_color = 1;
							nd = nd->_parent;
						}
						else
						{
							if (nd2->_left->_color == 0)
							{
								nd2->_right->_color = 0;
								nd2->_color = 1;
								left_rotation(nd2);
								nd2 = nd->_parent->_left;
							}
							nd2->_color = nd->_parent->_color;
							nd->_parent->_color = 0;
							nd2->_left->_color = 0;
							right_rotation(nd->_parent);
							nd = _root;
						}
					}
				}
				if (nd)
					nd->_color = 0;
				_allocator.destroy(_end);
				data_type data = (_root ? maximum(_root)->_data : data_type());
				_allocator.construct(_end, node(data, _root, _root, _root, 0));
			}

			bool delete_node_helper(node_ptr node, data_type key)
			{
				node_ptr nd, nd2;
				node_ptr nd3 = search_tree_helper(node, key);

				if (nd3 == _end || nd3 == NULL)
					return (false);
				_size--;
				nd2 = nd3;
				int nd2_previous_color = nd2->_color;
				if (nd3->_left == NULL)
				{
					nd = nd3->_right;
					replace(nd3, nd3->_right);
				}
				else if (nd3->_right == NULL)
				{
					nd = nd3->_left;
					replace(nd3, nd3->_left);
				}
				else
				{
					nd2 = minimum(nd3->_right);
					nd2_previous_color = nd2->_color;
					nd = nd2->_right;
					if (nd2->_parent == nd3)
					{
						if (nd)
							nd->_parent = nd2;
					}
					else
					{
						replace(nd2, nd2->_right);
						nd2->_right = nd3->_right;
						nd2->_right->_parent = nd2;
					}
					replace(nd3, nd2);
					nd2->_left = nd3->_left;
					nd2->_left->_parent = nd2;
					nd2->_color = nd3->_color;
				}
				free_node(nd3);
				if (nd && nd2_previous_color == 0)
					fix_delete(nd);
				return (true);
			}

			bool delete_node(data_type data)
			{
				return (delete_node_helper(_root, data));
			}
			
			/*************************count**************************/

			node_ptr count(data_type key) const
			{
				node_ptr element = search_tree_helper(_root, key);
				if (!element)
					return (NULL);
				return (element);
			}

			/*************************swap**************************/

			void swap(red_black_tree &y)
			{
				node_ptr tmp_root = _root;
				size_t tmp_size = _size;
				node_ptr tmp_end = _end;

				_root = y._root;
				_size = y._size;
				_end = y._end;

				y._root = tmp_root;
				y._size = tmp_size;
				y._end = tmp_end;
			}

			/*************************Print nodes**************************/
			
			void print_nodes(node_ptr curr, int distance)
			{
				if (!curr)
					return ;
				distance += 5;

				print_nodes(curr->_right, distance);

				std::cout << std::endl;
				for (int i = 5 ; i < distance ; i++)
					std::cout << " ";
				if (curr->_color)
					std::cout << "\033[1;31m";
				std::cout << curr->_data << "\033[0m\n" << std::endl;
				print_nodes(curr->_left, distance);
			}

			void print_rbt(void)
			{
				print_nodes(_root, 0);
			}

			private :
				size_t _size;
				node_ptr _root;
				node_ptr _end;
				std::allocator<Node<T> > _allocator;
				key_compare _comp;

	};
}

#endif
