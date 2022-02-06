
#ifndef LIST_HPP
#define LIST_HPP

#include <ostream>

template <typename T>
class list
{
private:
    class node;

public:
    typedef T value_type;
    typedef unsigned int size_type;

private:
    node* access_helper(const size_type& index) const;

public:
    size_type size() const;
    bool empty() const;
    void push_front(const value_type& value);
    void push_back(const value_type& value);
    void pop_front();
    void pop_back();
    void swap(node* next, node* prev);
    void bubble_sort();
    value_type access(const size_type& index) const;
    void insert(const size_type& p, const value_type& value);
    template <int>
    friend std::ostream& operator<<(std::ostream& out, const list<int>& l);


    void destrot_list();

private:
    node* m_head;

public:
    list<T>();
    list<T>(size_type n, const value_type& default_value);
    list<T>(const list<T>& b);
    const list<T>& operator=(const list<T>& c);
    ~list<T>();
};

#endif
