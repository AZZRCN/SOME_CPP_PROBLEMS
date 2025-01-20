#include <type_traits>
#include <iostream>
#ifndef INT_MAX
#define INT_MAX 0x7fffffff
#define INW_MIN (-INT_MAX-1)
#endif
namespace OI {
    class Node {
    public:
        int w;
        Node* nxt;
        Node* pre;
        Node(int O) { w = O; nxt = pre = nullptr; }
        Node(void) { w = 0; nxt = pre = nullptr; }
        void connect_to_next(Node* node) { this->nxt = node; node->pre = this; }
        void connect_to_prev(Node* node) { this->pre = node; node->nxt = this; }
        void del() { nxt->pre = pre; pre->nxt = nxt; }
        void swap_value(Node* O) { std::swap(w, O->w); }
        void reverse() { std::swap(pre, nxt); }
        void connect_to_both(Node* front, Node* back) {
            front->connect_to_next(this);
            back->connect_to_prev(this);
        }
    };
    class iterator {
    public:
        Node* ptr;
        Node* head;
        Node* tail;
        iterator(Node* _ptr) { ptr = _ptr; head = tail = nullptr; }
        iterator(Node* _head, Node* _tail, Node* _ptr) { head = _head; tail = _tail; ptr = _ptr; }
        bool is_end() { return ptr == tail; }
        bool is_beg() { return ptr == head; }
        iterator& operator++() { if (!is_end()) { ptr = ptr->nxt; }return*this; }
        iterator& operator--() { if (!is_beg()) { ptr = ptr->pre; }return*this; }
        iterator operator++(int) { iterator temp = *this; ++(*this); return temp; }
        iterator operator--(int) { iterator temp = *this; --(*this); return temp; }
        iterator next(int _pos = 1) { if (_pos == 0) { return *this; }iterator ret = *this; for (int i = 1; i <= _pos; i++) { ret++; }return ret; }
        iterator prev(int _pos = 1) { if (_pos == 0) { return *this; }iterator ret = *this; for (int i = 1; i <= _pos; i++) { ret--; }return ret; }
        iterator operator+(int _pos) { return next(_pos); }
        iterator operator-(int _pos) { return prev(_pos); }
        inline constexpr int& w() { return ptr->w; }
        inline constexpr int& operator*() { return ptr->w; };
        bool operator!=(const iterator& O)const {
            return O.ptr != ptr;
        }
    };
    class list {
    public:
        Node* head;
        Node* tail;
        int size;
        list(void) { head = new Node(INT_MAX); tail = new Node(INT_MIN); size = 0; head->connect_to_next(tail); }
        void clear() { head = new Node(INT_MAX); tail = new Node(INT_MIN); size = 0; head->connect_to_next(tail); }
        void s_() { size++; }
        void s__() { size--; }
        inline constexpr bool empty() { return !size; }
        Node* find(int _pos) { Node* pos = head->nxt; for (int i = 1; i <= _pos; i++) { pos = pos->nxt; }return pos; }
        void del(int _pos) { find(_pos)->del(); s__(); }
        void change(int _pos, int w) { find(_pos)->w = w; }
        void push_back(int O) { Node* node = new Node(O); if (empty()) { node->connect_to_both(head, tail); } else { node->connect_to_both(tail->pre, tail); }s_(); }
        void push_front(int O) { Node* node = new Node(O); if (empty()) { node->connect_to_both(head, tail); } else { node->connect_to_both(head, head->nxt); }s_(); }
        void insert_prev(int _pos, int w) { Node* node = new Node(w); if (empty()) { push_front(w); } else { Node* pos = find(_pos); node->connect_to_both(pos->pre, pos); } }
        void insert_next(int _pos, int w) { Node* node = new Node(w); if (empty()) { push_front(w); } else { Node* pos = find(_pos); node->connect_to_both(pos, pos->nxt); } }
        void reverse() { Node* pos = head->nxt; while (pos != tail) { pos->reverse(); pos = pos->pre; }std::swap(tail->pre, head->nxt); std::swap(head->nxt->pre, tail->pre->nxt); }
        void merge_front(list& l) { l.tail->pre->connect_to_next(head->nxt); l.tail = tail; head = l.head; size += l.size; l.size = size; }/*[l,this]*/
        void merge_back(list& l) { l.head->nxt->connect_to_prev(tail->pre); l.head = head; tail = l.tail; size += l.size; l.size = size; }/*[this,l]*/
        void print() { Node* pos = head->nxt; while (pos != tail) { printf("%d ", pos->w); pos = pos->nxt; }printf("\n"); }
        int inline constexpr back() { return tail->pre->w; }
        int inline constexpr front() { return head->nxt->w; }
        // Node* begin(){return head->nxt;}
        // Node* end  (){return tail;}
        iterator begin() { return iterator(head, tail, head->nxt); }
        iterator end() { return iterator(head, tail, tail); }
        iterator it_pos(int _pos) { return iterator(head, tail, find(_pos)); }
        void pop_back() { tail->pre->pre->connect_to_next(tail); s__(); }
        void pop_front() { head->nxt->nxt->connect_to_prev(head); s__(); }
        int& operator[](int _pos) { return find(_pos)->w; }
    };
    void print(int x) {
        if (x == INT_MIN) {
            printf("tail ");
        }
        else if (x == INT_MAX) {
            printf("head ");
        }
        else {
            printf("%d ", x);
        }
    }
    class queue_node {
    public:
        queue_node* nxt; int w;
        queue_node(int O) { w = O; nxt = nullptr; }
        void connect_next(queue_node* O) { O->nxt = nxt; nxt = O; }
        void connect_next() { nxt = nxt->nxt; }
    };
    class queue_iterator {
    public:
        queue_node* ptr;
        bool operator!=(const queue_iterator& o) { return ptr != o.ptr; }
        int& operator* () { return ptr->w; }
        queue_iterator(queue_node* _ptr) { ptr = _ptr; }
        queue_iterator& operator++() { ptr = ptr->nxt; return *this; }
        queue_iterator operator++(int) { queue_iterator temp = *this; ++(*this); return temp; }
    };
    class const_queue {
    public:
        queue_node* head, * tail, * node; int size;
        queue_node* new_(const int& O) { return new queue_node(O); }
        void s_() { size++; }
        void s__() { size--; }
        void s___() { size = 0; }
        const_queue(void) { s___(); head = new_(INT_MAX); tail = new_(INT_MIN); head->nxt = tail; tail->nxt = head; }
        void push(int O) { s_(); node = new_(O); tail->nxt->connect_next(node); tail->nxt = node; }
        queue_iterator  begin() { return queue_iterator(head->nxt); }
        queue_iterator  end() { return queue_iterator(tail); }
        bool            empty() { return !size; }
        int             front() { return head->nxt->w; }
        int             back() { return tail->nxt->w; }
        void            pop() { head->connect_next(); s__(); if (empty()) { tail->nxt = head; } }
        void            print() { for (int i : *this) { OI::print(i); }putchar('\n'); }
    };
    //这里执行三次，排1000以内的
    void LSD(list& l) {
        int div = 1;
        const_queue buckets[10];
        for (int i = 1; i <= 3; i++) {
            //分
            int w;
            while (!l.empty()) { w = l.front(); l.pop_front(); buckets[(w / div) % 10].push(w); }
            //合
            for (int j = 0; j < 10; j++) {
                while (!buckets[j].empty()) {
                    l.push_back(buckets[j].front());
                    buckets[j].pop();
                }
            }
            div *= 10;
        }
    }
};