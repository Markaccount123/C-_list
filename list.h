#pragma once

namespace wzy
{
	template<class T>
	struct __list_node
	{
		T _date;
		__list_node<T>* _next;
		__list_node<T>* _prev;

		//这个节点的构造函数     T()表示一个匿名对象
		__list_node(const T& x = T())
			:_date(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//迭代器里面也只有一个成员变量，就是指向那个结点的指针
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T,Ref,Ptr> self;
		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}
		//拷贝构造 赋值重载  析构函数等都不需要去写，默认生成的就行

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return !(*this != s);
		}

		Ref operator*()
		{
			return _node->_date;
		}

		//前置++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//self operator++(int)


		//self& operator--()

		//self operator--(int)
	};

	template<class T>
	class list
	{
		/*typedef __list_node<T> node;*/
	public:
		typedef __list_node<T> node;
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;//迭代器的本质就是，在不破坏你的封装的情况下，还能够访问和修改你
		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin()const
		{
			return _head->_next;
		}

		const_iterator end()const
		{
			return _head;
		}


		
		//__list_node<T>是他的类型，但是构造函数是与类名相同
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//引用可以很好解决传参过程中的深拷贝问题
		void push_back(const T& x)
		{
			node* newnode = new node(x);
			node* tail = _head->_prev;
			//_head  tail  newnode
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;
		}
	private:
		node* _head;
	};
}