#pragma once
#include "Sequence.hpp"
#include "LinkedList.hpp"

template <class T>
class ListSequence : public Sequence<T> {
private:
    void AppendInternal(T item);
    void PrependInternal(T item);
    void InsertAtInternal(T item, int index);
    void ConcatInternal(Sequence<T>* smth);

protected:
    LinkedList<T>* data_;
    
    virtual ListSequence<T>* Clone() const = 0;
    virtual Sequence<T>* Instance() = 0;
public:
    //конструкторы
    ListSequence() : data_(new LinkedList<T>()) {}
    explicit ListSequence(T* items, int count) 
        : data_(new LinkedList<T>(items, count)) {}
    explicit ListSequence(const LinkedList<T>& list) 
        : data_(new LinkedList<T>(list)) {}
    ListSequence(const ListSequence<T>& other) 
        : data_(new LinkedList<T>(*(other.data_))) {}
    virtual ~ListSequence() {
        delete data_;
    }

    //Get-теры
    T GetFirst() const override;
    T GetLast() const override;
    T Get(int index) const override;
    int GetLength() const override;
    Sequence<T>* GetSubsequence(int startIndex, int endIndex) const override;

    //set-теры
    Sequence<T>* Append(T item) override;
    Sequence<T>* Prepend(T item) override;
    Sequence<T>* InsertAt(T item, int index) override;
    Sequence<T>* Concat(Sequence<T>* smth) override;


    //перегруз операторов
    ListSequence<T>& operator=(const ListSequence<T>& other) {
        if (this != &other) {
            delete data_;
            data_ = new LinkedList<T>(*(other.data_));
        }
        return *this;
    }
};


#include "ListSequenceGetMethods.tpp"
#include "ListSequenceInsertMethods.tpp"