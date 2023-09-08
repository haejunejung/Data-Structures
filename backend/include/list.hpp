#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <cstddef>
#include <stdexcept>
#include <iostream>

struct node {
    int val_;
    node *prev_;
    node *next_;

    explicit node () : prev_(nullptr), next_(nullptr) {}
    explicit node (int val) : val_(val), prev_(nullptr), next_(nullptr) {}
};

class iterator {
    private:
        node *curr_;
    public:
        explicit iterator() : curr_(nullptr) {}
        explicit iterator(node *curr = nullptr) : curr_(curr) {}

        iterator &operator++() {
            if (curr_)
                curr_ = curr_->next_;
            
            return *this;
        }

        iterator &operator--() {
            if (curr_)
                curr_ = curr_->prev_;
            
            return *this;
        }

        iterator &operator+(const size_t cnt) {
            iterator &it = *this;
            for (size_t i = 0; i < cnt && it.curr_; i++) {
                ++it;
            }

            return it;
        }

        iterator &operator-(const size_t cnt) {
            iterator &it = *this;
            for (size_t i = 0; i < cnt && it.curr_; i++) {
                --it;
            }

            return it;
        }

        node *operator&() {
            return curr_;
        }

        int &operator*() {
            return curr_->val_;
        }

        bool operator!=(const iterator &cmp) const {
            return (curr_ != cmp.curr_);
        }

        bool operator==(const iterator &cmp) const {
            return (curr_ == cmp.curr_);
        }
};

class list {
    private:
        node    *front_;
        node    *back_;
        node    *end_;
        size_t  size_;
    
    public:
        //* Member functions
        explicit list () : front_(nullptr), back_(nullptr), end_(new node()), size_(0) {}

        //* Element access
        int &front          ();

        int &back           ();

        //* iterators
        iterator begin      ()  noexcept;

        iterator end        ()  noexcept;

        //* capacity
        bool empty          ()  const noexcept;

        size_t size         ()  const noexcept;

        //* modifiers
        void push_front     (const int val);

        void push_back      (const int val);

        void pop_front      ();

        void pop_back       ();
};

#endif