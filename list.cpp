
#include "list.hpp"

#include <cassert>
#include <iostream>

template <typename T>
class list<T>::node
{
public:
    value_type m_value;
    node* m_next;

    node* m_prev;
public:
    node(value_type v, node* n, node* p)
        : m_value(v)
        , m_next(n)
	, m_prev(p)
    {
    }

    ~node()
    {
    }
};

template <int>
std::ostream& operator<<(std::ostream& out, const list<int>& l)
{
    list<int>::node* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

template <typename T>
typename list<T>::size_type list<T>::size() const
{
    node* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

template <typename T>
void list<T>::swap(node* n, node* p)
{
	n->m_value = n->m_value + p->m_value;
	p->m_value = n->m_value - p->m_value;
	n->m_value = n->m_value - p->m_value;
}

template <typename T>
void list<T>::bubble_sort()
{
	node* current = nullptr;
	node* next = nullptr;
	for(unsigned int i = 0; i < size()-1; i++) {
	current = m_head;
	   for(unsigned int k = 0; k < size()-1; k++) {
		   next = current->m_next;
		   if (current->m_value > next->m_value){
		   	swap(current, next);
		   }
		   current = current->m_next;
		}
	}
}

template <typename T>
bool list<T>::empty() const
{
    return (m_head == nullptr);
}


template <typename T>
void list<T>::push_front(const value_type& value) // O(1)
{
    node* new_node = new node(value, m_head, nullptr);
    m_head = new_node;
}


template <typename T>
void list<T>::push_back(const value_type& value) // O(n)
{
    node* new_node = new node(value, nullptr, m_head);
    if (m_head == nullptr) {
        m_head = new_node;
    } else {
        assert(size() >= 1);
        node* last = access_helper(size() - 1);
        assert(last != nullptr);
        assert(last->m_next == nullptr);
        last->m_next = new_node;
	new_node->m_prev = last;
    }
}


template <typename T>
void list<T>::insert(const size_type& index, const value_type& value)
{
    assert(index >= 0);
    assert(index <= size());
    node* new_node = new node(value, nullptr, nullptr);
    if (index == 0) {
        push_front(value);
    } else if (index == size()) {
        push_back(value);
    } else {
        assert(index >= 1);
        node* current = access_helper(index - 1);
        assert(current != nullptr);
        new_node->m_next = current->m_next;
        current->m_next = new_node;

	new_node->m_prev = current;
	current->m_next->m_prev = new_node;
    }
}

template <typename T>
void list<T>::pop_front()
{

    assert(m_head != nullptr);
    node* n = m_head;
    m_head = m_head->m_next;
    if (m_head != nullptr && m_head->m_next)
    {
	    m_head->m_next->m_prev = nullptr;
    }

    delete n;
}

template <typename T>
void list<T>::pop_back()
{
    assert(m_head != nullptr);
    if (m_head->m_next == nullptr) {
        pop_front();
        assert(m_head == nullptr);
    } else {
        assert(size() >= 2);
        node* last = access_helper(size() - 1);
        assert(last != nullptr);
	last->m_prev->m_next = nullptr;
        delete last;
    }
}


template <typename T>
typename list<T>::node* list<T>::access_helper(const size_type& index) const
{
    assert(index >= 0);
    assert(index < size());
	node* current = m_head;
    for (size_type i = 0; i < index; ++i) {
        assert(current != nullptr);
        current = current->m_next;
	}
    assert(current != nullptr);
	return current;
}


template <typename T>
typename list<T>::value_type list<T>::access(const size_type& index) const
{
    node* n = access_helper(index);
    assert(n != nullptr);
	return n->m_value;
}


template <typename T>
list<T>::list()
    : m_head(nullptr)
{
}


template <typename T>
list<T>::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
{
    node* current = nullptr;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr, nullptr);
        if (current != nullptr) {
            current->m_next = new_node;
	    new_node->m_prev = current;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        current = new_node;
    }
}


template <typename T>
list<T>::list(const list& b)
	: m_head(nullptr)
{
    *this = b;

}


template <typename T>
const list<T>& list<T>::operator=(const list<T>& c)
{
    while(!empty())
 
    {
            pop_front();
    }   

    node* c_current = c.m_head;

    while (c_current != nullptr)
    {

	push_back(c_current->m_value);
	c_current = c_current->m_next;
    }
    return *this;
}


template <typename T>
list<T>::~list()
{
    while(!empty())

    {
	    pop_front();
    }
}
