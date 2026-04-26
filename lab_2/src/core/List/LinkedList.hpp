#pragma once
#include <Exceptions.hpp>
#include <Config.hpp>

template <class T>
class LinkedList {
private:
    struct Node_ {
        T data;
        Node_* next;
        Node_(T val) : data(val), next(nullptr) {}
    };

    Node_* head_;
    Node_* tail_;
    
    void clear() {
        Node_* current = head_;
        while (current != nullptr) {
            Node_* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_ = nullptr;
    }

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    explicit LinkedList(T* items, int count);
    explicit LinkedList(const LinkedList<T>& other);
    ~LinkedList() {clear();}

    
    T GetFirst() const;
    T GetLast() const;
    T Get(int index) const;
    int GetLength() const;
    LinkedList<T>* GetSubList(int startIndex, int endIndex) const;

    
    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    LinkedList<T>* Concat(LinkedList<T>* list);
};

#include "LinkedListConstructors.tpp"
#include "LinkedListGetMethodes.tpp"
#include "LinkedListInsertMethodes.tpp"