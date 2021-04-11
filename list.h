#pragma once

namespace wzy
{
	template<class T>
	struct __list_node
	{
		T _date;
		__list_node<T>* _next;
		__list_node<T>* _prev;

		//����ڵ�Ĺ��캯��     T()��ʾһ����������
		__list_node(const T& x = T())
			:_date(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	//����������Ҳֻ��һ����Ա����������ָ���Ǹ�����ָ��
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T,Ref,Ptr> self;
		node* _node;

		__list_iterator(node* node)
			:_node(node)
		{}
		//�������� ��ֵ����  ���������ȶ�����Ҫȥд��Ĭ�����ɵľ���

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

		//ǰ��++
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
		typedef __list_iterator<T, const T&, const T*> const_iterator;//�������ı��ʾ��ǣ��ڲ��ƻ���ķ�װ������£����ܹ����ʺ��޸���
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


		
		//__list_node<T>���������ͣ����ǹ��캯������������ͬ
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		//���ÿ��Ժܺý�����ι����е��������
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