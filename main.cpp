#include "list.cpp"
#include <iostream>
#include <cassert>

void test_default_constructor()
{
    list<int> l;
    assert(l.empty());
    assert(l.size() == 0);
    list<int>* p = new list<int>;
    assert(p->empty());
    assert(p->size() == 0);
    delete p;
}

void test_constructor()
{
    list<int> l(6, 0);
    assert(! l.empty());
    assert(l.size() == 6);
}

void test_push_back()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_back(2 * i);
    }
    assert(l.size() == 8);
    for (list<int>::size_type i = 0; i < l.size(); ++i) {
        assert(l.access(i) == (list<int>::value_type)(2 * i));
    }

}

void test_push_front()
{
    list<int> l;
    assert(l.empty());
    for (list<int>::size_type i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    assert(l.size() == 8);
    for (list<int>::size_type i = 0; i < l.size(); ++i) {
        assert(l.access(l.size() - 1 - i) == (list<int>::value_type)(2 * i));
    }

}

void test_bubble_sort()
{
    list<unsigned int> l;
    assert(l.empty());
    for (unsigned int i = 0; i < 8; ++i) {
        l.push_front(2 * i);
    }
    l.bubble_sort();
    for (unsigned int i = 0; i < l.size(); ++i) {
	    std::cout << l.access(i) << std::endl;
	    assert(l.access(i) == i*2); 
    }
}

void test_pop_back()
{
    list<int> l(5, 89);
    assert(l.size() == 5);
    while (! l.empty()) {
        l.pop_back();
    }
}

void test_pop_front()
{
    list<int> l(89, 5);
    assert(l.size() == 89);
    while (! l.empty()) {
        l.pop_front();
    }
}

void test_copy_constructor()
{
	list<int> b(56, 0);
    assert(b.size() == 56);
    list<int> a(b);
    assert(a.size() == 56);
    for (list<int>::size_type i = 0; i < a.size(); ++i) {
        assert(a.access(i) == 0);
    }
}

void test_insert()
{
    list<int> a;
    assert(a.size() == 0);
    assert(a.empty());
    /// 0 1 2 3 4 5 6 7 8 9
	a.insert(a.size(), 5);
	a.insert(a.size(), 6);
	a.insert(a.size(), 7);
	a.insert(a.size(), 9);
	a.insert(a.size() - 1, 8);
	a.insert(0, 0);
    a.insert(1, 1);
    a.insert(2, 2);
    a.insert(3, 3);
    a.insert(4, 4);
    assert(a.access(0) == 0);
    assert(a.access(1) == 1);
    assert(a.access(2) == 2);
    assert(a.access(3) == 3);
    assert(a.access(4) == 4);
    assert(a.access(5) == 5);
    assert(a.access(6) == 6);
    assert(a.access(7) == 7);
    assert(a.access(8) == 8);
    assert(a.access(9) == 9);
    assert(a.size() == 10);
}

int main()
{
    test_default_constructor();
    test_constructor();
    test_push_back();
    test_push_front();
    test_pop_back();
    test_pop_front();
    test_insert();
    test_copy_constructor();
    test_bubble_sort();
	return 0;
}
