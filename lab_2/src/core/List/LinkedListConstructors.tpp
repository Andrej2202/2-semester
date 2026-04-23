#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList(T* items, int count) : head_(nullptr), tail_(nullptr), length_(0) {
    if (count < 0) throw std::invalid_argument("Negative count in LinkedList constructor");
    for (int i = 0; i < count; ++i) Append(items[i]);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head_(nullptr), tail_(nullptr), length_(0) {
    Node_* current = other.head_;
    while (current != nullptr) {
        Node_* newNode_ = new Node_(current->data);
        if (!head_) head_ = tail_ = newNode_;
        else {
            tail_->next = newNode_;
            tail_ = newNode_;
        }
        length_++;
        current = current->next;
    }
}