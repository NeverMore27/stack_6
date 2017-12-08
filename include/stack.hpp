#include <iostream>


template <class Ty>
class forward_list {
private:
	struct node
	{
		Ty data;
		node* next;
		node() : next(nullptr) {};
		node(const Ty& t) : data{ t }, next{ nullptr } {};
		node(Ty&& t) : data{ std::move(t) }, next{ nullptr } {};
	};
	node *head;
	size_t count_;
	bool isEqual(const node* head1, const node* head2);
public:
	forward_list() : count_{ 0 }, head{ nullptr } {};
	forward_list(const forward_list& other);
	forward_list(forward_list&& other);
	forward_list& operator=(const forward_list& other);
	bool operator ==(const forward_list& other);
	forward_list& operator=(forward_list&& other);
	~forward_list();
	void clear();
	void push_back(const Ty& val);
	void push_front(const Ty &val);
	template<typename Args>
	void emplace_back(Args&& val);
	template<typename Args>
	void emplace_front(Args &&val);
	bool empty();
	Ty pop_back();
	Ty pop_front();
	size_t count();
	void swap(forward_list& other);
	void show()
	 {
		node *temp = head;
		while (temp != nullptr)
			{
			std::cout << temp->data << " ";
			temp = temp->next;
			}
	};
	forward_list(std::initializer_list<Ty> list);
};
template <class Ty>
forward_list<Ty>::forward_list(const forward_list& other)
{
	head = nullptr; count_ = 0;
	node *pTemp = other.head;
	while (pTemp != nullptr)
	{
		this->push_back(pTemp->data);
		pTemp = pTemp->next;
	}
}

template <class Ty>
forward_list<Ty>::forward_list(forward_list&& other)
{
	head = nullptr; count_ = 0;
	node *pTemp = other.head;
	while (pTemp != nullptr)
	{
		this->emplace_back(pTemp->data);
		pTemp = pTemp->next;
	}
}

template <class Ty>
bool forward_list<Ty>::isEqual(const node* head1, const node* head2)
{
	return (head1 && head2 ? head1->data == head2->data&&isEqual(head2->next, head1->next) : !head2 && !head1);
}

template <class Ty>
bool forward_list<Ty>:: operator ==(const forward_list& other)
{
	return isEqual(head, other.head);
}

template <class Ty>
void forward_list<Ty>::swap(forward_list& other)
{
	std::swap(count_, other.count_);
	std::swap(head, other.head);
}

template <class Ty>
forward_list<Ty>& forward_list<Ty>:: operator=(const forward_list& other)
{
	if (this != &other)
	{
		forward_list{ other }.swap(*this);
	}
	return *this;
}

template <class Ty>
forward_list<Ty>& forward_list<Ty>:: operator=(forward_list&& other)
{
	if (this != &other)
	{
		forward_list{ other }.swap(*this);
	}
	return *this;
}

template <class Ty>
bool forward_list<Ty>::empty()
{
	return (count_ == 0);
}

template <class Ty>
forward_list<Ty>::~forward_list()
{
	clear();
}

template <class Ty>
void forward_list<Ty>::clear()
{
	node *cur_ = head;
	node *deleted_ = head;
	while (deleted_ != nullptr)
	{
		cur_ = cur_->next;
		delete deleted_;
		deleted_ = cur_;
	}
	count_ = 0;
	head = nullptr;
}

template <class Ty>
void forward_list<Ty>::push_front(const Ty &val)
{
	node *tmp = new node;
	tmp->data = val;
	tmp->next = head;
	head = tmp;
	count_++;
}

template <class Ty>
template<typename Args>
void forward_list<Ty>::emplace_front(Args &&val)
{
	node *tmp = new node(std::forward<Args>(val));
	tmp->next = head;
	head = tmp;
	count_++;
}

template <class Ty>
void forward_list<Ty>::push_back(const Ty &val)
{
	node* front = head;
	if (front != nullptr)
	{
		while (front->next != nullptr)
		{
			front = front->next;
		}
		front->next = new node(val);
	}
	else
	{
		front = new node(val);
		head = front;
	}
	count_++;
}

template <class Ty>
template<typename Args>
void forward_list<Ty>::emplace_back(Args &&val)
{
	node* front = head;
	if (front != nullptr)
	{
		while (front->next != nullptr)
		{
			front = front->next;
		}
		front->next = new node(std::forward<Args>(val));
	}
	else
	{
		front = new node(std::forward<Args>(val));
		head = front;
	}
	count_++;
}

template <class Ty>
size_t forward_list<Ty>::count()
{
	return count_;
}

template <class Ty>
Ty forward_list<Ty>::pop_front()
{
	node *tmp;
	tmp = head->next;
	Ty r = head->data;
	delete head;
	head = tmp;
	--count_;
	return r;
}

template <class Ty>
Ty forward_list<Ty>::pop_back()
{
	Ty r;
	node* front = head;
	if (front->next)
	{
		while ((front->next->next != nullptr))
		{
			front = front->next;
		}
		r = front->next->data;
		delete front->next;
		front->next = nullptr;
		--count_;
	}
	else
	{
		r = pop_front();
		count_=0;
	}
	
	return r;
}

template <class Ty>
forward_list<Ty>::forward_list(std::initializer_list<Ty> list)
{
	head = nullptr;
	count_ = 0;
	for (auto& item : list)
	{
		emplace_back(item);
	}
}

///////////////////////////////////////////////////////

template <class Ty>
class queue
{
	forward_list<Ty> _items;
public:
	queue();
	~queue() {};
	void enqueue(const Ty& value);
	Ty dequeue();
	size_t count();
	void show()
	{
		_items.show();
	};
	void swap(queue& other);
	queue& operator=(const queue& other);
	queue& operator=(queue&& other) = default;
	queue (const queue& other) = default;
	queue(queue&& other);
	queue(std::initializer_list<Ty> list);
	
};


template <class Ty>
queue<Ty>::queue(queue&& other)
{
	queue other_ = other;
	while (!other_._items.empty())
	{
		
		Ty _i = other_._items.pop_back();
		_items.emplace_back(_i);
	}
	
}

template <class Ty>
queue<Ty>& queue<Ty>:: operator=(const queue<Ty>& other)
{
	_items = other._items;
	return *this;
}

template <class Ty>
queue<Ty>::queue() {}

template <class Ty>
queue<Ty>::queue(std::initializer_list<Ty> list)
{
	for (auto& item : list)
	{
		enqueue(item);
	}
}


template <class Ty>
void queue<Ty>::enqueue(const Ty& value)
{
	_items.push_front(value);
}

template <class Ty>
Ty queue<Ty>::dequeue()
{
	return _items.pop_back();
}

template <class Ty>
size_t queue<Ty>::count()
{
	return _items.count();
}

template <class Ty>
void queue<Ty>::swap(queue& other)
{
	_items.swap(other._items);
}
