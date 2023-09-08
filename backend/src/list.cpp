#include "list.hpp"

//* Element access
int &list::front () {
    if (front_ == nullptr) 
        throw std::runtime_error("There is no front value");


    return front_->val_;
}

int &list::back () {
    if (back_ == nullptr) 
        throw std::runtime_error("There is no back value");

    return back_->val_;
}

//* iterators
iterator list::begin () noexcept {
    return iterator(front_);
}

iterator list::end () noexcept{
    return iterator(end_);
}

//* capacity
bool list::empty () const noexcept {
    return (front_ == nullptr);
}

size_t list::size () const noexcept {
    return size_;
}

//* modifiers
void list::push_front (const int val) {
    if (front_ == nullptr) {
        front_ = back_ = new node(val);
        back_->next_ = end_;
        end_->prev_ = back_;
    } else {
        front_->prev_ = new node(val);
        front_->prev_->next_ = front_;
        front_ = front_->prev_;
    }

    size_++;
}

void list::push_back (const int val) {
    if (front_ == nullptr) {
        front_ = back_ = new node(val);
    } else {
        back_->next_ = new node(val);
        back_->next_->prev_ = back_;
        back_ = back_->next_;
    }

    back_->next_ = end_;
    end_->prev_ = back_;

    size_++;
}

void list::pop_front () {
    if (front_ == nullptr) 
        throw std::runtime_error("There is no element is list, can't pop_front()");

    if (front_ == back_) {
        front_ = back_ = nullptr;
        end_->prev_ = nullptr;
    } else {
        front_ = front_->next_;
        front_->prev_ = nullptr;
    }

    size_--;
}

void list::pop_back () {
    if (back_ == nullptr) 
        throw std::runtime_error("There is no element in list, can't pop_back()");

    if (front_ == back_) {
        front_ = back_ = nullptr;
        end_->prev_ = nullptr;
    } else {
        back_ = back_->prev_;
        back_->next_ = nullptr;
        back_->next_ = end_;
        end_->prev_ = back_;
    }

    size_--;
}

#include <emscripten/bind.h>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(b_list) {
    class_<list>("list")
        .constructor<>()
        .function("front", &list::front)
        .function("back", &list::back)
        .function("begin", &list::begin)
        .function("end", &list::end)
        .function("empty", &list::empty)
        .function("size", &list::size)
        .function("push_front", &list::push_front)
        .function("push_back", &list::push_back)
        .function("pop_front", &list::pop_front)
        .function("pop_back", &list::pop_back);
}