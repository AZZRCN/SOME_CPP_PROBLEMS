#include <stdlib.h>
#include "io.cpp"
#include "dbg.cpp"
#include "Book.cpp"
#include "defines.cpp"
out o;

template<typename T>
class node {
public:
    T data;
    node<T> *prev, *next;
    void link(node<T> *p, node<T> *n) { prev = p; next = n; }
    node(void) { prev = nullptr; next = nullptr; }
    node(const T& w) : data(w), prev(nullptr), next(nullptr) {}
    node(const T& w, node<T> *p, node<T> *n) : data(w), prev(p), next(n) {}
    T& operator*() {
        return data;
    }
    node<T>* operator->() {
        return this;
    }
};

template<typename T>
class node_iterator {
public:
    node<T>* p;
    node_iterator(node<T>* _p) : p(_p) {}
    node_iterator& operator++() {
        p = p->next;
        return *this;
    }
    node_iterator operator++(int) {
        node_iterator old = *this;
        p = p->next;
        return old;
    }
    node_iterator& operator--() {
        p = p->prev;
        return *this;
    }
    node_iterator operator--(int) {
        node_iterator old = *this;
        p = p->prev;
        return old;
    }
    bool operator==(const node_iterator& other) const {
        return p == other.p;
    }
    bool operator!=(const node_iterator& other) const {
        return !(*this == other);
    }
    T& operator*() {
        return p->data;
    }
    node<T>* operator->() {
        return p;
    }
};

template<typename T>
class list {
    size_t count = 0;
public:
    node<T> *head, *tail;

    list() {
        head = new node<T>(); tail = new node<T>();
        head->next = tail; tail->prev = head;
    }

    void insert_prev(node<T>* p, const T& v) {
        node<T>* n = new node<T>(v, p->prev, p);
        n->prev->next = n;
        n->next->prev = n;
        count++;
    }

    void insert_next(node<T>* p, const T& v) {
        node<T>* n = new node<T>(v, p, p->next);
        n->prev->next = n;
        n->next->prev = n;
        count++;
    }

    void del(node<T>* p) {
        if (count == 0) {
            return;
        }

        p->next->prev = p->prev;
        p->prev->next = p->next;
        p->prev = nullptr;
        p->next = nullptr;
        delete p;
        count--;
    }

    void psb(const T& v) { insert_prev(tail, v); }
    void psf(const T& v) { insert_next(head, v); }
    void pb() { del(tail->prev); }
    void pf() { del(head->next); }

    node_iterator<T> begin() { return node_iterator<T>(head->next); }
    node_iterator<T> end() { return node_iterator<T>(tail); }

    bool empty() { return count == 0; }
    size_t size() { return count; }

    void print() {
        for (node_iterator<T> p = begin(); p != end(); ++p) {
            o << *p << ' ';
        }
        o << '\n';
    }

    node<T>* at(const size_t& pos) {
        node<T>* p;
        err(pos >= count);
        if (pos < count / 2) {
            p = head->next;
            size_t time = pos;
            while (time-- > 0) {
                p = p->next;
            }
        } else {
            p = tail->prev;
            size_t time = count - pos - 1;
            while (time-- > 0) {
                p = p->prev;
            }
        }
        return p;
    }
};

int main() {
    list<int> l;
    l.psb(10);
    l.psb(20);
    l.pb();
    l.print();

    // 使用迭代器
    for (auto it = l.begin(); it != l.end(); ++it) {
        o << *it << ' ';
    }
    o << '\n';
}